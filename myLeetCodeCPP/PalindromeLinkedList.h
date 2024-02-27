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
        /*方法1：用数组保存，时间复杂度高*/
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

        /*方法二：用快慢指针找到中间节点，然后反转后半段链表*/
        //150ms--116.12MB, 92.87%-- 63.71%
        if (head->next == nullptr) return true;//只有一个节点
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //遍历后slow就是中间节点
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
        //反转链表
        if (node->next == nullptr) {//找到最后一个节点了，可以开始回溯
            new_head = node;//最后一个节点变为新的头节点
            return node;
        }
        //当前节点的下一个节点就是反转后当前1节点的上一个节点
        ListNode* p_rev_before = backtrack(node->next);
        p_rev_before->next = node;
        node->next = nullptr;
        return node;
    }
};

