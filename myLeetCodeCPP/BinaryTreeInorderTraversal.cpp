#include "BinaryTreeInorderTraversal.h"

vector<int> BinaryTreeInorderTraversal::inorderTraversal(TreeNode* root) {
	/*��94�⣺���������������
	* ����������ǣ����У��ң�Ҳ�����м�ڵ�ı���˳����ڵڶ���
	* ���õݹ鷽�������������Ρ��˳�����������չ��
	* 1. ���Σ�
	*	 TreeNode* node��vector<int>& result
	* 2. �˳�����
	*	 ���ݹ鵽ĳ����ֵ��nullptr��return��˵�������ˣ�Ҳ���� node == nullptr
	* 3. ����չ��
	*	 �ݹ麯���еģ��У�ָ�ľ��ǵ�ǰ���node����ô�����������˳��չ�����������ң�
	*	 backtrack(node->left)	��result.push_back(node->val)	�����backtrack(node->right)
	*/
	vector<int> result;
	backtrack(root, result);
	return result;
}

void BinaryTreeInorderTraversal::backtrack(TreeNode* node, vector<int>& result) {
	if (node == nullptr) return;
	backtrack(node->left, result);//��
	result.push_back(node->val);//��
	backtrack(node->right, result);//��
}
