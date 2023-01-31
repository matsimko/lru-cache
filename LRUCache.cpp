#include "LRUCache.h"
#include <sstream>

LRUCache::LRUCache(int maxSize) {
	this->maxSize = maxSize;
	size = 0;
	head = tail = nullptr;

	//a hash table of size "maxSize" is sufficient to provide O(1) get and set effiency in the average case.
	hashTable = new HashTable(maxSize);
}

LRUCache::~LRUCache() {
	delete hashTable;

	Node* current = head;
	Node* next = nullptr;
	//sequentially delete all Nodes of the queue starting from the head 
	while (current) {
		next = current->next;
		delete current;
		current = next;
	}
}

void LRUCache::setAsMostRecentlyUsed(Node* node) {
	Node* previous = node->previous;
	Node* next = node->next;

	//if it already isnt the last node (tail)
	if (next) {
		//if it isn't the head
		if (previous) {
			//connect the previous node to the next node
			previous->next = next;
			next->previous = previous;
		}
		else {
			//set a new head
			head = next;
			next->previous = nullptr;
		}

		//connect the node to the tail and set it as the new tail
		tail->next = node;
		node->previous = tail;
		node->next = nullptr;
		tail = node;
	}
}

void LRUCache::enqueue(Node* node) {
	//if the queue is not empty
	if (head) {
		//connect the node to the tail and set it as the new tail
		tail->next = node;
		node->previous = tail;
		tail = node;
	}
	else {
		head = node;
		tail = node;
	}
}

int LRUCache::dequeue() {
	//if the queue is not empty
	if (head) {
		Node* removed = head;
		int key = removed->key;
		//if there is more than one element
		if (head->next) {
			head = head->next;
			head->previous = nullptr;
		}
		else {
			head = tail = nullptr;
		}

		delete removed;
		return key;
	}

	return -1;
}

int LRUCache::get(int key) {
	if (maxSize <= 0)
		return -1;

	if (key <= 0)
		return -1;

	Node* node = hashTable->get(key);
	if (node == nullptr)
		return -1;
	else {
		setAsMostRecentlyUsed(node);
		return node->value;
	}
}


void  LRUCache::set(int key, int newvalue) {
	if (maxSize <= 0)
		return;

	if (key <= 0 || newvalue <= 0)
		return;

	Node* node = hashTable->get(key);
	//if it exists, then update it
	if (node) {
		node->value = newvalue;
		setAsMostRecentlyUsed(node);
	}
	//otherwise create a new Node
	else {

		//if the cache isn't full
		if(size < maxSize)
			size++;
		//otherwise delete the <key,value> pair that wasn't used for the longest time
		else {
			//delete the <key,value> pair from the queue and remove it from the hash table
			int removedKey = dequeue();
			hashTable->remove(removedKey);
		}
		//add the <key,value> pair to the queue and to the hash table
		node = new Node(key, newvalue);
		enqueue(node);
		hashTable->add(key, node);

	}
}

std::string LRUCache::toString() {
	std::stringstream ss;
	Node* current = head;
	while (current) {
		ss << "<" << current->key << ", " << current->value << ">";
		current = current->next;
		if (current)
			ss << ", ";
	}
	ss << "\n";
	return ss.str();
}

int LRUCache::getSize() {
	return size;
}


std::string LRUCache::tableStateString() {
	return hashTable->toString();
}