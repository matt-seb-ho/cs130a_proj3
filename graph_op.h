#ifndef GRAPH_OP_H
#define GRAPH_OP_H
#include "graph_gen.h"

class GraphOperator {
	public:
		GraphOperator(GraphGenerator* g);
		bool isAcyclic();
		void connectedComponents();
		
	private:
		GraphGenerator* gg;
};


#endif
