#include <BST.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("Add_int", "[add]") {
	BST<int> tree;
	REQUIRE(tree.add(1));
	REQUIRE(tree.add(2));
	REQUIRE(tree.add(3));
	REQUIRE(tree.search(2));
	REQUIRE(tree.search(3));
	REQUIRE(tree.search(1));
}

SCENARIO("Add_char", "[add_c]") {
	BST<char> tree;
	REQUIRE(tree.add(6));
	REQUIRE(tree.add(5));
	REQUIRE(tree.add(4));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(6));
	REQUIRE(tree.search(4));
}

SCENARIO("Add_double", "[add_d]") {
	BST<double> tree;
	REQUIRE(tree.add(14.88));
	REQUIRE(tree.add(3.14));
	REQUIRE(tree.add(2.17));
	REQUIRE(tree.search(3.14));
	REQUIRE(tree.search(2.17));
	REQUIRE(tree.search(14.88));
}

SCENARIO("Search_int", "[search_i]") {
	BST<int> tree;
	tree.add(7);
	tree.add(5);
	tree.add(1);
	tree.add(9);
	tree.add(3);
	REQUIRE(tree.search(7));
	REQUIRE(tree.search(9));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(1));
	REQUIRE(tree.search(3));
	REQUIRE(!tree.search(0));
	REQUIRE(!tree.search(8));
	REQUIRE(!tree.search(6));
	REQUIRE(!tree.search(4));
	REQUIRE(!tree.search(2));
}

SCENARIO("Search_char", "[search_c]") {
	BST<char> tree;
	tree.add(7);
	tree.add(5);
	tree.add(1);
	tree.add(9);
	tree.add(3);
	REQUIRE(tree.search(7));
	REQUIRE(tree.search(9));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(1));
	REQUIRE(tree.search(3));
	REQUIRE(!tree.search(0));
	REQUIRE(!tree.search(8));
	REQUIRE(!tree.search(6));
	REQUIRE(!tree.search(4));
	REQUIRE(!tree.search(2));
}

SCENARIO("Search_double", "[search_d]") {
	BST<double> tree;
	tree.add(7.77);
	tree.add(5.85);
	tree.add(1.29);
	tree.add(9.999);
	tree.add(3.14);
	REQUIRE(tree.search(7.77));
	REQUIRE(tree.search(9.999));
	REQUIRE(tree.search(5.85));
	REQUIRE(tree.search(1.29));
	REQUIRE(tree.search(3.14));
	REQUIRE(!tree.search(4.3));
	REQUIRE(!tree.search(2.777));
	REQUIRE(!tree.search(14.888));
	REQUIRE(!tree.search(6.22));
	REQUIRE(!tree.search(8.14));
}

SCENARIO("Del", "[del]"){
BST<int> tree; int G=0;
tree.add(8);
tree.add(6);
tree.add(12);
tree.add(3);
tree.add(7);
tree.add(9);
tree.add(15);
tree.add(13);
REQUIRE(tree.del(12));
REQUIRE(!tree.search(12));
REQUIRE(tree.search(8));
REQUIRE(tree.search(6));
REQUIRE(tree.search(3));
REQUIRE(tree.search(7));
REQUIRE(tree.search(9));
REQUIRE(tree.search(15));
REQUIRE(tree.search(13));
///
REQUIRE(tree.del(3));
REQUIRE(!tree.search(12));
REQUIRE(tree.search(8));
REQUIRE(tree.search(6));
REQUIRE(!tree.search(3));
REQUIRE(tree.search(7));
REQUIRE(tree.search(9));
REQUIRE(tree.search(15));
REQUIRE(tree.search(13));
///
REQUIRE(tree.del(6));
REQUIRE(!tree.search(12));
REQUIRE(tree.search(8));
REQUIRE(!tree.search(6));
REQUIRE(!tree.search(3));
REQUIRE(tree.search(7));
REQUIRE(tree.search(9));
REQUIRE(tree.search(15));
REQUIRE(tree.search(13));
///
REQUIRE(tree.del(13));
REQUIRE(!tree.search(12));
REQUIRE(tree.search(8));
REQUIRE(!tree.search(6));
REQUIRE(!tree.search(3));
REQUIRE(tree.search(7));
REQUIRE(tree.search(9));
REQUIRE(tree.search(15));
REQUIRE(!tree.search(13));
///
REQUIRE(tree.del(8));
REQUIRE(!tree.search(12));
REQUIRE(!tree.search(8));
REQUIRE(!tree.search(6));
REQUIRE(!tree.search(3));
REQUIRE(tree.search(7));
REQUIRE(tree.search(9));
REQUIRE(tree.search(15));
REQUIRE(!tree.search(13));
///
REQUIRE(tree.del(15));
REQUIRE(!tree.search(12));
REQUIRE(!tree.search(8));
REQUIRE(!tree.search(6));
REQUIRE(!tree.search(3));
REQUIRE(tree.search(7));
REQUIRE(tree.search(9));
REQUIRE(!tree.search(15));
REQUIRE(!tree.search(13));
///
REQUIRE(tree.del(9));
REQUIRE(!tree.search(12));
REQUIRE(!tree.search(8));
REQUIRE(!tree.search(6));
REQUIRE(!tree.search(3));
REQUIRE(tree.search(7));
REQUIRE(!tree.search(9));
REQUIRE(!tree.search(15));
REQUIRE(!tree.search(13));
///
try{ tree.del(7);}
catch(Tree_Was_Deleted &){G++;}
REQUIRE(G==1);
}

