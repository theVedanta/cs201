/*
  Name: Vedanta Somnathe
  Email: vpsomnathe@crimson.ua.edu
  Course Section: Spring 2026 CS 201 – 002
  Homework #: 2
  To Compile: g++ -std=c++20 -o STMain STMain.cpp
  To Run:     ./STMain
*/

#ifndef _ST_HPP_
#define _ST_HPP_

#include <iostream>
#include <utility>
#include <vector>

#include "RBT.hpp"
#include "RBTPrint.hpp"

template <class Key, class Type> class ST : public RedBlackTree<Key, Type> {
public:
  typedef RBTNode<Key, Type> *iterator;

  // Constructors
  // constant
  ST() { nodeCount = 0; };

  // Destructor
  // linear in the size of the ST
  // The base class RedBlackTree destructor handles deleting tree nodes.
  ~ST() {
    // RedBlackTree::~RedBlackTree() calls DeleteTree(root) automatically.
    // We just reset our count.
    nodeCount = 0;
  };

  // access or insert specifies element
  // inserts if the key is not present and returns a reference to
  // the value corresponding to that key
  // O(LogN), N size of ST
  Type &operator[](const Key &key) {
    RBTNode<Key, Type> *node = RedBlackTree<Key, Type>::Search(key);
    if (node != nullptr) {
      return node->value;
    }
    // Key not found, insert with default value
    RBTNode<Key, Type> *newNode = RedBlackTree<Key, Type>::Insert(key, Type());
    nodeCount++;
    return newNode->value;
  };

  // insert a (key, value) pair, if the key already exists
  // set the new value to the existing key
  // O(LogN), N size of ST
  void insert(const Key &key, const Type &value) {
    RBTNode<Key, Type> *node = RedBlackTree<Key, Type>::Search(key);
    if (node != nullptr) {
      node->value = value;
    } else {
      RedBlackTree<Key, Type>::Insert(key, value);
      nodeCount++;
    }
  };

  // remove element at the given position
  // amortized constant
  void remove(iterator position) {
    if (position == nullptr) {
      return;
    }
    RedBlackTree<Key, Type>::RemoveNode(position);
    nodeCount--;
  };

  // remove element with keyvalue key and
  // return number of elements removed (either 0 or 1)
  // O(logN), N size of ST
  std::size_t remove(const Key &key) {
    RBTNode<Key, Type> *node = RedBlackTree<Key, Type>::Search(key);
    if (node == nullptr) {
      return 0;
    }
    RedBlackTree<Key, Type>::RemoveNode(node);
    nodeCount--;
    return 1;
  };

  // removes all elements from the ST, after this size() returns 0
  // linear in the size of the ST
  void clear() {
    RedBlackTree<Key, Type>::DeleteTree(RedBlackTree<Key, Type>::root);
    RedBlackTree<Key, Type>::root = nullptr;
    nodeCount = 0;
  };

  // checks if ST has no elements; true is empty, false otherwise
  // constant
  bool empty() const { return nodeCount == 0; };

  // returns number of elements in ST
  // constant
  std::size_t size() const { return nodeCount; };

  // returns number of elements that match keyvalue key
  // value returned is 0 or 1 since keys are unique
  // O(LogN), N size of ST
  std::size_t count(const Key &key) {
    RBTNode<Key, Type> *node = RedBlackTree<Key, Type>::Search(key);
    if (node != nullptr) {
      return 1;
    }
    return 0;
  };

  // find an element with keyvalue key and return
  // the iterator to the element found, nullptr if not found
  // O(LogN), N size of ST
  iterator find(const Key &key) {
    return RedBlackTree<Key, Type>::Search(key);
  };

  // check if key exists in ST
  // O(LogN), N size of ST
  bool contains(const Key &key) {
    return RedBlackTree<Key, Type>::Search(key) != nullptr;
  };

  // return contents of ST as a vector of (key,value) pairs
  // O(N), N size of ST
  std::vector<std::pair<Key, Type>> toVector() {
    std::vector<std::pair<Key, Type>> result;
    result.reserve(nodeCount);
    inorderCollect(RedBlackTree<Key, Type>::root, result);
    return result;
  };

  // print the symbol table as Red-Black Tree
  // O(N), N size of ST
  void displayTree() {
    std::cout << RBTPrint<Key, Type>::TreeToString(
                     RedBlackTree<Key, Type>::root)
              << std::endl;
  };

  // print the symbol table in sorted order
  // O(N), N size of ST
  void display() { inorderDisplay(RedBlackTree<Key, Type>::root); };

private:
  std::size_t nodeCount;

  // Helper: in-order traversal to collect (key, value) pairs into a vector
  void inorderCollect(RBTNode<Key, Type> *node,
                      std::vector<std::pair<Key, Type>> &vec) {
    if (node == nullptr) {
      return;
    }
    inorderCollect(node->left, vec);
    vec.push_back(std::make_pair(node->key, node->value));
    inorderCollect(node->right, vec);
  }

  // Helper: in-order traversal to display key: value pairs
  void inorderDisplay(RBTNode<Key, Type> *node) {
    if (node == nullptr) {
      return;
    }
    inorderDisplay(node->left);
    std::cout << node->key << ": " << node->value << std::endl;
    inorderDisplay(node->right);
  }
};

#endif
