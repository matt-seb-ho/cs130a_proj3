#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// forward declaration
struct TreeNode;

struct ListNode {
	TreeNode* vertex = nullptr;
	ListNode* next = nullptr;
	~ListNode() {
		delete next;
	}
};

#endif
