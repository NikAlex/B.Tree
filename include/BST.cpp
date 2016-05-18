#include "BST.h"

using std::unique_ptr;
using std::move;
using std::ostream;
using std::istream;
using std::fstream;
using std::endl;

#ifndef BT_CPP
#define BT_CPP

template <typename T>	// WORKS
auto BinarySearchTree<T>::insert(const T &ref) -> bool {
    this->existed += 1;
    unique_ptr<node<T>> m_node(new node<T>(ref));

    if (root == nullptr) {
        root = move(m_node);
        return true;
    }
    else {
        node<T>* temp = root.get();
        node<T>* prev = root.get();

        while (temp != nullptr) {
            prev = temp;
            if (temp->data < ref) {
                temp = temp->right.get();
            }
            else if (temp->data == ref) {
                throw std::logic_error("Already exist");
            }
            else {
                temp = temp->left.get();
            }
        }

        if (prev->data < ref) {
            prev->right = move(m_node);
        }
        else {
            prev->left = move(m_node);
        }
        return true;
    }
    return false;
}

template <typename T>	// WORKS
auto BinarySearchTree<T>::remove(const T &key) -> node<T> * {
    if (search(key) == nullptr) {
        throw std::invalid_argument("Wrong index");
    }
    node<T> * leaf = root.get();
    return remove(key, leaf);
}

template<typename T>	// HARD, BUT WORKS
auto BinarySearchTree<T>::remove(const T &key, node<T> * leaf) -> node<T> * {
    // C - crutches
    if (leaf == nullptr) {
        return leaf;
    }

    if ((leaf->left.get() != nullptr) && ((leaf->left.get())->data == key)) {
        if (((leaf->left.get())->left.get() == nullptr) && ((leaf->left.get())->right.get() == nullptr)) {
            leaf->left.reset();
            this->existed -= 1;
            return leaf;
        }
    }
    else if ((leaf->right.get() != nullptr) && ((leaf->right.get())->data == key)) {
        if (((leaf->right.get())->left.get() == nullptr) && ((leaf->right.get())->right.get() == nullptr)) {
            leaf->right.reset();
            this->existed -= 1;
            return leaf;
        }
    }
    if (key < leaf->data) {
        leaf = remove(key, leaf->left.get());
    }
    else if (key > leaf->data) {
        leaf = remove(key, leaf->right.get());
    }
    else if ((leaf->left.get() != nullptr) && (leaf->right.get() != nullptr)) {
        leaf->data = findMin(leaf->right)->data;
        this->existed -= 1;
        return leaf;
    }
    else {
        if (leaf->left.get() != nullptr) {
            leaf->data = (leaf->left.get())->data;
            leaf->left.reset();
            this->existed -= 1;
            return leaf;
        }
        else {
            leaf->data = (leaf->right.get())->data;
            leaf->right = move((leaf->right.get())->right);
            this->existed -= 1;
            return leaf;
        }
    }
    return leaf;
}

template<typename T>	// Works?.. Hmm...
auto BinarySearchTree<T>::findMin(unique_ptr<node<T>>& leaf) -> node<T> * {
    if (leaf->left.get() == nullptr) {
        node<T> *tmp = new node<T>(leaf.get()->data);
        if (((leaf.get())->right).get() == nullptr) {
            leaf.reset();
        }
        else {
            leaf = move((leaf.get()->right));
        }
        return tmp;
    }
    return findMin(leaf->left);
}

template <typename T>	// WORKS
auto BinarySearchTree<T>::search(const T &key) -> node<T> * {
    node<T>* leaf = root.get();
    return search(key, leaf);
}

template <typename T>	// WORKS
auto BinarySearchTree<T>::search(const T & key, node<T>* leaf) -> node<T> * {
    if (leaf != nullptr) {
        if (key == leaf->data) {
            return leaf;
        }
        if (key < leaf->data) {
            return search(key, leaf->left.get());
        }
        else {
            return search(key, leaf->right.get());
        }
    }
    else {
        throw std::invalid_argument("Wrong index");
    }
}

template <typename T>	// WORKS
auto BinarySearchTree<T>::getCount() const -> size_t {
    return this->count;
}

template<typename T>	// WORKS
auto BinarySearchTree<T>::getNumber() const -> size_t {
    return this->existed;
}

template <typename T>	// WORKS
auto BinarySearchTree<T>::print(const unique_ptr<node<T>> &m_node, ostream & os, size_t width) -> void {
    node<T>* tmp = m_node.get();

    if (m_node.get() == nullptr) {
        return;
    }
    if (tmp->left.get() != nullptr) {
        print(tmp->left, os, width + 3);
    }
    if (width) {
        os.width(width);
        os << ' ';
    }
    os << m_node->data << endl;
    if (tmp->right.get()) {
        print(tmp->right, os, width + 3);
    }
}

template <typename T>	// WORKS
ostream & operator <<(ostream & os, BinarySearchTree<T> & x) {
    if (x.root == nullptr) {
        throw std::logic_error("Empty tree");
    }
    x.print(x.root, os);

    return os;
}

template <typename T>	// WORKS
istream & operator >>(istream & input, BinarySearchTree<T> & x) {
    T temp;
    if (x.count == 0) {
        throw std::logic_error("Empty tree");
    }
    else {
        for (size_t i = 0; i < x.count; ++i) {
            if (input >> temp) {
                x.insert(temp);
            }
            else {
                throw std::logic_error("Error in input stream");
            }
        }
        return input;
    }
}

template <typename T>	//WORKS
fstream & operator <<(fstream &file, BinarySearchTree<T> & x) {
    if (x.count == 0) {
        throw std::logic_error("Empty tree");
    }
    x.print(x.root, file);

    return file;
}

template <typename T>	// WORKS
fstream & operator >>(fstream &file, BinarySearchTree<T> & x) {
    T temp;
    if (x.count == 0) {
        throw std::logic_error("Empty tree");
    }
    else {
        for (size_t i = 0; i < x.count; ++i) {
            if (file >> temp) {
                x.insert(temp);
            }
            else {
                throw std::logic_error("Error in input stream");
            }
        }
        return file;
    }
}
#endif

