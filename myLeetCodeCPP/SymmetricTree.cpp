#include "SymmetricTree.h"

bool SymmetricTree::isSymmetric(TreeNode* root) {
	/*��101�⣺�Գƶ�����
	* 1. ����չ��
	* Ҫ�ж϶������Ƿ���жԳ��ԣ�Ҳ������root�ڵ�Ϊ�����и�����������ڵݹ���ÿ���ж϶ԳƵ��������Ƿ����
	* ��ô�����൱����������Ҫ���෴�ı���˳����ߵİ�����������ҵ�˳��������ұߵİ���������Һ����˳����������������ܱ�֤�ԳƵ�ıȽ�
	* ������Ͷ˵Ľڵ�������ÿ���ӽڵ㣨�нڵ㣩����һ��return�ĵ㣬����е�˳�������󣬶����ֱ�����ʽ��ֻ�к�������������У����������ص�
	* ��ߵİ�����������ҵ�˳��������ұߵİ���������Һ����˳������������������� ������ �ı���˳���Ұ������� �����еı���˳��һһ�ȶ�(���������м����)
	* 2. �˳����������رȶԽ����
	*	 left == nullptr && right == nullptr ������Ϊ��Ҳ����ȣ�����������Ⱥ��ܼ������ݵ��ˣ����return true
	*	 left == nullptr || right == nullptr �����һ���������жϺ������ֻ��һ�����Ϊ�գ���ƥ�䣬��˷���false
	*	 left.val != right.val ��һ���ˣ�return false
	*/
	return (root == nullptr) ? true : compare(root->left, root->right);
}
bool SymmetricTree::compare(TreeNode* left, TreeNode* right) {//left��Զ��������Ķ�Ӧ�ڵ㣬right��Զ���Ұ�����Ķ�Ӧ�ڵ�
	if (left == nullptr && right == nullptr) return true;
	if (left == nullptr || right == nullptr) return false;
	if (left->val != right->val) return false;

	//ɸѡ��������ҶԳ���ȣ����Լ����ݹ�Ƚ�
	//�������ĵݹ�˳�������У��Ұ�����ĵݹ�˳��������
	bool outside = compare(left->left, right->right);//�������� ���Ұ���� ��
	bool inside  = compare(left->right, right->left);//�������� �ң��Ұ�ߺ� ��
	return outside && inside;//�У��м�ڵ㷵�رȽϽ��
}
