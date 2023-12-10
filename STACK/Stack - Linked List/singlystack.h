#include "stack.h"
#include "linkedlist.h"

class SinglyStack : public Stack {
    LinkedList* list;

    public:
    SinglyStack() {
        list = new LinkedList();
    }

    void push (int num) {
        list->addHead(num);
    }

    int pop() {
        if(isEmpty()) {
            return 0;
        }
        return list->removeHead();
    }

    int top() {
        if(isEmpty()) {
            return 0;
        }
        return list->getHead();
    }

    int size() {
        return list->_size();
    }

    bool isEmpty() {
        return list->_size() == 0;
    }

    void print() {
        list->print();
    }
};  