#include "SortList.h"

SortList::ListNode* SortList::sortList(ListNode* head) {
	/*��148�⣺��������
	* ������򵥵ķ��������б��е�valһ��һ��ȡ�������������У���sort�����������һ�����Ż������ʱ�临�Ӷ���O(n)�����װ�Ҫ����O(nlgn)
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
	ListNode* temp_p = head;//ָ��headָ��
	for (int i : nums) {
		temp_p->val = i;
		temp_p = temp_p->next;
	}
	return head;
}
