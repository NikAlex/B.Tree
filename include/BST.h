#pragma once
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <vector>

using std::exception;
using std::ostream;
using std::istream;
using std::fstream;
using std::vector;
using std::unique_ptr;
using std::iterator;
using std::output_iterator_tag;
using std::cout;

#ifndef BT_H
#define BT_H

template <typename T>
class BinarySearchTree;

template <typename T>
ostream & operator<<(ostream & output, BinarySearchTree<T> &);
template <typename T>
istream & operator >> (istream & input, BinarySearchTree<T> &);
template <typename T>
fstream & operator<<(fstream & file, BinarySearchTree<T> &);
template <typename T>
fstream & operator >> (fstream & file, BinarySearchTree<T> &);

template <typename T>
struct node {
	typedef unique_ptr<node<T>> ptrNode;

	T			data;
	ptrNode		left;
	ptrNode		right;
	node(const T & value) : data(value), left(nullptr), right(nullptr) {};
};

template <typename T>
class BinarySearchTree {
private:
	typedef		unique_ptr<node<T>> ptrNode;
	ptrNode		root;
	size_t		count;
	size_t		existed;
	vector<T>	elements;

	auto		print(const unique_ptr<node<T>>&, ostream & os = cout, size_t width = 0)->void;
	auto		remove(const T&, node<T>*)->node<T> *;
	auto		findMin(unique_ptr<node<T>>&)->node<T> *;
	auto		search(const T&, node<T>*)->node<T> *;
	auto		createVector(const unique_ptr<node<T>> &m_node, vector<T> &elem)->vector<T>;
public:
	BinarySearchTree() : root(nullptr), count(0), existed(0) {};					// TESTED
	BinarySearchTree(size_t k) : root(nullptr), count(k), existed(0) {};			// TESTED
	BinarySearchTree(const std::initializer_list<T> &list);							// WORKS

	auto		insert(const T&)->bool; 									// TESTED
	auto		remove(const T&)->node<T> *;								// tested?..
	auto		search(const T&)->node<T> *;								// TESTED
	auto		getCount() const->size_t;									// TESTED
	auto		getNumber() const->size_t;
	auto		createVector()->vector<T>;
	auto		getRoot()->T;
	auto		begin();
	auto		end();

	friend		istream & operator >> <>(istream &, BinarySearchTree &);		// TESTED
	friend		fstream & operator >> <>(fstream &, BinarySearchTree &);		// TESTED
	friend		ostream & operator<< <>(ostream &, BinarySearchTree &);		// TESTED
	friend		fstream & operator<< <>(fstream &, BinarySearchTree &);		// TESTED
};

#include "BST.cpp"

#endif
