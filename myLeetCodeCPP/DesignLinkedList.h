#pragma once
#include "header.h"
class DesignLinkedList
{
private:
    //1. 设计单链表
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() :val(-1), next(nullptr) {};
        ListNode(int val, ListNode* node) :val(val), next(node) {};
    };
    int _size;
    ListNode* _head;//虚链表头，_head->next才代表第一个节点
public:
    DesignLinkedList() {
        _size = 0;
        _head = new ListNode();
    }

    int get(int index) {
        //首先判断index是否越界了
        if (_size <= index) {//不能相等，因为size比index大1
            return -1;
        }
        ListNode* it = _head;
        for (int i = 0; i <= index; i++) {//index 0 从_head->next开始
            it = it->next;
        }
        return it->val;
    }

    void addAtHead(int val) {
        ListNode* temp = _head->next;
        _head->next = new ListNode(val, temp);

        _size++;
    }

    void addAtTail(int val) {
        //找到Tail（Tail->next == nullptr）
        ListNode* temp = _head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = new ListNode(val, nullptr);
        _size++;
    }

    void addAtIndex(int index, int val) {
        //首先判断index是否越界了
        if (_size < index) {//可以等于，等于就想到与在对位add了
            return;
        }

        ListNode* temp = _head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        //此时temp在index-1的位置，temp->next才是idnex
        ListNode* nodeIndex = new ListNode(val, temp->next);//新节点的next节点是就链表的index位
        temp->next = nodeIndex;//更新新index位的节点
        _size++;
    }

    void deleteAtIndex(int index) {
        //首先判断index是否越界了
        if (_size <= index) {//不能相等，因为size比index大1
            return;
        }

        ListNode* temp = _head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        //此时temp在index-1的位置，temp->next才是idnex
        ListNode* nodeIndex = temp->next;
        temp->next = nodeIndex->next;
        delete nodeIndex;

        _size--;
    }
};

