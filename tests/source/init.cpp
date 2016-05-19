#include <BST.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream> 
using namespace std;
                  
SCENARIO("Add_int", "[add]"){
  BST<int> tree;
  REQUIRE(tree.Insert(7));
  REQUIRE(tree.Insert(3));
  REQUIRE(tree.Insert(5));
  REQUIRE(tree.Search(3));
  REQUIRE(tree.Search(5));
  REQUIRE(tree.Search(7));
}

SCENARIO("Add_char", "[add_c]"){
  BST<char> tree;
  REQUIRE(tree.Insert(5));
  REQUIRE(tree.Insert(4));
  REQUIRE(tree.Insert(6));
  REQUIRE(tree.Search(4));
  REQUIRE(tree.Search(5));
  REQUIRE(tree.Search(6));
}

SCENARIO("Add_double", "[add_d]"){
  BST<double> tree;
  REQUIRE(tree.Insert(7.62));
  REQUIRE(tree.Insert(3.14));
  REQUIRE(tree.Insert(5.85));
  REQUIRE(tree.Search(3.14));
  REQUIRE(tree.Search(5.85));
  REQUIRE(tree.Search(7.62));
}

SCENARIO("Search_int", "[search_i]") {
BST<int> tree;
tree.Insert(7);
tree.Insert(5);
tree.Insert(1);
tree.Insert(9);
tree.Insert(3);
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
REQUIRE(!tree.Search(0));
REQUIRE(!tree.Search(8));
REQUIRE(!tree.Search(6));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(2));
}

SCENARIO("Search_char", "[search_c]") {
  BST<char> tree;
tree.Insert(7);
tree.Insert(5);
tree.Insert(1);
tree.Insert(9);
tree.Insert(3);
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
REQUIRE(!tree.Search(0));
REQUIRE(!tree.Search(8));
REQUIRE(!tree.Search(6));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(2));
}

SCENARIO("Search_double", "[search_d]") {
BST<double> tree;
tree.Insert(7.77);
tree.Insert(5.85);
tree.Insert(1.29);
tree.Insert(9.999);
tree.Insert(3.14);
REQUIRE(tree.Search(7.77));
REQUIRE(tree.Search(9.999));
REQUIRE(tree.Search(5.85));
REQUIRE(tree.Search(1.29));
REQUIRE(tree.Search(3.14));
REQUIRE(!tree.Search(0.5));
REQUIRE(!tree.Search(8.800));
REQUIRE(!tree.Search(6.666));
REQUIRE(!tree.Search(4.13));
REQUIRE(!tree.Search(2.34));
}

SCENARIO("Read_int","[read_i]"){
BST<int> tree; ifstream fin("read.txt");
fin>>tree;
fin.close();
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
}

SCENARIO("Read_double","[read_d]"){
BST<double> tree; ifstream fin("read_double.txt");
fin>>tree;
fin.close();
REQUIRE(tree.Search(12.74));
REQUIRE(tree.Search(15.62));
REQUIRE(tree.Search(7.62));
REQUIRE(tree.Search(3.14));
REQUIRE(tree.Search(8.34));
REQUIRE(tree.Search(25.15));
REQUIRE(tree.Search(17.16));
}

SCENARIO("Print_file_int","[print_file_i]"){
BST<int> tree, tree_2; ofstream fout("print.txt", ios::app);
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  fout<<tree; fout<<-1;
  fout.close();
  ifstream fin("print.txt");
  fin>>tree_2;
  fin.close();
  REQUIRE(tree_2.Search(7));
  REQUIRE(tree_2.Search(3));
  REQUIRE(tree_2.Search(5));
}

SCENARIO("Print_file_double","[print_file_d]"){
BST<double> tree, tree_2; ofstream fout("print_db.txt", ios::app);
  tree.Insert(7.77);
  tree.Insert(3.33);
  tree.Insert(5.55);
  fout<<tree; fout<<-1;
  fout.close();
  ifstream fin("print_db.txt");
  fin>>tree_2;
  fin.close();
  REQUIRE(tree_2.Search(7.77));
  REQUIRE(tree_2.Search(3.33));
  REQUIRE(tree_2.Search(5.55));
}


