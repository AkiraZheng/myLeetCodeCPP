#include "MergekSortedLists.h"

MergekSortedLists::ListNode* MergekSortedLists::mergeKLists(vector<ListNode*>& lists) {
	/*第23题：合并k个升序链表
	* 复用第21题的合并两个有序链表，将链表进行循环两两合并
	*/
	if (lists.size() == 0)return nullptr;
	ListNode* p = lists[0];//取出第一个链表的指针
	for (int i = 1; i < lists.size(); i++) {
		p = mergeTwoLists(p, lists[i]);
	}
	return p;

}

MergekSortedLists::ListNode* MergekSortedLists::mergeTwoLists(ListNode* list1, ListNode* list2) {
	/*第21题：合并两个有序链表
	* 直接新建一个链表作为result，遍历两个链表逐个比较，将其按顺序放在新链表中
	*/

	ListNode result(-1);//新链表从下一个指针开始
	ListNode* p = &result;//用于新链表添加元素
	for (; list1 != nullptr && list2 != nullptr; p = p->next) {
		if (list1->val > list2->val) {
			p->next = list2;
			list2 = list2->next;//因为list1当前位的值跟list2下一位的值大小还不知道，因此还不能将list1更新进新链表
		}
		else {
			p->next = list1;
			list1 = list1->next;
		}
	}
	p->next = (list1 != nullptr) ? list1 : list2;//list1和list2总有一个链表被遍历完了

	return result.next;
}
