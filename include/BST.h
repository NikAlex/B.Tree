#include <iostream> 
#include <fstream> 
#include <list> 
using namespace std;

template <class T>
class BST;
template <class T>
ostream & operator<<(ostream & out, BST<T> &tree);

template <class T>
ofstream & operator<<(ofstream & fout, BST<T> &tree);

template <class T>
ifstream & operator >> (ifstream & fin, BST<T> &tree);

template <class T>
istream & operator >> (istream & in, BST<T> &tree);

class Exceptions {
	char* err;
public:
	Exceptions(char* _err);
	char* what();
};
class File_Not_Open : public Exceptions {
public:
	File_Not_Open();
};
class Empty : public Exceptions {
public:
	Empty();
};
class Exist : public Exceptions {
public:
	Exist();
};
class Deleted : public Exceptions {
public:
	Deleted();
};
class Error_stream : public Exceptions {
public:
	Error_stream();
};

Exceptions::Exceptions(char* _err) : err(_err) {}

char* Exceptions::what() { return err; }

Exist::Exist() : Exceptions("ERROR: It's already exist!") {}

File_Not_Open::File_Not_Open() : Exceptions("ERROR: file is not open!") {}

Empty::Empty() : Exceptions("ERROR: The Binary Tree is empty!") {}

Deleted::Deleted() : Exceptions("ERROR: It was deleted before") {}

Error_stream::Error_stream() : Exceptions("ERROR: Stream error") {}

template <class T>
class BST {
public:
	class NodeIterator;
	using iterator = NodeIterator;

	BST() :root(nullptr) {};
	BST(const initializer_list<T> & ilist);
	~BST();
	bool operator == (const BST<T> & tree);
	auto begin() const->iterator;
	auto end() const->iterator;
	bool Insert(T x);
	bool Search(T x);
	bool del(T x); 
	size_t size();
	friend ostream & operator<< <>(ostream &out, BST<T> &tree);
	friend ofstream & operator<< <>(ofstream &fout, BST<T> &tree);
	friend ifstream & operator>> <>(ifstream &fin, BST<T> &tree);
	friend istream & operator >> <>(istream & in, BST<T> &tree);
	class Root;
	Root* root; 
	static auto  fillListOfNodes(list<const Root*> & listOfNodes, const Root* root)->void;
	class NodeIterator {
	public:
		NodeIterator() = default;
		NodeIterator(const Root* root);
		auto operator == (const NodeIterator & _iterator) -> bool;
		auto operator != (const NodeIterator & _iterator) -> bool;
		auto operator ++()->NodeIterator;
		auto operator *() const -> const T &;
		list<const Root*> history_;
		
	};
};

template <class T>
class BST<T>::Root {
public:
	Root(T x);
	void destroy(Root* root);
	void Insert(T x);
	bool Search(T x);
	size_t size_;
	size_t sizeRoot();
	bool print_console();
	bool print_file(ofstream &fout);
	void del(T el);
	T find_min(Root* el);
	T get_data() { return D; };
	T D;
	Root *l;
	Root *r;
private:
	
};

