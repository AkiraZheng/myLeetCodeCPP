#pragma once
#include "header.h"
class PalindromeLinkedList
{
private:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
	ListNode* new_head;
public:
    bool isPalindrome(ListNode* head) {
        /*����1�������鱣�棬ʱ�临�Ӷȸ�*/
        //202ms--127.62MB, 27.29%-- 19.20%
        // vector<int> nodeList;
        // ListNode* temp = head;
        // while(temp!=nullptr){
        //     nodeList.push_back(temp->val);
        //     temp = temp->next;
        // }
        // int backIndex = nodeList.size()-1;
        // for(int i = 0; i<nodeList.size()/2; i++){
        //     if(nodeList[i]!=nodeList[backIndex])return false;
        //     backIndex--;
        // }
        // return true;

        /*���������ÿ���ָ���ҵ��м�ڵ㣬Ȼ��ת��������*/
        //150ms--116.12MB, 92.87%-- 63.71%
        if (head->next == nullptr) return true;//ֻ��һ���ڵ�
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //������slow�����м�ڵ�
        backtrack(slow->next);
        ListNode* back_p = new_head;
        ListNode* front_p = head;
        while (back_p != nullptr) {
            if (front_p->val != back_p->val) return false;
            back_p = back_p->next;
            front_p = front_p->next;
        }
        return true;
    }
    ListNode* backtrack(ListNode* node) {
        //��ת����
        if (node->next == nullptr) {//�ҵ����һ���ڵ��ˣ����Կ�ʼ����
            new_head = node;//���һ���ڵ��Ϊ�µ�ͷ�ڵ�
            return node;
        }
        //��ǰ�ڵ����һ���ڵ���Ƿ�ת��ǰ1�ڵ����һ���ڵ�
        ListNode* p_rev_before = backtrack(node->next);
        p_rev_before->next = node;
        node->next = nullptr;
        return node;
    }
};

