#include "Element.h"

Element::Element(int key, Node* value) {
	this->key = key;
	this->value = value;
	this->next = nullptr;
}
