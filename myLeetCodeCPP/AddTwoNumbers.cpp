#include "AddTwoNumbers.h"
ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode first_Node(-1);//该节点的next指向第一个节点
    ListNode* prev = &first_Node;//prev指向first_Node
    int carry = 0;//表示进位
    for (ListNode* pa = l1, *pb = l2;
        pa != nullptr || pb != nullptr;
        pa = pa != nullptr ? pa->next : nullptr,
        pb = pb != nullptr ? pb->next : nullptr,
        prev = prev->next) {//因为pa或pb都有可能是一位数或两位数
        int pa_int = pa != nullptr ? pa->val : 0;
        int pb_int = pb != nullptr ? pb->val : 0;
        int prev_int = (pa_int + pb_int + carry) % 10;//此时prev->next还为null，不能直接给prev->next赋值
        carry = (pa_int + pb_int + carry) / 10;
        prev->next = new ListNode(prev_int);
    }
    //处理最后一位-有可能add后有四位数，需要添加第四位
    if (carry > 0) {
        //存在进位
        prev->next = new ListNode(carry);
    }
    return first_Node.next;
}
