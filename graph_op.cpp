#include "graph_op.h"
#include <iostream>
#include <queue>

// initialize static members
int GraphOperator::label = 0;
std::string* GraphOperator::components = nullptr;

// --------------------
// operations
// --------------------
bool GraphOperator::isAcyclic(GraphGenerator& gg) {
	// clear all node visited flags
	auto resetVisitedPtr = &resetVisited;
	forEach(gg, resetVisitedPtr);
	
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
	auto resetLabelPtr = &resetLabel;
	forEach(gg, resetLabelPtr);

	// iterate through nodes, labeling unlabeled nodes
	label = 0;
	void (*labelComponentPtr)(TreeNode* node) = &labelComponent;
	forEach(gg, labelComponentPtr);

	// build sorted string for each component
	components = new std::string[label];
	auto addToComponentsArrPtr = &addToComponentArray;
	forEach(gg, addToComponentsArrPtr);

	// print components and clean up
	for (int i = 0; i < label; i++) {
		std::cout << components[i] << std::endl;
	}

	delete [] components;
	components = nullptr;
}

// --------------------
// helper routines
// --------------------

// an undirected graph has a cycle if dfs finds a back edge 
bool GraphOperator::hasCycle(TreeNode* node, TreeNode* parent) {
	// mark visited
	node->visited = true;

	// move on to neighbors
	ListNode* neighborList = node->neighbors;
	TreeNode* neighbor;
	while (neighborList) {
		neighbor = neighborList->vertex;
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
		neighborList = neighborList->next;
	}
	return false;
}

void GraphOperator::labelComponent(TreeNode* node, int label) {
	// mark node
	node->label = label;

	// recurse for unlabeled neighbors
	ListNode* neighborList = node->neighbors;
	TreeNode* neighbor;
	while (neighborList) {
		neighbor = neighborList->vertex;
		if (neighbor->label == -1) {
			labelComponent(neighbor, label);
		}
		neighborList = neighborList->next;
	}
}

void GraphOperator::forEach(GraphGenerator& gg, void (*&func)(TreeNode* node)) {
	if (gg.getRoot()) {	
		forEach(gg.getRoot(), func);
	}
}

void GraphOperator::forEach(TreeNode* root, void (*&func)(TreeNode* node)) {
	if (root->left)
		forEach(root->left, func);
	func(root);
	if (root->right)
		forEach(root->right, func);
}

void GraphOperator::resetVisited(TreeNode* node) {
	node->visited = false;
}

void GraphOperator::resetLabel(TreeNode* node) {
	node->label = -1;
}

// version callable with forEach
void GraphOperator::labelComponent(TreeNode* node) {
	if (node->label == -1) {
		labelComponent(node, GraphOperator::label++);
	}
}

void GraphOperator::addToComponentArray(TreeNode* node) {
	std::string& component = components[node->label];
	if (component != "") {
		component += " ";
	}
	component += std::to_string(node->num);
}
