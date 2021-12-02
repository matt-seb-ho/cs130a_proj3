#ifndef GRAPH_OP_H
#define GRAPH_OP_H
#include "graph_gen.h"
#include "treenode.h"
#include <string>

class GraphOperator {
	public:
		// operations
		static bool isAcyclic(GraphGenerator& gg);
		static void connectedComponents(GraphGenerator& gg);
		
	private:
		// helper routines
		static bool hasCycle(TreeNode* node, TreeNode* parent);
		static void labelComponent(TreeNode* node, int label);

		// applies function to each node in tree (in-order traversal)
		static void forEach(GraphGenerator& gg, void (*&func)(TreeNode* node));
		static void forEach(TreeNode* root, void (*&func)(TreeNode* node));

		// node functions
		static void resetVisited(TreeNode* node);
		static void resetLabel(TreeNode* node);
		static void labelComponent(TreeNode* node);
		static void addToComponentArray(TreeNode* node);

		// static members to track current component number & print-outs
		static int label;
		static std::string* components;
};


#endif
