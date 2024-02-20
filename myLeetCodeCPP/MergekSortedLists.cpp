#include "MergekSortedLists.h"

MergekSortedLists::ListNode* MergekSortedLists::mergeKLists(vector<ListNode*>& lists) {
	/*��23�⣺�ϲ�k����������
	* ���õ�21��ĺϲ����������������������ѭ�������ϲ�
	*/
	if (lists.size() == 0)return nullptr;
	ListNode* p = lists[0];//ȡ����һ�������ָ��
	for (int i = 1; i < lists.size(); i++) {
		p = mergeTwoLists(p, lists[i]);
	}
	return p;

}

MergekSortedLists::ListNode* MergekSortedLists::mergeTwoLists(ListNode* list1, ListNode* list2) {
	/*��21�⣺�ϲ�������������
	* ֱ���½�һ��������Ϊresult������������������Ƚϣ����䰴˳�������������
	*/

	ListNode result(-1);//���������һ��ָ�뿪ʼ
	ListNode* p = &result;//�������������Ԫ��
	for (; list1 != nullptr && list2 != nullptr; p = p->next) {
		if (list1->val > list2->val) {
			p->next = list2;
			list2 = list2->next;//��Ϊlist1��ǰλ��ֵ��list2��һλ��ֵ��С����֪������˻����ܽ�list1���½�������
		}
		else {
			p->next = list1;
			list1 = list1->next;
		}
	}
	p->next = (list1 != nullptr) ? list1 : list2;//list1��list2����һ��������������

	return result.next;
}
