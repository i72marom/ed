#include <iostream>

#include "avltree.hpp"

int main() {
	AVLTree<int> tree;
	tree.insert(10);
	tree.insert(11);
	tree.insert(8);
	tree.insert(7);
	tree.insert(2);
	tree.insert(15);

	std::cout << tree.root()->item() << std::endl;
}
