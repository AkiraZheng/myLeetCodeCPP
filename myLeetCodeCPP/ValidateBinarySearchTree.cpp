#include "ValidateBinarySearchTree.h"

bool ValidateBinarySearchTree::isValidBST(TreeNode* root) {
	/*��98�⣺��֤����������
	* �õݹ鷽��������������������ô�������ֱ���˳���أ�
	* ��Ч�Ķ�����������ʹ����������������ң�ʱ���������ϱ����Ĺ�����Ӧ���ǵ�����
	* �������������ķ����������ϱ�������һ���������洢�����Ľ�����ݹ����������Ӧ���ǵ����ģ�
	*/
	result.clear();
	backtrack(root);//��ö�������Ӧ������
	for (int i = 0; i < result.size()-1; i++) {
		if (result[i] >= result[i + 1]) {
			//��������ǵ����ģ�ǰһ������Ӧ��С�ں�һ����
			return false;
		}
	}
	return true;
}

void ValidateBinarySearchTree::backtrack(TreeNode* node) {
	if (node == nullptr) return;//���������һ����

	backtrack(node->left);//��
	result.push_back(node->val);//��
	backtrack(node->right);//��
}
