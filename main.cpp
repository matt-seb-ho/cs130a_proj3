#include <iostream>
#include "graph_gen.h"

int main() {
	GraphGenerator gg;
	gg.insertVertex(3);
	gg.insertVertex(2);
	gg.insertVertex(1);
	gg.printInOrder();
	gg.printPreOrder();

	// std::cout << "hello world" << std::endl;
	return 0;
}
