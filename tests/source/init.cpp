
#include <BST.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("list_init", "[list]"){
  BinarySearchTree<int> tree{7,5,9,4,6,8,10};
  REQUIRE(tree.search(7));
  REQUIRE(tree.search(5));
  REQUIRE(tree.search(9));
  REQUIRE(tree.search(4));
  REQUIRE(tree.search(6));
  REQUIRE(tree.search(8));
  REQUIRE(tree.search(10));
}

SCENARIO("Add_int", "[add]"){
  BinarySearchTree<int> tree;
  REQUIRE(tree.add(7));
  REQUIRE(tree.add(3));
  REQUIRE(tree.add(5));
  REQUIRE(tree.search(3));
  REQUIRE(tree.search(5));
  REQUIRE(tree.search(7));
}

SCENARIO("Add_char", "[add_c]"){
  BinarySearchTree<char> tree;
  REQUIRE(tree.add(5));
  REQUIRE(tree.add(4));
  REQUIRE(tree.add(6));
  REQUIRE(tree.search(4));
  REQUIRE(tree.search(5));
  REQUIRE(tree.search(6));
}

SCENARIO("Add_double", "[add_d]"){
  BinarySearchTree<double> tree;
  REQUIRE(tree.add(7.62));
  REQUIRE(tree.add(3.14));
  REQUIRE(tree.add(5.85));
  REQUIRE(tree.search(3.14));
  REQUIRE(tree.search(5.85));
  REQUIRE(tree.search(7.62));
}

SCENARIO("Search_int", "[search_i]") {
BinarySearchTree<int> tree;
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
BinarySearchTree<char> tree;
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
BinarySearchTree<double> tree;
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
REQUIRE(!tree.search(0.5));
REQUIRE(!tree.search(8.800));
REQUIRE(!tree.search(6.666));
REQUIRE(!tree.search(4.13));
REQUIRE(!tree.search(2.34));
}

SCENARIO("Read_int","[read_i]"){
BinarySearchTree<int> tree; ifstream fin("read_file_test.txt");
fin>>tree;
fin.close();
REQUIRE(tree.search(7));
REQUIRE(tree.search(9));
REQUIRE(tree.search(5));
REQUIRE(tree.search(1));
REQUIRE(tree.search(3));
}

SCENARIO("Read_double","[read_d]"){
BinarySearchTree<double> tree; ifstream fin("read_file_test_double.txt");
fin>>tree;
fin.close();
REQUIRE(tree.search(12.74));
REQUIRE(tree.search(15.62));
REQUIRE(tree.search(7.62));
REQUIRE(tree.search(3.14));
REQUIRE(tree.search(8.34));
REQUIRE(tree.search(25.15));
REQUIRE(tree.search(17.16));
}

SCENARIO("Print_file_int","[print_file_i]"){
BinarySearchTree<int> tree, tree_2; ofstream fout("print_file_test.txt", ios::app);
  tree.add(7);
  tree.add(3);
  tree.add(5);
  fout<<tree; fout<<-1;
  fout.close();
  ifstream fin("print_file_test.txt");
  fin>>tree_2;
  fin.close();
  REQUIRE(tree_2.search(7));
  REQUIRE(tree_2.search(3));
  REQUIRE(tree_2.search(5));
}

SCENARIO("Print_file_double","[print_file_d]"){
BinarySearchTree<double> tree, tree_2; ofstream fout("print_file_test_double.txt", ios::app);
  tree.add(7.77);
  tree.add(3.33);
  tree.add(5.55);
  fout<<tree; fout<<-1;
  fout.close();
  ifstream fin("print_file_test_double.txt");
  fin>>tree_2;
  fin.close();
  REQUIRE(tree_2.search(7.77));
  REQUIRE(tree_2.search(3.33));
  REQUIRE(tree_2.search(5.55));
}


SCENARIO("Print_console_int", "[print_console_i]"){
BinarySearchTree<int> tree;  
  tree.add(7);
  tree.add(3);
  tree.add(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Print_console_char", "[print_console_c]"){
BinarySearchTree<char> tree;  
  tree.add(7);
  tree.add(3);
  tree.add(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Print_console_double", "[print_console_d]"){
BinarySearchTree<double> tree;  
  tree.add(7);
  tree.add(3);
  tree.add(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Iscl_add", "[I_a]"){
BinarySearchTree<int> tree; int O=0; 
tree.add(1);
try{tree.add(1);}
catch(Uzhe_est &){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_not_open", "[I_no]"){
BinarySearchTree<int> tree; int O=0; ifstream fin("AVADA_KEDAVRA");
try{fin>>tree;}
catch(File_Not_Open &){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust1", "[I_p1]"){
BinarySearchTree<int> tree; int O=0; 
try{cout<<tree;}
catch(Pustoe_derevo &){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust2", "[I_p2]"){
BinarySearchTree<int> tree; int O=0; ofstream fout("print_file_test_double.txt", ios::app);
try{fout<<tree;}
catch(Pustoe_derevo &){O++;}
fout.close();
REQUIRE(O==1);
}

SCENARIO("Iscl_del1", "[del1]"){
BinarySearchTree<int> tree; int O=0;
try{tree.del(777);}
catch(Pustoe_derevo &){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_del2", "[del2]"){
BinarySearchTree<int> tree; int O=0;
tree.add(1);
try{tree.del(2);}
catch(Element_not_found &){O++;}
REQUIRE(O==1);
}


