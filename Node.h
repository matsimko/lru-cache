#pragma once

//!An element of a queue that is implemented as doubly-linked list (used in LRU cache)
/**
*The idea to use an explicit doubly-linked list as the queue for LRUCache (and hence the structure of this class) was taken from https://medium.com/@krishankantsinghal/my-first-blog-on-medium-583159139237 (class Entry)
* @see LRUCache
*/
class Node {
private:
	int key;
	int value;

	Node* next;  //!<The next Node in the list.
	Node* previous;  //!<The previous Node in the list.
public:
	Node(int key, int value);

	friend class LRUCache;
};