#include "FlattenBinaryTreetoLinkedList.h"

void FlattenBinaryTreetoLinkedList::flatten(TreeNode* root) {
	/*��114�⣺������չ��Ϊ����
	* ���õݹ�ķ��������ǲ��ϵ�ѭ������ߵ������뵽�ұߵ����У�ͼ�⿴word��
	*/
	while (root) {
		if(root->left) {
			TreeNode* tempLetf = root->left;
			//�Ƚ���ǰroot����������ұߵ��������Ǹ��ڵ��ҵ��������������ߵ�֦�뵱ǰroot������ƴ��
			while (tempLetf->right) {//��������֦ʱ�Ͳ���ѭ��
				tempLetf = tempLetf->right;
			}
			//ƴ��
			tempLetf->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}
		//�ƽ���������һ��root����ƴ��
		root = root->right;
	}
}
void FlattenBinaryTreetoLinkedList::traversal(TreeNode* root) {
	
}
