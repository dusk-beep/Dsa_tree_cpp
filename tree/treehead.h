// Tree.h
#ifndef TREE_H
#define TREE_H

class tree {
public :

	int data;
	tree* left;
	tree* right;

	tree(int val);
};

int maxdepth(tree* root);
bool balancedsubtree(tree* root);
int maxPathSum(tree* root, int& max);

#endif
