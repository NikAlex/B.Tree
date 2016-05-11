#include "BST.h"
#include <iostream>
#include <fstream>
using namespace std;
Exceptions::Exceptions(char* _err) : err(_err){}
char* Exceptions::what() { return err; }
Busy::Busy() : Exceptions("ERROR: Already added") {}
File_Not_Open::File_Not_Open() : Exceptions("ERROR: file not open!") {}
Empty_tree::Empty_tree() : Exceptions("ERROR: Tree is empty!") {}
Element_not_found::Element_not_found() : Exceptions("ERROR: Empty") {}
Tree_Was_Deleted::Tree_Was_Deleted() : Exceptions("ERROR: Tree was deleted!") {}


template <class T>
BST<T>::Node::Node(T x) : k(x), l(nullptr), r(nullptr) {}
template <class T>
void BST<T>::Node::add(T x) 
{
	if (x < k) 
	{
		if (l != nullptr) l->add(x);
		if (l == nullptr) l = new Node(x);
	}
	if (x>k) 
	{
		if (r != nullptr) r->add(x);
		if (r == nullptr) r = new Node(x);
	}
}
template <class T>
bool BST<T>::Node::search(T x) 
{
	if (x == k) { return true; }
	if (x > k) if (r != nullptr) return(r->search(x));
	if (x < k) if (l != nullptr) return(l->search(x));
	return false;
}
template <class T>
bool BST<T>::Node::print_file(ofstream &fout) 
{
	if (this != nullptr) {
		if (fout.is_open()) 
		{
			if (l != nullptr) l->print_file(fout);
			fout << k << " ";
			if (r != nullptr) r->print_file(fout);
		}
		return true;
	}
	return false;
}
template <class T>
bool BST<T>::Node::print_console() 
{
	if (this != nullptr) 
	{
		if (l != nullptr) l->print_console();
		cout << k << " ";
		if (r != nullptr) r->print_console();
		return true;
	}
	else return false;
}

template <class T>
T BST<T>::Node::min(Node* M)
{
	if (M->l) return min(M->l);
	else return M->k;
}
template <class T>
void BST<T>::Node::del(T x)
{
	if ((x == k) && (!l) && (!r)) { delete this; throw Tree_Was_Deleted(); }
	if ((x == k) && (!l)) 
	{
		k = r->k;
		if (r->l) l = r->l; else l = nullptr;
		if (r->r) r = r->r; else r = nullptr;
		return;
	}
	if ((x == k) && (!r)) 
	{
		k = l->k;
		if (l->r) r = l->r; else r = nullptr;
		if (l->l) l = l->l; else l = nullptr;
		return;
	}
	if (x < k) 
	{
		if ((l->k == x) && (!(l->r)) && (!(l->l))) { l = nullptr; return; }
		if ((l->k == x) && (l->l) && (l->r)) { l->k = min(l->r); if (l->r->k != min(l->r)) l->r->del(min(l->r)); else l->r = nullptr; return; }
		else; l->del(x);
		return;
	}
	if (x > k) 
	{ 
		if ((r->k == x) && (!(r->r)) && (!(r->l))) { r = nullptr; return; }
		if ((r->k == x) && (r->l) && (r->r)) { r->k = min(r->r); if (r->r->k != min(r->r)) r->r->del(min(r->r)); else r->r = nullptr; return; }
		else r->del(x);
		return;
	}
	if ((x == k) && (l) && (r)) { k = min(r); if (r->k != min(r)) r->del(min(r)); else r = nullptr; return; }
}

template <class T>
void BST<T>::Create_tree_again() {
	parent = nullptr;
}

template <class T>
BST<T>::BST() : parent(nullptr) {}
template <class T>
bool BST<T>::add(T x) 
{
	if (parent != nullptr) if (search(x)) throw Busy();
	if (parent == nullptr) { parent = new Node(x); return true; }
	else { parent->add(x); return true; }
	return false;
}
template <class T>
bool BST<T>::search(T x) 
{
	if (parent == nullptr) throw Empty_tree();
	return(parent->search(x));
}

template <class T>
bool BST<T>::del(T x)
{
	if (parent == nullptr) throw Empty_tree();
	if (!this->search(x)) throw Element_not_found();
	try{ parent->del(x); }
	catch (Tree_Was_Deleted &){ throw Tree_Was_Deleted(); }
	return true;
}
template <class T>
ifstream & operator >>(ifstream & fin, BST<T> & tree) 
{
	if (!fin.is_open()) throw File_Not_Open();
	T x;
	while (!fin.eof()) 
	{
		fin >> x;
		if (x != -1)tree.add(x);
		else break;
	}
	return fin;
}
template <class T>
ostream & operator <<(ostream & out, BST<T> & tree) 
{
	if (tree.parent->print_console()) return out;
	else throw Empty_tree();
}
template <class T>
ofstream & operator <<(ofstream & fout, BST<T> & tree) 
{
	if (tree.parent->print_file(fout)) return fout;
	else throw Empty_tree();
}
