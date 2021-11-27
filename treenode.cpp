#include "treenode.h"

TreeNode::~TreeNode() {
	delete left;
	delete right;
}
