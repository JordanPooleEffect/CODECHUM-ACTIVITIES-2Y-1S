#include "mybinarytree.h"

class BST {
	MyBinaryTree* tree = new MyBinaryTree();

	public:
    // TODO copy and paste from previous activity
	bool search(int num) {
        node* curr = tree->getRoot();
        while(curr) {
            if(num == curr->elem) {
                return true;
            } else if (num < curr->elem) {
                curr = tree->left(curr);
            } else {
                curr = tree->right(curr);
            }
        }
        return false;
	}

    void from_preorder(int* array, int size) {
        tree->size = size;
        tree->root = convert_preorder(array, 0, size-1, NULL);
    }

    // TODO convert_preorder recursively
    node* convert_preorder(int* array, int start, int end, node* parent) {
        if(start > end) {
            return nullptr;
        }
        node* current = (node*)calloc(1, sizeof(node));
        current->elem = array[start];
        current->parent = parent;

        int beg = start + 1;
        for(; beg <= end && array[start] > array[beg]; beg++) {
            // note to self: this can also be translated as....
            // while(beg <= end && array[start] > array[beg]) beg++;
        }
        
        current->left = convert_preorder(array, start + 1, beg - 1, current);
        current->right = convert_preorder(array, beg, end, current);
        
        return current;

        // I had to change the fields to public para mu run ang code hehe
    }

	void print() {
		tree->print();
	}
};