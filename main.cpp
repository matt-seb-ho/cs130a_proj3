#include "treenode.h"
#include "graph_gen.h"
#include "graph_op.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

void readInput(GraphGenerator& gg, std::string fname) {
	std::ifstream in(fname);
	if (in.fail()) {
		throw std::runtime_error("file open failed\n");
	}
	std::string line;
	int x, y, commaIndex;
	while (std::getline(in, line)) {
		commaIndex = line.find(",");
		x = stoi(line.substr(0, commaIndex));
		y = stoi(line.substr(commaIndex + 1));
		gg.insertEdge(x, y);

		// debugging
		// std::cout << "x, y: " << x << ", " << y << "\n";
		// gg.printPreOrder();
	}
	in.close();
}
	
int main(int argc,  char* argv[]) {
	if (argc != 2) {
		throw std::invalid_argument("requires cmdline arg: input filename\n");
	}

	GraphGenerator gg;
	readInput(gg, argv[1]);
	
	std::cout << "The in order traversal:\n";
	gg.printInOrder();

	std::cout << "The pre order traversal:\n";
	gg.printPreOrder();

	std::cout << "Is acyclic(Yes/No):\n";
	std::cout << (GraphOperator::isAcyclic(gg) ? "Yes\n" : "No\n");

	std::cout << "Connected Components:\n";
	GraphOperator::connectedComponents(gg); 

	return 0;
}
