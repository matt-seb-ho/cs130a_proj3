#include "graph_op.h"
#include "treenode.h"

GraphOperator::GraphOperator(GraphGenerator* g)
		: gg(g) {}
	
bool dfs(TreeNode* node) {
	// mark visited
	node->label = 1;
	for (TreeNode* neighbor : node->neighbors) {
		if (neighbor->label == 1) {
			return true;
		} else {
			if (dfs(neighbor)) {
				return true;
			}
		}
	}
	return false;
}
	
bool GraphOperator::isAcyclic() {
	


