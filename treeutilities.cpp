#ifndef TREE_UTILITIES
#define TREE_UTILITIES

#include "treehead.h"
#include <iostream>

void readTree(tree* ptr)
{
	int data, choice;

	// Read the data for the current node
	std::cout << "Enter data for this node: ";
	std::cin >> ptr->data;

	// Read if there is a left child
	std::cout << "Enter left child for " << ptr->data << " (-1 for no child): ";
	std::cin >> choice;

	if (choice != -1) {
		ptr->left = new tree(choice); // Create left child node with user input value
		readTree(ptr->left);            // Recursively read left subtree
	}

	// Read if there is a right child
	std::cout << "Enter right child for " << ptr->data << " (-1 for no child): ";
	std::cin >> choice;

	if (choice != -1) {
		ptr->right = new tree(choice); // Create right child node with user input value
		readTree(ptr->right);            // Recursively read right subtree
	}
}

void printCompactTree(tree* root, const std::string& prefix, bool isLeft)
{
	if (root == nullptr) return;

	std::cout << prefix;
	std::cout << (isLeft ? "├── " : "└── ");
	std::cout << root->data << std::endl;

	// Recursively print the left and right subtrees
	std::string leftPrefix = prefix + (isLeft ? "│   " : "    ");
	std::string rightPrefix = prefix + (isLeft ? "│   " : "    ");

	printCompactTree(root->left, leftPrefix, true);
	printCompactTree(root->right, rightPrefix, false);
}

#endif
