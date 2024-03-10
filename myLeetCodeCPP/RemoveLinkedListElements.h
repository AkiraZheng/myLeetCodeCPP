#pragma once
#include "header.h"
class RemoveLinkedListElements
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
    ListNode* removeElements(ListNode* head, int val) {
        //1. 删除头节点:找到第一个不为val的作为新的头节点
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;//清空内存才是真正的删除
        }

        //删除头节点往后等于val的节点
        ListNode* it = head;
        while (it != nullptr) {
            while (it->next != nullptr && it->next->val == val) {
                ListNode* temp = it->next;
                it->next = temp->next;
                delete temp;
            }
            it = it->next;
        }
        return head;
    }
};

