#pragma once
#include "header.h"
class DesignLinkedList
{
private:
    //1. ��Ƶ�����
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() :val(-1), next(nullptr) {};
        ListNode(int val, ListNode* node) :val(val), next(node) {};
    };
    int _size;
    ListNode* _head;//������ͷ��_head->next�Ŵ����һ���ڵ�
public:
    DesignLinkedList() {
        _size = 0;
        _head = new ListNode();
    }

    int get(int index) {
        //�����ж�index�Ƿ�Խ����
        if (_size <= index) {//������ȣ���Ϊsize��index��1
            return -1;
        }
        ListNode* it = _head;
        for (int i = 0; i <= index; i++) {//index 0 ��_head->next��ʼ
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
        //�ҵ�Tail��Tail->next == nullptr��
        ListNode* temp = _head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = new ListNode(val, nullptr);
        _size++;
    }

    void addAtIndex(int index, int val) {
        //�����ж�index�Ƿ�Խ����
        if (_size < index) {//���Ե��ڣ����ھ��뵽���ڶ�λadd��
            return;
        }

        ListNode* temp = _head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        //��ʱtemp��index-1��λ�ã�temp->next����idnex
        ListNode* nodeIndex = new ListNode(val, temp->next);//�½ڵ��next�ڵ��Ǿ������indexλ
        temp->next = nodeIndex;//������indexλ�Ľڵ�
        _size++;
    }

    void deleteAtIndex(int index) {
        //�����ж�index�Ƿ�Խ����
        if (_size <= index) {//������ȣ���Ϊsize��index��1
            return;
        }

        ListNode* temp = _head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        //��ʱtemp��index-1��λ�ã�temp->next����idnex
        ListNode* nodeIndex = temp->next;
        temp->next = nodeIndex->next;
        delete nodeIndex;

        _size--;
    }
};