SCENARIO("Read_int", "[read_i]") {
	BST<int> tree; ifstream fin("read.txt");
	fin >> tree;
	fin.close();
	REQUIRE(tree.search(1));
	REQUIRE(tree.search(4));
	REQUIRE(tree.search(3));
	REQUIRE(tree.search(5));
	REQUIRE(tree.search(2));
}

SCENARIO("Read_double", "[read_d]") {
	BST<double> tree; ifstream fin("read_double.txt");
	fin >> tree;
	fin.close();
	REQUIRE(tree.search(14.88));
	REQUIRE(tree.search(3.14));
	REQUIRE(tree.search(7.62));
	REQUIRE(tree.search(2.30));
	REQUIRE(tree.search(4.44));
	REQUIRE(tree.search(5.02));
	REQUIRE(tree.search(27.86));
}

SCENARIO("Print_int", "[print_file_i]") {
	BST<int> tree, tree_2; ofstream fout("print.txt", ios::app);
	tree.add(1);
	tree.add(2);
	tree.add(3);
	fout << tree; fout << -1;
	fout.close();
	ifstream fin("print.txt");
	fin >> tree_2;
	fin.close();
	REQUIRE(tree_2.search(1));
	REQUIRE(tree_2.search(2));
	REQUIRE(tree_2.search(3));
}

SCENARIO("Print_file_double", "[print_file_d]") {
	BST<double> tree, tree_2; ofstream fout("print_double.txt", ios::app);
	tree.add(1.23);
	tree.add(4.56);
	tree.add(7.89);
	fout << tree; fout << -1;
	fout.close();
	ifstream fin("print_double.txt");
	fin >> tree_2;
	fin.close();
	REQUIRE(tree_2.search(1.23));
	REQUIRE(tree_2.search(4.56));
	REQUIRE(tree_2.search(7.89));
}


SCENARIO("Print_console_int", "[print_console_i]") {
	BST<int> tree;
	tree.add(1);
	tree.add(2);
	tree.add(3);
	REQUIRE(cout << tree);
}

SCENARIO("Print_console_char", "[print_console_c]") {
	BST<char> tree;
	tree.add(1);
	tree.add(2);
	tree.add(3);
	REQUIRE(cout << tree);
}

SCENARIO("Print_console_double", "[print_console_d]") {
	BST<double> tree;
	tree.add(1);
	tree.add(2);
	tree.add(3);
	REQUIRE(cout << tree);
}

SCENARIO("Iscl_add", "[I_a]") {
	BST<int> tree; int G = 0;
	tree.add(1);
	try { tree.add(1); }
	catch (Busy &e) { G++; }
	REQUIRE(G == 1);
}

SCENARIO("Iscl_not_open", "[I_no]") {
	BST<int> tree; int G = 0; ifstream fin("kek");
	try { fin >> tree; }
	catch (File_Not_Open &e) { G++; }
	REQUIRE(G == 1);
}

SCENARIO("Iscl_pust1", "[I_p1]") {
	BST<int> tree; int G = 0;
	try { cout << tree; }
	catch (Empty_tree &e) { G++; }
	REQUIRE(G == 1);
}

SCENARIO("Iscl_pust2", "[I_p2]") {
	BST<int> tree; int G = 0; ofstream fout("print_double.txt", ios::app);
	try { fout << tree; }
	catch (Empty_tree &e) { G++; }
	fout.close();
	REQUIRE(G == 1);
}

SCENARIO("Iscl_del1", "[del1]"){
BST<int> tree; int G=0;
try{tree.del(777);}
catch(Empty_tree &){G++;}
REQUIRE(G==1);
}

SCENARIO("Iscl_del2", "[del2]"){
BST<int> tree; int G=0;
tree.add(1);
try{tree.del(2);}
catch(Element_not_found &){G++;}
REQUIRE(G==1);
}

SCENARIO("Iscl_del3", "[del3]"){
BST<int> tree; int G=0;
tree.add(1);
try{tree.del(1);}
catch(Tree_Was_Deleted &){G++;}
REQUIRE(G==1);
}
