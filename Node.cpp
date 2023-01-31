#pragma once
#include "Node.h"


Node::Node(int key,int value) : value(value), key(key) {
	this->next = this->previous = nullptr;
}

