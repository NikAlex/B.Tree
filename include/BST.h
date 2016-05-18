#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory>
#include <stdexcept>

using std::exception;
using std::unique_ptr;
using std::ostream;
using std::istream;
using std::fstream;

#ifndef BT_H
#define BT_H

template <typename T>
class BinarySearchTree;

template <typename T>
ostream & operator<<(ostream & output, BinarySearchTree<T> &);

template <typename T>
istream & operator>>(istream & input, BinarySearchTree<T> &);

template <typename T>
fstream & operator<<(fstream & file, BinarySearchTree<T> &);

template <typename T>
fstream & operator>>(fstream & file, BinarySearchTree<T> &);

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

    auto		print(const unique_ptr<node<T>>&, ostream & os = std::cout, size_t width = 0) -> void;
    auto		remove(const T&, node<T>*) -> node<T> *;
    auto		findMin(unique_ptr<node<T>>&) -> node<T> *;
    auto		search(const T&, node<T>*) -> node<T> *;
public:
    BinarySearchTree() : root(nullptr), count(0), existed(0) {};					// TESTED
    BinarySearchTree(size_t k) : root(nullptr), count(k), existed(0) {};			// TESTED

    auto		insert(const T&) -> bool;									// TESTED
    auto		remove(const T&) -> node<T> *;								// tested?..
    auto		search(const T&) -> node<T> *;								// TESTED
    auto		getCount() const -> size_t;									// TESTED
    auto		getNumber() const -> size_t;									// TESTED

    friend		ostream & operator<< <>(ostream &output, BinarySearchTree &);		// TESTED
    friend		istream & operator>> <>(istream &input, BinarySearchTree &);		// TESTED
    friend		fstream & operator<< <>(fstream &file, BinarySearchTree<T> &);		// TESTED
    friend		fstream & operator>> <>(fstream &file, BinarySearchTree<T> &);		// TESTED
};

#include "BST.cpp"

#endif

