#pragma once
#include "header.h"
class RemoveNthNode
{
public:
	static struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
public:
	ListNode* removeNthFromEnd(ListNode* head, int n);
};

