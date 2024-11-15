// treehaed.cpp
#include "treehead.h"
#include <iostream>

tree::tree(int value)
{
	data = value;
	left = right = nullptr;
}

int maxdepth(tree* root)
{
	if(root == nullptr)
		return 0;

	return 1 + std::max(maxdepth(root->left), maxdepth(root->right));
}

bool balancedsubtree(tree* root)
{
	if(root == nullptr)
		return 0;

	int leftHeight = balancedsubtree(root->left);
	int rightHeight = balancedsubtree(root->right);

	if(std::abs(leftHeight - rightHeight) > 1)
		return -1;

	return 1 + std::max(leftHeight, rightHeight);
}

int maxPathSum(tree* root, int& max)
{
	if(root == nullptr)
		return 0;

	//lf leftSum or rightSum returnib negative dont consider  it make it zero

	int leftSum = maxPathSum(root->left, max);
	int rightSum = maxPathSum(root->right, max);
	int currentSum = root->data + leftSum + rightSum;

	max = std::max(currentSum, max);
	return root->data + std::max(leftSum, rightSum);
}
