#include "IntersectionofTwoLinkedLists.h"

IntersectionofTwoLinkedLists::ListNode* IntersectionofTwoLinkedLists::getIntersectionNode(ListNode* headA, ListNode* headB) {
	/*��160�⣺�ཻ����
	* �����������һ�������ǽϳ����������ǿ�������ǰ�ߣ�ֱ���ߵ����ڶ�������һ����Ϊֹ
	* Ȼ����������ʼ��ͬ����step=1��ǰ�ߣ�������ཻ�Ļ���ô�϶����ߵ�ĳ����������ȵ�
    * ���裺
    * 1. �ȱ����õ���������ĳ���
    * 2. ��p1��size1����ϳ�����Ķ�Ӧ��������p2��size2����ϳ�����Ķ�Ӧ����
    * 3. ���������Ƚ��ϳ�������ǰ�ߣ�֪��size1==siaze2��Ȼ��p1��p2��ͬƵ��ǰ�ߣ������ж��Ƿ���p1==p2
	*/
    if (headA == nullptr || headB == nullptr) return nullptr;
    ListNode* p1 = headA; int head1_size = 1;
    ListNode* p2 = headB; int head2_size = 1;
    while (p1 != nullptr) {//�����õ�A����ĳ���
        head1_size++;
        p1 = p1->next;
    }
    while (p2 != nullptr) {//�����õ�B����ĳ���
        head2_size++;
        p2 = p2->next;
    }
    //���1�洢���������Ϣ�����2�洢�϶��������Ϣ
    if (head1_size >= head2_size) {
        p1 = headA; p2 = headB;
    }
    else {
        p1 = headB; p2 = headA;
        swap(head1_size, head2_size);
    }
    while (p1 != nullptr && p2 != nullptr) {//������nullptr��˵��û�н���
        while (head1_size != head2_size) {
            //���Ľڵ㲻����ǰ��
            p1 = p1->next; head1_size--;
        }
        //������һ������ʼ�ж��Ƿ��ǽ���
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    //û�ҵ�����
    return nullptr;
}
