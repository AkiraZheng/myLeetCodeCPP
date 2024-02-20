#pragma once
#include "header.h"
class MergekSortedLists
{
private:
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
public:
	ListNode* mergeKLists(vector<ListNode*>& lists);
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};

