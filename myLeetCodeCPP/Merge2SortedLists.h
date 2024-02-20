#pragma once
#include "header.h"
class Merge2SortedLists
{
private:
static struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    static void test_Merge2SortedLists();
};

