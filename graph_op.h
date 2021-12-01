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

		// functors (passed to forEach)
		struct NodeFunctor {
			virtual void operator()(TreeNode* node);
		};
		struct ResetVisited : public NodeFunctor {
			void operator()(TreeNode* node) override;
		};
		struct ResetLabel : public NodeFunctor {
			void operator()(TreeNode* node) override;
		};
		struct LabelComponentHelper : public NodeFunctor {
			int label = 0;
			void operator()(TreeNode* node) override;
		};
		static void forEach(GraphGenerator& gg, NodeFunctor* func);
		static void forEach(TreeNode* root, NodeFunctor* func);
};


#endif
