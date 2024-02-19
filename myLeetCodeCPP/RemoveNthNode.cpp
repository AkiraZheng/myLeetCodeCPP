#include "RemoveNthNode.h"

RemoveNthNode::ListNode* RemoveNthNode::removeNthFromEnd(ListNode* head, int n) {
	/*����˫ָ��
	* 1. ָ��fontNode����ǰ�棬����n��
	* 2. ָ��backNode���ں��棬��fontNode����n��������fontNodeһ����
	* 3. ��fontNode->next==nullptr��ɾ��backNode->next����
	* 4. ��󷵻�firstNode->next
	*/
	ListNode firstNode(-1, head);//ָ��ͷ��ַ�����ﲻֱ��ָ��headӦ����Ϊ�˷�ֹ�׵�ַҲ��ɾ��
	ListNode* fontNode = &firstNode;//����n��
	ListNode* backNode = &firstNode;//����

	//1. fontNode����n��
	for (int i = 0; i < n; i++) fontNode = fontNode->next;
	//2. fontNode��backNode�벽��
	while (fontNode->next != nullptr) {
		fontNode = fontNode->next;
		backNode = backNode->next;
	}
	//3. ��fontNode->next==nullptr��ɾ��backNode->next����
	ListNode* temp = backNode->next;//�������ͨ��delete����ɾ���ýڵ����ڴ�ռ�ķ���
	backNode->next = backNode->next->next;
	delete temp;
	return firstNode.next;
}
