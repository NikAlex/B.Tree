#ifndef binarysearchtree_h
#define binarysearchtree_h
#pragma once
#include <iostream>
#include <fstream>
#include <initializer_list>
using namespace std;

template <class Z>
class BinarySearchTree;

template <class Z>
ostream & operator<<(ostream & out, BinarySearchTree<Z> &tree);

template <class Z>
ofstream & operator<<(ofstream & fout, BinarySearchTree<Z> &tree);

template <class Z>
ifstream & operator >> (ifstream & fin, BinarySearchTree<Z> &tree);
class Iscluchenia {
	char* err;
public:
	Iscluchenia(char* _err);
	char* what();
};

class Uzhe_est : public Iscluchenia{
public:
	Uzhe_est();
};

class File_Not_Open : public Iscluchenia{
public:
	File_Not_Open();
};

class Pustoe_derevo : public Iscluchenia{
public:
	Pustoe_derevo();
};

class Element_not_found : public Iscluchenia{  
public:
	Element_not_found();
};

class Tree_Was_Deleted : public Iscluchenia{  
public:
	Tree_Was_Deleted();
};

template <class Z>
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(initializer_list<Z> L);
	~BinarySearchTree();
	bool add(Z x);
	bool search(Z x);
	bool del(Z x);
	void sozdaem_derevo_snova();
	friend ostream & operator<< <>(ostream &out, BinarySearchTree<Z> &tree);
	friend ofstream & operator<< <>(ofstream &fout, BinarySearchTree<Z> &tree);		
	friend ifstream & operator>> <>(ifstream &fin, BinarySearchTree<Z> &tree);
private:
	class der; 
	der* root;
};

template <class Z>
class BinarySearchTree<Z>::der{
public:
	der(Z x);
	void add(Z x);
	bool search(Z x);
	bool print_console();
	bool print_file(ofstream &fout);
	void del(Z x);
	Z min(der* G);
	void do_free(der* root); 
private:
	Z D;
	der *l;
	der *r;
};



/*#define TAHK double

int main(){
	BinarySearchTree<TAHK> tree{ 7, 5, 9, 3, 6, 8, 10 }; 
	int J;
	cout << "add-1, search-2, read_f-3, spis_inic-4, del-6, fr_pr_c-7, fr_r_f-8, fr_pr_f-9 exit-0\n";
	do{
		cout << "J="; cin >> J;
		if (J == 1){
			TAHK x;
			cout << "x="; cin >> x;
			try{ if (tree.add(x))cout << "done\n"; }
			catch (Uzhe_est &e){ cout << e.what() << endl; }
		}
		if (J == 2){
			TAHK x;
			cout << "x="; cin >> x;
			try{ if (tree.search(x)) cout << "founded\n"; else cout << "not founded\n"; }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; } 
		}
		if (J == 6){
			int x;
			cout << "x="; cin >> x;
			try{ tree.del(x); }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; }
			catch (Element_not_found &e){ cout << e.what() << endl; }
			catch (Tree_Was_Deleted &e) { cout << e.what() << endl; tree.sozdaem_derevo_snova(); }
		}
		if (J == 7){
			try{ cout << tree; cout << endl; }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; }
		}
		if (J == 8){
			char a[20];
			cout << "name of file: "; cin >> a;	
			ifstream fin(a);
			try{ fin >> tree; }
			catch (File_Not_Open &e) { cout << e.what() << endl; }
			fin.close();
		}
		if (J == 9){
			char a[20];
			cout << "name of file: "; cin >> a;
			ofstream fout(a, ios::app);
			try{ fout << tree; fout << -1; }
			catch (Pustoe_derevo &e) { cout << e.what() << endl; }
			fout.close();
		}
	} while (J);
	system("pause");
}*/
#endif

