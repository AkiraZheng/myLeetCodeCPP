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
        /*�����ཻ
        * �ȸ���ѭ����������������Ե��ܳ��ȣ�x��y
        * ����yΪ�ϳ����Ǹ�����(y>x)����ô���������غϵ��ѭ���У��ϳ�����������(y-x)����Ȼ����ͬ���ߣ�����ֻҪ�н��㣬һ��������
        */
        //1. ������������ĳ���
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
        //2. �ҵ��ϳ�������y
        if (x > y) {//A��������y
            swap(x, y);
            tempx = headB; tempy = headA;
        }
        else {
            tempx = headA; tempy = headB;
        }
        //3. ��������y-x��
        int first = y - x;
        while (first--) {
            tempy = tempy->next;
        }
        //4. ͬ���ߣ�����ͬ��
        while (tempx != nullptr) {
            if (tempx == tempy) return tempx;//�ҵ���ͬ��
            tempx = tempx->next;
            tempy = tempy->next;
        }
        return nullptr;
    }
};

