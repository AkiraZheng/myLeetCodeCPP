#include "SortList.h"

SortList::ListNode* SortList::sortList(ListNode* head) {
	/*第148题：排序链表
	* 采用最简单的方法，将列表中的val一个一个取出来放在数组中，用sort排序数组后再一个个放回链表里，时间复杂度是O(n)，进阶版要求是O(nlgn)
	*/
	vector<int> nums;
	for (ListNode* p = head; p != nullptr; p = p->next) {
		nums.push_back(p->val);
	}
	if (nums.size() != 0) {
		sort(nums.begin(), nums.end());
	}
	else {
		return nullptr;
	}
	ListNode* temp_p = head;//指向head指针
	for (int i : nums) {
		temp_p->val = i;
		temp_p = temp_p->next;
	}
	return head;
}
