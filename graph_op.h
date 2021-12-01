#ifndef GRAPH_OP_H
#define GRAPH_OP_H
#include "graph_gen.h"
#include "treenode.h"
#include <unordered_set>

class GraphOperator {
	public:
		// operations
		static bool isAcyclic(GraphGenerator& gg);
		static void connectedComponents(GraphGenerator& gg);
		
	private:
		// helper routines
		static bool hasCycle(TreeNode* node, TreeNode* parent);
		static void labelComponent(TreeNode* node, int label, bool first = 0);

		// applies function to each node in tree (in-order traversal)
		static void forEach(GraphGenerator& gg, void (*&func)(TreeNode* node));
		static void forEach(TreeNode* root, void (*&func)(TreeNode* node));

		// node functions
		static void resetVisited(TreeNode* node);
		static void resetLabel(TreeNode* node);
		static void connectedComponentsHelper(TreeNode* node);
		static int label;
};


#endif
