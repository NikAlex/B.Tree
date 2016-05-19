#ifndef BST_h 
#define BST_h 
#pragma once 
#include <iostream> 
#include <fstream> 
#include <initializer_list> 
using namespace std; 

template <class Z> 
class BinarySearchTree; 

template <class Z> 
ostream & operator«(ostream & out, BinarySearchTree<Z> &tree); 

template <class Z> 
ofstream & operator«(ofstream & fout, BinarySearchTree<Z> &tree); 

template <class Z> 
ifstream & operator » (ifstream & fin, BinarySearchTree<Z> &tree); 
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
friend ostream & operator« <>(ostream &out, BinarySearchTree<Z> &tree); 
friend ofstream & operator« <>(ofstream &fout, BinarySearchTree<Z> &tree); 
friend ifstream & operator» <>(ifstream &fin, BinarySearchTree<Z> &tree); 
private: 
class der; 
der* root; 
}; 

template <class Z> 
class BinarySearchTree<Z>::der{ 
public: 
der(Z x); 
void destroy(der* root);
void add(Z x); 
bool search(Z x); 
bool print_console(); 
bool print_file(ofstream &fout); 
void del(Z x); 
Z min(der* G); 
void TFREE(); 
private: 
Z D; 
der *l; 
der *r; 
}; 

#endif
