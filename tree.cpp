#include "treehead.h"
#include "treeutilities.h"

#include <iostream>

//main
int main()
{
	tree* root = new tree(0);
	readTree(root);

	std::cout << std::endl;
	std::cout << std::endl;
	printCompactTree(root);
}

