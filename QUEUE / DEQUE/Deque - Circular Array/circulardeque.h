// ALREADY IMPLEMENTED
// Go to arraylist.h's methods being called here.

#include <iostream>
#include "arraylist.h"
#include "deque.h"
using namespace std;

class CircularDeque : public Deque {
    ArrayList* list;
public:
    CircularDeque() {
        list = new ArrayList();
    }
	void addLast(int num) {
		list->addLast(num);
	}
	void addFirst(int num) {
		list->addFirst(num);
	}

	int removeFirst() {
		if (isEmpty()) {
			return 0;
		}
		return list->removeFirst();
	}

	int removeLast() {
		if (isEmpty()) {
			return 0;
		}
		return list->removeLast();
	}

	int size() {
		return list->_size();
	}

	bool isEmpty() {
		return size() == 0;
	}

	void print() {
		list->print();
	}
};