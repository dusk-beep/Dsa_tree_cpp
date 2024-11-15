#include <iostream>

class tree {
public :

	int data;
	tree* left;
	tree* right;

	tree(int val) {
		data = val;
		left = right = nullptr; }
};
//fuction declarations
int maxdepth(tree* root);
bool balancedsubtree(tree* root);
int maxPathSum(tree* root,int& max);


//nax depth or height of a binary tree
int maxdepth(tree* root) {
	if(root == nullptr)
		return 0;
	return 1 + std::max(maxdepth(root->left),maxdepth(root->right));
}

//check balanced biinary tree
//ie same height on both subtree
bool balancedsubtree(tree* root) {
	if(root == nullptr)
		return 0;

	int leftHeight = balancedsubtree(root->left);
	int rightHeight = balancedsubtree(root->right);

	if(std::abs(leftHeight-rightHeight) > 1)
		return -1;

	return 1+ std::max(leftHeight,rightHeight);
}
int maxPathSum(tree* root,int& max) {
	if(root == nullptr)
		return 0;
	//lf leftSum or rightSum returnib negative dont consider  it make it zero

	int leftSum = maxPathSum(root->left,max);
	int rightSum = maxPathSum(root->right,max);
	int currentSum = root->data + leftSum + rightSum;

	max = std::max(currentSum,max);
	return root->data + std::max(leftSum,rightSum);
}
//main
int main()
{
	//balanced
	tree* root = new tree(1);
	root->left = new tree(2);
	root->left->left = new tree(4);
	root->right = new tree(3);
	root->right->left = new tree(5);
	root->right->right = new tree(6);

	/*
	unbalanced
	tree* root = new tree(1);
	root->left = new tree(2);
	root->right = new tree(3);
	root->right->left = new tree(4);
	root->right->right = new tree(5);
	root->right->right->right = new tree(6);
	*/
	//std::cout<<"max depth : : "<<maxdepth(root);;
	//std::cout<<std::boolalpha<<"balancedsubtree : "<<balancedsubtree(root);

	// int maxi = -1000;
	//maxi is int_min and maxi is pass by refeernece so the  maxPathSum will chnage maxi to the maximjum path summ of the tree
	//maxPathSum(root,maxi);
	//std::cout<<"max path sum" <<maxi;

}
