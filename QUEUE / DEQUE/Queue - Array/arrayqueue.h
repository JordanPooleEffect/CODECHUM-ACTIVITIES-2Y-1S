// TODO implement the class ArrayQueue here
// by inheriting the Queue class

#include <iostream>
#include <cstdlib>
#include "arraylist.h"
#include "queue.h"
using namespace std;

class ArrayQueue : public Queue {
    ArrayList* list = new ArrayList();

public:
    void enqueue(int num) {
        return list->add(num);
    }
	int dequeue() {
        if (!isEmpty()) {
			return list->removeFirst();
		}
		// cout << "WA LAGI SULOD" << endl;
		return 0;
    }
	int first() {
        if (!isEmpty()) {
			return list->get(1);
		}
		// cout << "WA LAGI SULOD" << endl;
		return 0;
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