#ifndef TREENODE_H
#define TREENODE_H
#include "linkedlist.h"

struct TreeNode {
	// vertex number, AVL tree height, component label, visited status
	int num;
	int height = 1;
	int label = -1;
	bool visited = false;

	// tree pointers
	TreeNode* parent = nullptr;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	// graph neighbors
	ListNode* neighbors = nullptr;

	~TreeNode() {
		delete neighbors;
		delete left;
		delete right;
	}
};

#endif