SCENARIO("Print_console_int", "[print_console_i]"){
BST<int> tree;  
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Print_console_char", "[print_console_c]"){
BST<char> tree;  
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Print_console_double", "[print_console_d]"){
BST<double> tree;  
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Iscl_add", "[I_a]"){
BST<int> tree; int O=0; 
tree.Insert(1);
try{tree.Insert(1);}
catch(Exist &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_not_open", "[I_no]"){
BST<int> tree; int O=0; ifstream fin("errotypeoffile");
try{fin>>tree;}
catch(File_Not_Open &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust1", "[I_p1]"){
BST<int> tree; int O=0; 
try{cout<<tree;}
catch(Empty &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust2", "[I_p2]"){
BST<int> tree; int O=0; ofstream fout("print_db.txt", ios::app);
try{fout<<tree;}
catch(Empty &e){O++;}
fout.close();
REQUIRE(O==1);
}


SCENARIO("Del", "[del]"){
BST<int> tree; int O=0;
tree.Insert(1);
tree.Insert(4);
tree.Insert(10);
tree.Insert(3);
tree.Insert(5);
tree.Insert(8);
tree.Insert(11);

REQUIRE(tree.del(1));
REQUIRE(!tree.Search(1));
REQUIRE(tree.Search(4));
REQUIRE(tree.Search(10));
REQUIRE(tree.Search(3));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
REQUIRE(tree.del(4));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(tree.Search(10));
REQUIRE(tree.Search(3));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
REQUIRE(tree.del(5));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(tree.Search(10));
REQUIRE(tree.Search(3));
REQUIRE(!tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
REQUIRE(tree.del(3));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(tree.Search(10));
REQUIRE(!tree.Search(3));
REQUIRE(!tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
REQUIRE(tree.del(10));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(10));
REQUIRE(!tree.Search(3));
REQUIRE(!tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(tree.Search(11));
REQUIRE(tree.del(11));
REQUIRE(!tree.Search(1));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(10));
REQUIRE(!tree.Search(3));
REQUIRE(!tree.Search(5));
REQUIRE(tree.Search(8));
REQUIRE(!tree.Search(11));
}

SCENARIO("Add_int999", "[add_l]"){
  BST<int> tree{1,2,3};
  REQUIRE(tree.Search(1));
  REQUIRE(tree.Search(2));
  REQUIRE(tree.Search(3));
}


SCENARIO("BST init with initializer list", "[init]") {
BST<int> tree {8};
	REQUIRE( tree.size() == 1 );
}

SCENARIO("BST search inserted element", "[search]") {
	BST<int> tree  {8, 4, 3};
	REQUIRE( tree.Search(4) );
}

SCENARIO("BST search non inserted element", "[search]") {
	BST<int> tree  {8, 4, 3};
	REQUIRE( !tree.Search(5) );
}

SCENARIO("BST delete non inserted element", "[delete]") {
	BST<int> tree {8};
	REQUIRE( !tree.del(4) );

}

SCENARIO("BST delete root without children", "[delete]") {
	BST<int> tree  {8};
	REQUIRE( tree.del(8) );
}


SCENARIO("BST delete root with one child", "[delete]") {
	BST<int> tree  {8, 4, 3};
	REQUIRE( tree.del(8) );
	REQUIRE( tree == BST<int>({4, 3}) );
}


SCENARIO("BST delete root with children", "[delete]") {
	BST<int> tree {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.del(8) );
	REQUIRE( tree == BST<int>({9, 4, 3, 10, 13, 11, 12}) );
}


SCENARIO("BST delete non root without children", "[delete]") {
	BST<int> tree  {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.del(3) );
	REQUIRE( tree == BST<int>({8, 4, 10, 9, 13, 11, 12}) );
}


SCENARIO("BST delete non root with one child", "[delete]") {
	BST<int> tree  {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.del(11) );
	REQUIRE( tree == BST<int>({8, 4, 3, 10, 9, 13, 12}) );
}


SCENARIO("BST delete non root with children", "[delete]") {
	BST<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
	REQUIRE( tree.del(10) );
	REQUIRE( tree == BST<int>({8, 4, 3, 11, 9, 13, 12}) );
}

