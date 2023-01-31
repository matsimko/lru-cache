#include "HashTable.h"
#include <sstream>

HashTable::HashTable(int size) {
	this->size = size;
	this->table = new Element * [size];
	//initalize all lists as empty
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}
HashTable::~HashTable() {
	//go through all lists
	for (int i = 0; i < size; i++) {
		//sequentially delete all Elements of the list starting from the head 
		Element* current = table[i];
		Element* next = nullptr;
		while (current) {
			next= current->next;
			delete current;

			current = next;
		}
	}

	delete[] table;
}

Node* HashTable::get(int key) {
	Element* current = table[hashFunction(key)]; //find the list associated with the hashFunctions' result
	//iterate through the list starting from the head
	while (current) {
		//if the keys match, return the node
		if (current->key == key)
			return current->value;

		current = current->next;
	}

	return nullptr;
}

/**
*The idea of using a "previous" variable to reconnect Elements adjacent to the removed Element from a singly-linked list was taken from this site: https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250 (function "remove")
*/
Node* HashTable::remove(int key) {

	int hashCode = hashFunction(key);
	Element* current = table[hashCode]; //find the list associated with the hashFunctions' result
	Element* previous = nullptr;
	//iterate through the list starting from the head
	while (current) {
		if (current->key == key)
			return remove(current,previous, hashCode);

		previous = current;
		current = current->next;
	}

	return nullptr;
}

/**
*The idea of using a "previous" variable to reconnect Elements adjacent to the removed Element from a singly-linked list was taken from this site: https://aozturk.medium.com/simple-hash-map-hash-table-implementation-in-c-931965904250 (function "remove")
*/
Node* HashTable::remove(Element* e, Element* previous, int hashCode) {
	Node* value = e->value;

	//e is the head if previous is nullptr
	if (previous == nullptr) {
		table[hashCode] = e->next; //set the next element as the head
	}
	else {
		previous->next = e->next;
	}

	delete e;
	return value;
}

void HashTable::add(int key, Node* value) {

	int hashValue = hashFunction(key);
	Element* current = table[hashValue]; //find the list associated with the hashFunctions' result

	//if the list is empty, set the new element as the head
	if (current == nullptr) {
		table[hashValue] = new Element(key, value);
		return;
	}
	//iterate through the list starting from the head
	while (current->next) {
		//if the key was found, update the value
		if (current->key == key) {
			current->value = value;
			return;
		}

		current = current->next;
	}
	//The tail was reached and it needs to be checked if its key doesn't match the sought key. If so, update the value.
	if (current->key == key) {
		current->value = value;
		return;
	}
	//the key was not found, so append a new node at the and of the list
	current->next = new Element(key, value);
	return;
}


int HashTable::hashFunction(int key) {
	return (key % size);
}

std::string HashTable::toString() {
	std::stringstream ss;
	for (int i = 0; i < size; i++) {
		Element* current = table[i];
		int count = 0;
		while (current) {
			count++;
			current = current->next;
		}
		ss << count;
		if (i < size - 1)
			ss << ", ";
	}
	ss << "\n";
	return ss.str();
}