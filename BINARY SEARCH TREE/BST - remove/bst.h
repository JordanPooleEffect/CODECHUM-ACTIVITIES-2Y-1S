#include "mybinarytree.h"

class BST {
	BinaryTree* tree = new MyBinaryTree();

	public:
	bool search(int num) {
		return search_node(tree->getRoot(), num);
	}

	bool search_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return true;
		}
		if (num > n->elem) {
			return search_node(n->right, num);
		} else {
			return search_node(n->left, num);
		}
	}

	bool insert(int num) {
		node* n = tree->getRoot();
		if (n == NULL) {
			tree->addRoot(num);
		}
		return insert_node(n, num);
	}

	bool insert_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return false;
		}
		if (num > n->elem) {
			if (!n->right) {
				tree->addRight(n, num);
				return true;
			} else {
				return insert_node(n->right, num);
			}
		} else {
			if (!n->left) {
				tree->addLeft(n, num);
				return true;
			} else {
				return insert_node(n->left, num);
			}
		}
	}
    // DO not modify the lines above.

    node* mostLeft(node* n) {
        while(n->left) {
            n = n->left;
        }
        return n;
    }

    // TODO implement remove method
    // You can add helper methods like what is done for insert and search
    bool remove(int num) {
         /*   node* curr = tree->getRoot();
        while(curr) {
            node* par = NULL;
            if(!tree->getRoot()) {
                return false;
            }
            node* returner;
            if(num < curr->elem) {
                tree->remove(par);
            } else if(num > curr->elem) {
                tree->remove(par);
            } else if(curr->left && curr->right) {
                node* minNode = mostLeft(par);
                curr->elem = minNode->elem;
                curr->right = remove(minNode->elem);
                return true;
            } else if(curr->left) {
                returner = curr->left;
                delete curr;
                return returner;
            } else if(curr->right) {
                returner = curr->right;
                delete curr;
                return returner;
            } else {
                delete curr;
                return NULL;
            }
            return true;
        }
        return curr;
        return false; */
// -----------------------------------------------------------------
        node* curr = tree->getRoot();
        if(!tree->getRoot()) {
            return false;
        }
        while(curr) {
            if(curr->elem < num) {
                curr = curr->right;
            } else if (curr->elem > num) {
                curr = curr->left;
            } else {
                break;
            }
        }
        if(!curr) {
            return false;
        }
        if(curr->left && curr->right) {
            node* rs = curr->right;
            while(rs->left) {
                rs = rs->left;
            }
            curr->elem = rs->elem;
            curr = NULL;
            tree->remove(rs);
            return true;
        } else {
            tree->remove(curr);
            return true;
        }
    }

	void print() {
		tree->print();
	}
};