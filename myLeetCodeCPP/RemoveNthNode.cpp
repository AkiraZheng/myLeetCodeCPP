#include "RemoveNthNode.h"

RemoveNthNode::ListNode* RemoveNthNode::removeNthFromEnd(ListNode* head, int n) {
	/*采用双指针
	* 1. 指针fontNode走在前面，先走n步
	* 2. 指针backNode走在后面，当fontNode走完n步后再与fontNode一起走
	* 3. 当fontNode->next==nullptr后，删掉backNode->next即可
	* 4. 最后返回firstNode->next
	*/
	ListNode firstNode(-1, head);//指向头地址，这里不直接指向head应该是为了防止首地址也被删除
	ListNode* fontNode = &firstNode;//先走n步
	ListNode* backNode = &firstNode;//后走

	//1. fontNode先走n步
	for (int i = 0; i < n; i++) fontNode = fontNode->next;
	//2. fontNode和backNode齐步走
	while (fontNode->next != nullptr) {
		fontNode = fontNode->next;
		backNode = backNode->next;
	}
	//3. 当fontNode->next==nullptr后，删掉backNode->next即可
	ListNode* temp = backNode->next;//用于最后通过delete彻底删除该节点在内存空间的分配
	backNode->next = backNode->next->next;
	delete temp;
	return firstNode.next;
}
