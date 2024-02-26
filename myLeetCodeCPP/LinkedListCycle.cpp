#include "LinkedListCycle.h"

bool LinkedListCycle::hasCycle(ListNode* head) {
	/*��141�⣺��������
	* 1. ����ж��Ƿ��л���
	*	 ���ÿ���ָ�뷽������fastָ��һ����2����slowָ��һ����1��
	*	 ���û�л��Ļ�����ô�ߵ��������nullptr�Ϳ��Է���false�ˣ�������л��Ļ�����ô����ָ������һ�����ڻ�������������ֻҪ�ж��Ƿ���fast==slow������Ϳ���֪���Ƿ��л���
	* 2. ���ȷ��������ڽڵ��أ����������ʵ����Ҫ�жϣ����ǿ����˽�һ�£�
	*	 ����л��Ļ�����ôfast�Ƚ��뻷�ڣ���slow���뻷��fast��ʼ׷��slow�����ߵ�����ٶ���fast��slow��1
	*	 ���slow�ڻ�������һȦ����ôfast�Ѿ�������2Ȧ�ˣ�����fastһ������slow�뻷���һȦ��׷��slow(Ҳ���ǵ���������ʱ��slow�϶���û�߹�һȦ)
	*	 ��ô����head�뻷����ھ�����x����ھ���fast��slow�����ĵ�˳ʱ�����Ϊy(Ҳ����slow�ڻ�������y)�������ĵ������˳ʱ�뻹��z��Ҳ����slow����z������һȦ��
	*	 2.1 ������ڽڵ��λ��
	*		 ��fast��slow����ǰ��fast�����Ѿ��ڻ�����nȦ�ˣ�Ҳ�����Ѿ�����n(y+z)��
	*		 a. slow�ܹ��ߵľ��� len_slow = x+y
	*		 b. fast�ܹ��ߵľ��� len_fast = x + n(y+z) + y
	*		 ����fast�ٶ���slow�������������len_fast = 2*len_slow,�򻯺���x+y=n(y+z)
	*		 �����������Ҫ�����x����������Ȱ�������ȫ�����ڵ�ʽ�ұߣ�x=n(y+z)-y
	*		 c.���һ���������� x=(n-1)(y+z)+z ,�����ʽ�����ǾͿ��Կ������ˣ���������������һ��index1׼����ǰ�ߣ���fast��slow�����ĵ��һ��index2�ڻ�����Ȧ������step1��ǰ��
	*		   index1�ߵ�ʽ��ߵ�x��		   ��ô��index1�߹�����ʽx��������ڵ��(index1����x��)
	*		   index2�ߵ�ʽ�ұߵ�(n-1)(y+z)+z����ʱ���ǵ�index2����������ڻ�ʣz�ľ��룬������z�󵽴ﻷ��ڵ������n-1Ȧ�϶���ǡ����index1��Ȧ��ʱ������������������ʱ�����ĵ������ڵ�(index2����(n-1)(y+z)+z��)
	*/
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != nullptr && fast->next != nullptr) {
		//��ָ��������
		fast = fast->next->next;
		//��ָ����һ��
		slow = slow->next;
		if (fast == slow) {
			//�л������ˣ�����ֱ��return
			return true;
		}
	}
	return false;
}

LinkedListCycle::ListNode* LinkedListCycle::detectCycle(ListNode* head) {
	/*��142�⣺��������II
	* �ο�141�⻷�����������˼·����
	*/
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast!=nullptr && fast->next!=nullptr)
	{
		fast = fast->next->next;//��ָ��������
		slow = slow->next;//��ָ����1��
		if (fast == slow) {
			//�ڻ���������
			//1. һ���ڵ�index1��head��ʼ�ߣ��ٶ�Ϊ1
			ListNode* index1 = head;
			//2. ��һ���ڵ�index2�ӿ����ڵ������ĵط���ʼ�ߣ��ٶ�Ϊ1
			ListNode* index2 = fast;
			//3. �����ڵ���ڽ��㴦����
			while (index1 != index2) {
				index1 = index1->next;
				index2 = index2->next;
			}
			return index1;
		}
	}
	return nullptr;
}