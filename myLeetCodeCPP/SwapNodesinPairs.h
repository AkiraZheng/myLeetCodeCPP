#pragma once
#include "header.h"
class SwapNodesinPairs
{
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() :val(-1), next(nullptr) {};
        ListNode(int val, ListNode* node) :val(val), next(node) {};
    };
public:
    ListNode* swapPairs(ListNode* head) {
        return swapTwo(head);
    }

    ListNode* swapTwo(ListNode* node) {
        //��������
        //preָ�µ�ǰ��Ľڵ㣬next��ʾ�µ�pre����Ľڵ㣬next_next��ʾ��һ���ݹ�Ľڵ�
        if (node == nullptr) return nullptr;//����head��������ȫ�յ�����������head=nullptr��

        if (node->next != nullptr && node->next->next != nullptr) {
            ListNode* next_next = node->next->next;
            ListNode* pre = node->next;
            ListNode* next = node;

            //���н���
            pre->next = next;
            next->next = swapTwo(next_next);
            return pre;//���������µ��׽ڵ㷵�أ���Ҫ��Ϊ�˻��ݵ���������ʱ�����head��Ҳ�Ǹ��¸���һ���µ�next
        }
        else if (node->next == nullptr) {
            //���ֻʣһ���ڵ㲻�ý�����
            return node;
        }
        else if (node->next->next == nullptr) {
            //���ֻʣ�����ڵ㣬�������return
            ListNode* next_next = node->next->next;
            ListNode* pre = node->next;
            ListNode* next = node;

            //���н���
            pre->next = next;
            next->next = next_next;
            return pre;
        }
        return nullptr;
    }
};

