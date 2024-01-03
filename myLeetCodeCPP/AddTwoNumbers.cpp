#include "AddTwoNumbers.h"
ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode first_Node(-1);//�ýڵ��nextָ���һ���ڵ�
    ListNode* prev = &first_Node;//prevָ��first_Node
    int carry = 0;//��ʾ��λ
    for (ListNode* pa = l1, *pb = l2;
        pa != nullptr || pb != nullptr;
        pa = pa != nullptr ? pa->next : nullptr,
        pb = pb != nullptr ? pb->next : nullptr,
        prev = prev->next) {//��Ϊpa��pb���п�����һλ������λ��
        int pa_int = pa != nullptr ? pa->val : 0;
        int pb_int = pb != nullptr ? pb->val : 0;
        int prev_int = (pa_int + pb_int + carry) % 10;//��ʱprev->next��Ϊnull������ֱ�Ӹ�prev->next��ֵ
        carry = (pa_int + pb_int + carry) / 10;
        prev->next = new ListNode(prev_int);
    }
    //�������һλ-�п���add������λ������Ҫ��ӵ���λ
    if (carry > 0) {
        //���ڽ�λ
        prev->next = new ListNode(carry);
    }
    return first_Node.next;
}
