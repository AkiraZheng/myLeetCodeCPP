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
        //1. ɾ��ͷ�ڵ�:�ҵ���һ����Ϊval����Ϊ�µ�ͷ�ڵ�
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;//����ڴ����������ɾ��
        }

        //ɾ��ͷ�ڵ��������val�Ľڵ�
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

