#ifndef TREENODE_H
#define TREENODE_H
#include <vector>

struct TreeNode {
	// vertex number
	int num;

	// height
	int height = 1;

	// tree pointers
	TreeNode* parent = nullptr;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;

	// graph neighbors
	std::vector<TreeNode*> neighbors;

	~TreeNode();
};

#endif
