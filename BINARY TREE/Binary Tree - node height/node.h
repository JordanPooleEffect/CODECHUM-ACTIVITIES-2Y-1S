#include <algorithm>
using namespace std;

struct node {
	int elem;
	node* left;
	node* right;
	node* parent;

    // TODO implement this method
    int height() {
        if(left == nullptr && right == nullptr) {
            return NULL;
        } else {
            int Hleft = 0; // left->height();
            int Hright = 0; // right->height();

        if(left != nullptr) {
            Hleft = left->height();
        }
        if(right != nullptr) {
            Hright = right->height();
            }


        return 1 + max(Hleft, Hright);
        }
    }
};

/*
if(parent == nullptr) {
            return 0;
        }
        return 1 + parent->depth();

*/

/*
node* root = (node*) calloc (1, sizeof(node));
        if (root == NULL)
            return 0;
        else {

        int left_height = height(root->left);
        int right_height = height(root->right);


        return height(left_height, right_height) + 1;
        }
*/