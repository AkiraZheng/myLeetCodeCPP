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
        //两两交换
        //pre指新的前面的节点，next表示新的pre后面的节点，next_next表示下一个递归的节点
        if (node == nullptr) return nullptr;//处理head本来就是全空的链表的情况（head=nullptr）

        if (node->next != nullptr && node->next->next != nullptr) {
            ListNode* next_next = node->next->next;
            ListNode* pre = node->next;
            ListNode* next = node;

            //进行交换
            pre->next = next;
            next->next = swapTwo(next_next);
            return pre;//将交换后新的首节点返回，主要是为了回溯到主函数的时候更新head，也是更新给上一层新的next
        }
        else if (node->next == nullptr) {
            //最后只剩一个节点不用交换了
            return node;
        }
        else if (node->next->next == nullptr) {
            //最后只剩两个节点，交换完就return
            ListNode* next_next = node->next->next;
            ListNode* pre = node->next;
            ListNode* next = node;

            //进行交换
            pre->next = next;
            next->next = next_next;
            return pre;
        }
        return nullptr;
    }
};

