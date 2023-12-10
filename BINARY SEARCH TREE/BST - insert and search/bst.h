#include "mybinarytree.h"


class BST {
	BinaryTree* tree = new MyBinaryTree();

	public:
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

	bool insert(int num) {
        if(!tree->getRoot()) {
            tree->addRoot(num);
            return true;
        }
        node* curr = tree->getRoot();
        node* par = NULL;
        while(curr) {
            par = curr;
            if(num < curr->elem) {
                if(!tree->left(curr)) {
                    tree->addLeft(par,num);
                    return true;
                }
                curr = tree->left(curr);
            } else if (num > curr->elem){
                if(!tree->right(curr)) {
                    tree->addRight(par,num);
                    return true;
                }
                curr = tree->right(curr);
            } else {
                return false;
            }
        }
        return false;
	}

    /*
        node* curr = tree->getRoot();
        node* par = NULL;
        while(curr) {
            par = curr;
            if(curr->elem < num) {
                curr = curr->right;
            } else if (curr->elem > num) {
                curr = curr->left;
            } else {
                return false;
            }
        }
    */

    /*
    if(num > node->value) {
        return search(node->right, num);
    }
    */

	void print() {
		tree->print();
	}
};