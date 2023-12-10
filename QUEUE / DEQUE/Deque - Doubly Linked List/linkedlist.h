#include "list.h"
#include "node.h"
#include <iostream>
#include <cmath>
using namespace std;

class LinkedList : public List {
	node *head, *tail;
	int size;

    void addBetween(int num, node* pred, node* succ){
        node* n = (node*) malloc ( sizeof(node));

        n->elem = num;
        n->prev = pred;
        n->next = succ;

        succ->prev = n;
        pred->next = n;

        size++;
    }

    void removeNode(node* n){
     node* pred = n->prev;
     node* succ= n->next;

     pred->next = succ;
     succ->prev = pred;
     free(n);

     size--;
    }

public:

    LinkedList() {
    head = (node*) calloc (1,sizeof(node));
    tail = (node*) calloc (1,sizeof(node));

    head->next = tail;
    tail->prev = head;
    size = 0;

}
    // TODO implement
	void addHead(int num) {
        addBetween(num, head, head->next);
	}

    // TODO implement
	void addTail(int num) {
        addBetween(num, tail->prev, tail);
	}

    // TODO implement
	int removeTail() {
	int tmp = tail->prev->elem;
		removeNode(tail->prev);
		return tmp;
	}

    // TODO implement
	int removeHead() {
    int tmp = head->next->elem;
		removeNode(head->next);
		return tmp;
		//return 0;
	}

    // TODO implement
	int getSize() {
        return size;
	}

	void add(int num) {
		addTail(num);
	}

    int remove(int num) {
        // IGNORE this
        return 0;
	}

    int get(int pos){
        return 0;
    }

    // TODO implement print method
    void print() {
    	node* curr;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
			cout << "From HEAD: ";
            curr = head->next;
            do {
	    		if (curr->next != tail) {
	    			cout << curr->elem << " -> ";
				} else {
					cout << curr->elem << endl;
                    break;
				}
	    		curr = curr->next;
			} while (true);
            // TODO print all elements from first to last, separated by ->
			cout << "From TAIL: ";
            curr = tail->prev;
            do {
	    		if (curr->prev != head) {
	    			cout << curr->elem << " <- ";
				} else {
					cout << curr->elem << endl;
                    break;
				}
	    		curr = curr->prev;
			} while (true);
            // TODO print all elements from last to first, separated by <-
		}
    }
};