struct node {
	int elem;
	node* left;
	node* right;
	node* parent;

    // TODO implement this method
    int depth() {
        if(parent == nullptr) {
            return 0;
        }
        return 1 + parent->depth();
    }
};

/*
if(parent == root) {
    return 0;
} else {
    return depth(parent + 1);
}

/*

        if (node == NULL)
            return 0;
        else {

        int lDepth = depth(left->elem);
        int rDepth = depth(right->elem);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
        }
        return 0;
*/