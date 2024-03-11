#pragma once
#include "header.h"
class IntersectionofTwoLinkedListsLCCI
{
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() :val(-1), next(nullptr) {};
        ListNode(int val, ListNode* node) :val(val), next(node) {};
    };
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        /*链表相交
        * 先各自循环两个链表，计算各自的总长度，x和y
        * 假设y为较长的那个链表(y>x)，那么在下面找重合点的循环中，较长的链表先走(y-x)步，然后再同步走，这样只要有交点，一定会相遇
        */
        //1. 计算两个链表的长度
        int x = 0, y = 0;
        ListNode* tempx = headA;
        ListNode* tempy = headB;
        while (tempx != nullptr) {
            tempx = tempx->next;
            x++;
        }
        while (tempy != nullptr) {
            tempy = tempy->next;
            y++;
        }
        //2. 找到较长的链表当y
        if (x > y) {//A链表长，当y
            swap(x, y);
            tempx = headB; tempy = headA;
        }
        else {
            tempx = headA; tempy = headB;
        }
        //3. 长表先走y-x步
        int first = y - x;
        while (first--) {
            tempy = tempy->next;
        }
        //4. 同步走，找相同点
        while (tempx != nullptr) {
            if (tempx == tempy) return tempx;//找到相同点
            tempx = tempx->next;
            tempy = tempy->next;
        }
        return nullptr;
    }
};

