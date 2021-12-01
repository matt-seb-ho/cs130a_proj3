#include "graph_op.h"
#include <iostream>
#include <queue>

// --------------------
// operations
// --------------------
bool GraphOperator::isAcyclic(GraphGenerator& gg) {
	// clear all node visited flags
	ResetVisited rv;
	forEach(gg, &rv);
	
	// bfs through tree to check each component for cycles
	TreeNode* curr;
	std::queue<TreeNode*> q;
	q.push(gg.getRoot());
	while (!q.empty()) {
		// get next node
		curr = q.front();
		q.pop();
		
		// check unvisited node for cycles
		if (!curr->visited && hasCycle(curr, nullptr)) {
			return false;
		}
		
		// enqueue children
		if (curr->left) {
			q.push(curr->left);
		}
		if (curr->right) {
			q.push(curr->right);
		}
	}
	return true;
}

void GraphOperator::connectedComponents(GraphGenerator& gg) {
	// clear all node labels
	ResetLabel rl;
	forEach(gg, &rl);

	// iterate through nodes, labeling unlabeled nodes
	LabelComponentHelper lch;
	forEach(gg, &lch);
}

// --------------------
// helper routines
// --------------------

// an undirected graph has a cycle if dfs finds a back edge 
bool GraphOperator::hasCycle(TreeNode* node, TreeNode* parent) {
	// mark visited
	node->visited = true;

	// move on to neighbors
	for (TreeNode* neighbor : node->neighbors) {
		// skip parent, since tree edge != back edge
		if (neighbor != parent) {
			if (neighbor->visited) {
				// back edge found
				return true;
			} else {
				// recurse
				if (hasCycle(neighbor, node)) {
					return true;
				}
			}
		}
	}
	return false;
}

void GraphOperator::labelComponent(TreeNode* node, int label, bool first) {
	// mark node
	node->label = label;
	
	// only print space if not first
	std::cout << (first ? "" : " ") << node->num;

	// recurse for unlabeled neighbors
	for (TreeNode* neighbor : node->neighbors) {
		if (neighbor->label == -1) {
			labelComponent(neighbor, label);
		}
	}
}

void GraphOperator::NodeFunctor::operator()(TreeNode* node) {
	return;
}

void GraphOperator::ResetVisited::operator()(TreeNode* node) {
	node->visited = false;
}

void GraphOperator::ResetLabel::operator()(TreeNode* node) {
	node->label = -1;
}

void GraphOperator::LabelComponentHelper::operator()(TreeNode* node) {
	if (node->label == -1) {
		labelComponent(node, label++, true);
		std::cout << '\n';
	}
}

void GraphOperator::forEach(GraphGenerator& gg, NodeFunctor* func) {
	if (gg.getRoot()) {	
		forEach(gg.getRoot(), func);
	}
}

void GraphOperator::forEach(TreeNode* root, NodeFunctor* func) {
	if (root->left)
		forEach(root->left, func);
	(*func)(root);
	if (root->right)
		forEach(root->right, func);
}

