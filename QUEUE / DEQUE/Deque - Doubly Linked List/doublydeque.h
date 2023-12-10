// TODO implement
#include <iostream>
#include "deque.h"
#include "linkedlist.h"

class DoublyDeque : public Deque {
    LinkedList* list;
public:
    DoublyDeque() {
        list = new LinkedList();
    }

    void addFirst(int num) {
        list->addHead(num);
    }

    void addLast(int num) {
        list->addTail(num);
    }

    int removeFirst()  {
    	return list->removeHead();
    }
    int removeLast(){
    	return list->removeTail();
    }

    int size(){
    	return list->getSize();
    }

    bool isEmpty() {
    	return size() == 0;
    }

    void print() {
    	list->print();
	}
};