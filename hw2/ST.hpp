#ifndef _ST_HPP_
#define _ST_HPP_

#include <utility>

#include "RBT.hpp"
#include "RBTPrint.hpp"

template <class Key, class Type>
class ST : public RedBlackTree<Key, Type> {
public:
	typedef RBTNode<Key, Type>* iterator;

	// Constructors
	// constant
	ST() { 
	}; 

	// Destructor
	// linear in the size of the ST
	~ST(){
	};

	// access or insert specifies element
	// inserts if the key is not present and returns a reference to
	// the value corresponding to that key
	// O(LogN), N size of ST
	Type& operator[](const Key& key) {
	}; 

	// insert a (key, value) pair, if the key already exists
	// set the new value to the existing key
	// O(LogN), N size of ST
	void insert(const Key& key, const Type& value) {
	};

	// remove element at the given position
	// amortized constant
	void remove(iterator position) {
	};

        // remove element with keyvalue key and 
	// return number of elements removed (either 0 or 1)
	// O(logN), N size of ST
	std::size_t remove(const Key& key) {
	};  

	// removes all elements from the ST, after this size() returns 0
	// linear in the size of the ST
	void clear() {
	}; 

	// checks if ST has no elements; true is empty, false otherwise
	// constant
	bool empty() const {
	}; 

	// returns number of elements in ST
	// constant
	std::size_t size() const {	
	}; 

	// returns number of elements that match keyvalue key
	// value returned is 0 or 1 since keys are unique
	// O(LogN), N size of ST
	std::size_t count(const Key& key) {
	}; 

	// find an element with keyvalue key and return 
	// the iterator to the element found, nullptr if not found
	// O(LogN), N size of ST
	iterator find(const Key& key) {
	};

	// check if key exists in ST
	// O(LogN), N size of ST
	bool contains(const Key& key) {
	};

        // return contents of ST as a vector of (key,value) pairs
        // O(N), N size of ST
        std::vector<std::pair<Key, Type> > toVector() {
        };

	// print the symbol table as Red-Black Tree
	// O(N), N size of ST
	void displayTree() {
		std::cout << RBTPrint<Key,Type>::TreeToString(RedBlackTree<Key,Type>::root) << std::endl;
	};

	// print the symbol table in sorted order
	// O(N), N size of ST
	void display() {
	};

private:
	std::size_t nodeCount;

};

#endif

