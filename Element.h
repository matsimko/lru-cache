#pragma once
#include "Node.h"

//!An element of a linked list that is used in HashTable
/**
* The idea of storing the <key,value> pair like this was inspired by the class HashNode from this site: https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250 
*@see HashTable
*/
class Element {
private:
	int key; 
	Node* value;
	
	Element* next; //!<The next Element in the list.

public:
	Element(int key, Node* value);

	friend class HashTable;

};