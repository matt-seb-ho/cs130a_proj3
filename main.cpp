#include "treenode.h"
#include "graph_gen.h"
#include "graph_op.h"
#include <fstream>
#include <iostream>

int main() {
	GraphGenerator gg;
	gg.insertVertex(3);
	gg.insertVertex(2);
	gg.insertVertex(1);
	gg.insertEdge(1, 2);
	std::cout << "connected components, 1 edge:\n";
	GraphOperator::connectedComponents(gg);
	std::cout << "----\n";
	gg.insertEdge(2, 3);
	gg.insertEdge(1, 3);
	std::cout << "in order: ";
	gg.printInOrder();
	std::cout << "pre order: ";
	gg.printPreOrder();

	std::cout << GraphOperator::isAcyclic(gg) << std::endl;
	std::cout << "connected components, 3 edges:\n";
	GraphOperator::connectedComponents(gg);
	std::cout << "----\n";


	// std::cout << "hello world" << std::endl;
	return 0;
}
