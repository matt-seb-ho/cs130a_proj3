#include "treenode.h"
#include "graph_gen.h"
#include "graph_op.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

void readInput(GraphGenerator& gg, std::string fname) {
	std::ifstream in(fname);
	if (in.fail()) {
		throw std::runtime_error("file open failed\n");
	}
	std::string line;
	std::stringstream ss;
	int x, y;
	int counter = 0;
	while (std::getline(in, line)) {
		line += ',';
		ss.str(line);
		std::getline(ss, line, ',');
		x = stoi(line);
		std::getline(ss, line, ',');
		y = stoi(line);
		// std::cout << "x, y: " << x << ", " << y << "\n";
		gg.insertEdge(x, y);
		// gg.printPreOrder();
		counter++;
		
	}
	in.close();
}
	
int main(int argc,  char* argv[]) {
	if (argc != 2) {
		throw std::invalid_argument("requires cmdline arg: input filename\n");
	}

	GraphGenerator gg;
	readInput(gg, argv[1]);
	
	gg.printInOrder();
	gg.printPreOrder();
	std::cout << GraphOperator::isAcyclic(gg) << std::endl;
	GraphOperator::connectedComponents(gg); 

	/*
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
	*/


	// std::cout << "hello world" << std::endl;
	return 0;
}
