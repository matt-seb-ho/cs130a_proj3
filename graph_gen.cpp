#include "graph_gen.h"
#include <iostream>

// ctor
GraphGenerator::GraphGenerator() {}

// accessors 
TreeNode* GraphGenerator::lookup(int num) {
	TreeNode* node = root;
	while (node) {
		if (num == node->num) {
			return node;
		} 
		if (num < node->num) {
			node = node->left;
		} else {
			node = node->right;
		}
	}
	return node;
}

TreeNode* GraphGenerator::getRoot() {
	return root;
}

void GraphGenerator::printInOrder() {
	if (root) {
		printOut = "";
		inOrderHelper(root);
		std::cout << printOut.substr(0, printOut.size() - 1);
		printOut = "";
	}
	std::cout << std::endl;
}

void GraphGenerator::printPreOrder() {
	if (root) {
		printOut = "";
		preOrderHelper(root);
		std::cout << printOut.substr(0, printOut.size() - 1);
		printOut = "";
	}
	std::cout << std::endl;
}

// mutators
void GraphGenerator::insertVertex(int num) {
	if (lookup(num)) {
		return;
	}
	insertHelper(root, num);
}

void GraphGenerator::insertHelper(TreeNode*& root, int num) {
	// standard BST insert
	if (!root) {
		root = new TreeNode();
		root->num = num;
	} else if (num < root->num) {
		insertHelper(root->left, num);
	} else {
		insertHelper(root->right, num);
	}
	
	// re-balance to maintain AVL invariant + update heights
	balance(root);
}

void GraphGenerator::balance(TreeNode*& node) {
	// check if node is null
	if (!node) {
		return;
	}

	// fix balance invariant
	if (balanceFactor(node) < -1) {
		// left heavy
		if (height(node->left->left) > height(node->left->right)) {
			rotateR(node);
		} else {
			rotateL(node->left);
			rotateR(node);
		}
	} else if (balanceFactor(node) > 1) {
		// right heavy
		if (height(node->right->right) > height(node->right->left)) {
			rotateL(node);
		} else {
			rotateR(node->right);
			rotateL(node);
		}
	}

	// update height
	node->height = std::max(height(node->left), height(node->right)) + 1;
}

void GraphGenerator::insertEdge(int num1, int num2) {
	TreeNode* node1 = lookup(num1);
	if (!node1) {
		insertVertex(num1);
		node1 = lookup(num1);
	}
	TreeNode* node2 = lookup(num2);
	if (!node2) {
		insertVertex(num2);
		node2 = lookup(num2);
	}
	
	addNeighbor(node1, node2);
	addNeighbor(node2, node1);
	// node1->neighbors.push_back(node2);
	// node2->neighbors.push_back(node1);
}

GraphGenerator::~GraphGenerator() {
	delete root;
}

// helper routines
void GraphGenerator::inOrderHelper(TreeNode* node) {
	if (node->left) {
		inOrderHelper(node->left);
	}
	printOut += std::to_string(node->num);
	printOut += " ";
	if (node->right) {
		inOrderHelper(node->right);
	}
}

void GraphGenerator::preOrderHelper(TreeNode* node) {
	printOut += std::to_string(node->num);
	printOut += " ";
	if (node->left) {
		preOrderHelper(node->left);
	}
	if (node->right) {
		preOrderHelper(node->right);
	}
}

int GraphGenerator::height(TreeNode* node) {
	if (node) {
		return node->height;
	}
	return 0;
}

int GraphGenerator::balanceFactor(TreeNode* node) {
	return height(node->right) - height(node->left);
}

void GraphGenerator::rotateR(TreeNode*& node) {
	// rearrange pointers
	TreeNode* temp = node;
	node = node->left;
	temp->left = node->right;
	node->right = temp;

	// update heights
	temp->height = std::max(height(temp->left), height(temp->right)) + 1;
	node->height = std::max(height(node->left), height(node->right)) + 1;
}

void GraphGenerator::rotateL(TreeNode*& node) {
	// rearrange pointers
	TreeNode* temp = node;
	node = node->right;
	temp->right = node->left;
	node->left = temp;

	// update heights
	temp->height = std::max(height(temp->left), height(temp->right)) + 1;
	node->height = std::max(height(node->left), height(node->right)) + 1;
}

void GraphGenerator::addNeighbor(TreeNode* node, TreeNode* neighbor) {
	// special case for empty adjacency list
	if (!node->neighbors) {
		node->neighbors = new ListNode();
		node->neighbors->vertex = neighbor;
		return;
	}
	ListNode* neighborList = node->neighbors;
	while (neighborList->next) {
		if (neighborList->vertex == neighbor) {
			// adjacency list already contains this vertex
			return;
		}
		neighborList = neighborList->next;
	}
	neighborList->next = new ListNode();
	neighborList->next->vertex = neighbor;
}
