#ifndef GRAPH_GEN_H
#define GRAPH_GEN_H
#include "treenode.h"
#include <string>

class GraphGenerator {
	public:
		// ctor
		GraphGenerator();

		// accessors
		TreeNode* lookup(int num);
		TreeNode* getRoot();
		void printInOrder();
		void printPreOrder();

		// mutators
		void insertVertex(int num);
		void insertEdge(int num1, int num2);

		// dtor
		~GraphGenerator();

	private:
		// helper routines
		void inOrderHelper(TreeNode* node);
		void preOrderHelper(TreeNode* node);
		static int height(TreeNode* node);
		static int balanceFactor(TreeNode* node);
		static void insertHelper(TreeNode*& root, int num);
		static void balance(TreeNode*& node);
		static void rotateR(TreeNode*& node);
		static void rotateL(TreeNode*& node);
		static void addNeighbor(TreeNode* node, TreeNode* neighbor);

		// data
		TreeNode* root = nullptr;
		std::string printOut;
		
};

#endif
