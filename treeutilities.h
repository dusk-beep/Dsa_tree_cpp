#ifndef TREE_UTILITIES
#define TREE_UTILITIES

#include "treehead.h"
#include <string>

void readTree(tree* ptr);
void printCompactTree(tree* root, const std::string& prefix = "", bool isLeft = true);

#endif

