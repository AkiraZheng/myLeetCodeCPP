#include "IntersectionofTwoLinkedLists.h"

IntersectionofTwoLinkedLists::ListNode* IntersectionofTwoLinkedLists::getIntersectionNode(ListNode* headA, ListNode* headB) {
	/*第160题：相交链表
	* 如果两个链表不一样长，那较长的链表我们可以先往前走，直到走到跟第二个链表一样长为止
	* 然后两个链表开始以同样的step=1向前走，如果有相交的话那么肯定会走到某个点两个相等的
    * 步骤：
    * 1. 先遍历得到两个链表的长度
    * 2. 用p1和size1来存较长链表的对应参数；用p2和size2来存较长链表的对应参数
    * 3. 遍历链表，先将较长链表往前走，知道size1==siaze2；然后p1和p2再同频向前走，不断判断是否有p1==p2
	*/
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode* p1 = headA; int head1_size = 1;
    ListNode* p2 = headB; int head2_size = 1;
    while (p1 != nullptr) {//遍历得到A链表的长度
        head1_size++;
        p1 = p1->next;
    }
    while (p2 != nullptr) {//遍历得到B链表的长度
        head2_size++;
        p2 = p2->next;
    }
    //序号1存储长链表的信息，序号2存储较短链表的信息
    if (head1_size >= head2_size) {
        p1 = headA; p2 = headB;
    }
    else {
        p1 = headB; p2 = headA;
        swap(head1_size, head2_size);
    }
    while (p1 != nullptr && p2 != nullptr) {//当出现nullptr就说明没有交点
        while (head1_size != head2_size) {
            //长的节点不断往前走
            p1 = p1->next; head1_size--;
        }
        //两个点一样长后开始判断是否是交点
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    //没找到交点
    return nullptr;
}
