#include "BST.h" 

template <class T>
size_t BST<T>::size() {
	if (root) {
		root->sizeRoot();
	}
	else return 0;
}
template <class T>
size_t BST<T>::Root::sizeRoot() {
	return size_;
}


template <class T>
BST<T>::Root::Root(T x) : D(x), l(nullptr), r(nullptr),size_(1) {}
template <class T>
BST<T>::BST(const std::initializer_list<T> & ilist) {

	for (T element : ilist) {
		Insert(element);
	}
};

template <class T>
BST<T>::~BST() {
	if (root!=nullptr) {
		root->destroy(root);
	}
}
template <class T>
void BST<T>::Root::destroy(Root* root) {

	if (root->l)
	{
		destroy(root->l);
	}
	if (root->r != 0)
	{
		destroy(root->r);
	}
	delete root;
	root = nullptr;
}

template <class T>
T BST<T>::Root::find_min(Root* tree) {
	if (tree->l) return find_min(tree->l);
	else return tree->D;
}

template <class T>
void BST<T>::Root::del(T x) {
	if ((x == D) && (!l)) {
		D = r->D;
		if (r->l) l = r->l; else { delete[] l; l = nullptr; --size_; }
		if (r->r) r = r->r; else { delete[] r; r = nullptr; --size_; }
		return;
	}
	if ((x == D) && (!r)) {
		D = l->D;
		if (l->r) r = l->r; else { delete[] r; r = nullptr; --size_; }
		if (l->l) l = l->l; else { delete[] l; l = nullptr; --size_; }
		return;
	}
	if (x < D) {
		if ((l->D == x) && (!(l->r)) && (!(l->l))) { delete[] l; l = nullptr; return; --size_; }
		if ((l->D == x) && (l->l) && (l->r)) { l->D = find_min(l->r); if (l->r->D != find_min(l->r)) l->r->del(find_min(l->r)); else { delete[] l->r; l->r = nullptr; --size_; } return; }
		else; l->del(x);

		return;
	}
	if (x > D) {
		if ((r->D == x) && (!(r->r)) && (!(r->l))) { delete[] r; r = nullptr; return; --size_; }
		if ((r->D == x) && (r->l) && (r->r)) { r->D = find_min(r->r); if (r->r->D != find_min(r->r)) r->r->del(find_min(r->r)); else { delete[] r->r; r->r = nullptr; --size_; } return; }
		else r->del(x);
		return;
	}
	if ((x == D) && (l) && (r)) { D = find_min(r); if (r->D != find_min(r)) r->del(find_min(r)); else { delete[]r; r = nullptr; --size_; } return; }
	
}

template <class T>
void BST<T>::Root::Insert(T x) {
	if (x < D) {
		if (l != nullptr) l->Insert(x);
		if (l == nullptr) l = new Root(x);
		++size_;
	}
	if (x>D) {
		if (r != nullptr) r->Insert(x);
		if (r == nullptr) r = new Root(x);
		++size_;
	}
}
template <class T>
bool BST<T>::Root::Search(T x) {
	if (x == D) { return true; }
	if (x > D) if (r != nullptr) return(r->Search(x));
	if (x < D) if (l != nullptr) return(l->Search(x));
	return false;
}
template <class T>
bool BST<T>::Root::print_console() {
	if (this != nullptr) {
		if (l != nullptr) l->print_console();
		cout << D << " ";
		if (r != nullptr) r->print_console();
		return true;
	}
	else { 

		return false;
	}
}
template <class T>
bool BST<T>::Root::print_file(ofstream &fout) {
	if (this != nullptr) {
		if (fout.is_open()) {
			if (l != nullptr) l->print_file(fout);
			fout << D << " ";
			if (r != nullptr) r->print_file(fout);
		}
		return true;
	}
	return false;
}
template <class T>
bool BST<T>::Insert(T x) {
	if (root != nullptr) if (Search(x)) throw Exist();
	if (root == nullptr) { root = new Root(x); return true; }
	else { root->Insert(x); return true; }
	return false;
}
template <class T>
bool BST<T>::Search(T x) {
	if (root == nullptr) throw Empty();
	return(root->Search(x));
}
template <class T>
bool BST<T>::del(T x) {
	if (root == nullptr) throw Empty();
	if (!this->Search(x)) {return false;}
	if (this->size()==1) {
		root = nullptr;
		delete root;
	root = nullptr;
		
	}
	else {
		root->del(x);
	}
	return true;
}

template <class T>
ostream & operator <<(ostream & out, BST<T> & tree) {
	if (tree.root->print_console()) return out;
	else throw Empty();
}
template <class T>
ifstream& operator >>(ifstream & fin, BST<T> & tree) {
	if (!fin.is_open()) throw File_Not_Open();
	T x;
	while (!fin.eof()) {
		if (fin>>x) tree.Insert(x);
		else break;
	}
	return fin;
}
template <class T>
ofstream & operator <<(ofstream & fout, BST<T> & tree) {
	if (tree.root->print_file(fout)) return fout; else throw Empty();
}

template <class T>
istream & operator >> (istream & in, BST<T> & tree) {
	size_t size;
	if (in >> size) {
		for (int i = 0; i < size; ++i) {
			T temp;
			if (in >> temp) {
				tree.Insert(temp);
			}
			else {
				throw
					Error_stream();
			}
		}
	}
	else {
		throw Error_stream();
	}

	return in;

}
/////////////////////////////////////////////////////////////////////////////



template <class T>
bool BST<T>::operator == (const BST<T> &tree) 
{
	

	iterator i = begin();
	iterator j = tree.begin();
	for (; i != end() || j != tree.end(); ++i, ++j) {
		if (*i != *j) {
			return false;
		}
	}

	return true;
}


template <class T>
auto BST<T>::fillListOfNodes(list<const Root*> & listOfNodes, const Root* root) ->void
{
	if (root) {
		if (root->l != nullptr) {
			fillListOfNodes(listOfNodes, root->l);
		}

		listOfNodes.push_back(root);

		if (root->r != nullptr) {
			fillListOfNodes(listOfNodes, root->r);
		}
	}
}

template <class T>
auto BST<T>::begin() const->iterator
{
	return iterator(root);
}

template <class T>
auto BST<T>::end() const->iterator
{
	return iterator();
}

template <class T>
BST<T>::NodeIterator::NodeIterator(const Root* root) : NodeIterator()
{
	fillListOfNodes(history_, root);
}

template <class T>
auto BST<T>::NodeIterator::operator == (const NodeIterator & _iterator) -> bool
{
	cout << "asd";
	return this->history_ == _iterator.history_;
}

template <class T>
auto BST<T>::NodeIterator::operator != (const NodeIterator & _iterator) -> bool
{
	return !this->operator==(_iterator);
}

template <typename T>
auto BST<T>::NodeIterator::operator ++() -> NodeIterator
{
	history_.pop_front();
	return *this;
}

template <typename T>
auto BST<T>::NodeIterator::operator *() const -> const T &
{
	return history_.front()->D;
}


