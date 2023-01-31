#pragma once
#include "HashTable.h"
#include "Node.h"
#include <string>

//!LRU cache of a limited size, which contains <int,int> (<key,value>) pairs, where key > 0 AND value > 0
/**
* A hash table stores pointers pointing to a Node (that contains the <key,value> pair) in a queue.
*  The queue stores <key,value> pairs from least recently used (head) to most recently used (tail).
*  Get and set functions update a <key,value> pair to be the most recently used.
* The overall implementation is, to some extent, similar to the LRU cache implementation on this site  https://medium.com/@krishankantsinghal/my-first-blog-on-medium-583159139237
*, because we both use a queue implemented as doubly-linked list combined with a hash table to reach average O(1) complexity of get and set methods.
* @see get
*  @see set
* @see Node
*/

class LRUCache {
private:

	int maxSize; //!< The maximum size of the LRUCache
	int size; //!< The current utilized size of the LRUCache
	//! A hash table with int keys and Node values
	HashTable* hashTable;


	//! head represents the <key,value> pair that wasn't used for the longest time
	Node* head;
	//!  tail represents the <key,value> pair that was used the most recently
	Node* tail;

	//! Moves the node to the end of the queue
	void setAsMostRecentlyUsed(Node* node);
	//! Removes the first node from the queue
	/**
	* @return The key of the removed node
	*/
	int dequeue();
	//! Adds the node to the end of the queue
	void enqueue(Node* node);
public:

	LRUCache(int maxSize);

	~LRUCache();

	//! Retrieves the value associated with the given key.
	/**@param key The key whose associated value should be found.
	 *@return The value associated with the key. -1 if the key doesn't exist.
	 */
	int get(int key);

	//! Updates the key value pair with a new value, or creates a new pair if the key doesn't exist.
	/** If a new pair needs to be created and the cache is full, the pair that wasn't used for the longest time will be removed to make space for the new one.
	 *@param key The key whose associated value should be changed.
	 *@param newvalue The value that will be paired with the given key.
	 */
	void set(int key, int newvalue);

	//!Writes the state of the cache into a string
	std::string toString();

	//!Returns the current size of the LRU cache
	int getSize();

	//!Returns a string with length of each list of the underlying hash table 
	std::string tableStateString();
};