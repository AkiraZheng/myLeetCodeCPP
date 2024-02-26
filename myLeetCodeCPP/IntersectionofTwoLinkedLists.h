#pragma once
#include "header.h"
class IntersectionofTwoLinkedLists
{
public:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
};

