#pragma once
#include "Node.h"
#include "Element.h"
#include <string>

//! A hash table which stores <key,value> (<int,Node*>) pairs using open hashing
/**
* Because the structure of the class Element is closely similar to the class HashNode from this site https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250
* , my overall implementation is bound to be similar to the one on that site.
*/
class HashTable {
private:
	int size; //!< The size of the table
	//!The hash table, implemented as an array of linked lists that contain <key,value> pairs.
	/**
	* The array contains heads of linked lists (or nullptr). Each list contains <key,value> pairs (each stored as an Element)
	* where hashFunction(key) corresponds to the the array index that contains the list which contains all Elements with that hash value.
	* @see hashFunction
	* @see Element
	*/
	Element** table; 

	//! Returns hashCode of the given key
	int hashFunction(int key);
	Node* remove(Element* e, Element* previous, int hashCode);

public:
	HashTable(int size);
	~HashTable();

	//! Returns the Node associated with the given key
	Node* get(int key);
	//! Removes the <key,value> (<int,Node*>) pair associated with the given key
	Node* remove(int key);
	//! Updates the key value pair with a new value, or creates a new pair if the key in case it is a new key.
	void add(int key, Node* value);

	//!Returns a string with length of each list of the table 
	std::string toString();

};