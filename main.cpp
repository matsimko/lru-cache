#include <iostream>
#include <ctime>
#include "LRUCache.h"


int main() {
	srand(time(nullptr));

	LRUCache lru(5);
	for (int i = 1; i <= 5;i++) {
		lru.set(i, i + 1);
		std::cout << lru.toString();
		if (i % 2 == 0) {
			std::cout << "get: value = " << lru.get(i - 1) << std::endl;
			std::cout << lru.toString();
		}
	}

	std::cout << "table state: " << lru.tableStateString();

	std::cout << "get: value = " << lru.get(1) << std::endl;
	std::cout << lru.toString();
	lru.set(2, 20);
	std::cout << lru.toString();
	lru.set(10, 11);
	std::cout << lru.toString();
	lru.set(11, 12);
	std::cout << lru.toString();
	std::cout << "get: value = " << lru.get(2) << std::endl;
	std::cout << lru.toString();
	lru.set(10, 110);
	std::cout << lru.toString();
	lru.set(1, 20);
	std::cout << lru.toString();
	lru.set(5, 60);
	std::cout << lru.toString();

	std::cout << "table state: " << lru.tableStateString();



	std::cout << std::endl;
	LRUCache lru2(1000);
	for (int i = 0; i < 1000; i++) {
		lru2.set(rand(), rand());
	}
	std::cout << lru2.getSize() << std::endl;
	std::cout << "table state: " << lru2.tableStateString();

	lru2.get(rand() % 1000);
	lru2.set(rand() % 1000, rand() % 1000);
	std::cout << lru2.getSize() << std::endl;

	for (int i = 0; i < 1000; i++) {
		lru2.get(rand());
	}

	std::cout << lru2.getSize() << std::endl;
	for (int i = 0; i < 1000; i++) {
		lru2.set(rand() % 1500, rand() % 1500);
	}
	std::cout << lru2.getSize() << std::endl;
	std::cout << "table state: " << lru2.tableStateString();

	std::cout << std::endl;
	LRUCache lru3(1);
	lru3.set(1, 10);
	std::cout << lru3.toString();
	std::cout << "get: value = " << lru3.get(1) << std::endl;
	std::cout << lru3.toString();
	lru3.set(2, 20);
	std::cout << lru3.toString();
	std::cout << "get: value = " << lru3.get(1) << std::endl;
	std::cout << lru3.toString();
	std::cout << "get: value = " << lru3.get(2) << std::endl;
	std::cout << lru3.toString();

	return 0;

}