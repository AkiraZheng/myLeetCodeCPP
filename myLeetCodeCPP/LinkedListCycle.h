#pragma once
class LinkedListCycle
{
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(nullptr) {}
	};
	bool hasCycle(ListNode* head);
};

