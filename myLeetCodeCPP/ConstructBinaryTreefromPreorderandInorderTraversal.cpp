#include "ConstructBinaryTreefromPreorderandInorderTraversal.h"

ConstructBinaryTreefromPreorderandInorderTraversal::TreeNode* ConstructBinaryTreefromPreorderandInorderTraversal::buildTree(vector<int>& preorder, vector<int>& inorder) {
	return traversal(preorder, inorder);
}
ConstructBinaryTreefromPreorderandInorderTraversal::TreeNode* ConstructBinaryTreefromPreorderandInorderTraversal::traversal(vector<int>& preorder, vector<int>& inorder) {
	if (inorder.size() == 0) return nullptr;

	TreeNode* root = new TreeNode(preorder[0]);//preorder���ڱ�����ǰ������������ͷ�ڵ㣬ÿ�ν�����һ�����ǰ��Ҫeraseһ��
	int rootIndex_in_inorder;
	for (int i = 0; i < inorder.size(); i++) {
		//��ǰ���У��������е�����ᱻ��ǰ���е�root��Ϊ���������������Ҫ�ҵ����������У�preorder[0]ֵ�Ķ�Ӧ�±�
		if (inorder[i] == preorder[0]) {
			rootIndex_in_inorder = i;
			break;
		}
	}

	preorder.erase(preorder.begin());//�Ƴ���ǰ��ͷ�ڵ㣬���ں���ݹ����ʣ�µĽڵ�

	vector<int> inorder_left_tree = vector<int>(inorder.begin(), inorder.begin() + rootIndex_in_inorder);//copy ��������Ӧ��������Χ�ڵ�����[0,rootIndex_in_inorder)
	vector<int> inorder_right_tree = vector<int>(inorder.begin() + rootIndex_in_inorder + 1, inorder.end());//������Ҫ��һ����ΪҪ��������ǰ��root�ڵ㣬ֻ����root�������������ӽڵ�
	vector<int> preorder_left_tree = vector<int>(preorder.begin(), preorder.begin() + inorder_left_tree.size());//copy ��������Ӧǰ������Χ�ڵ�����:����ҿ�
	vector<int> preorder_right_tree = vector<int>(preorder.begin() + inorder_left_tree.size(), preorder.end());
	//�Ե�һ����Ϊroot�ڵ�Ϊ����������Ҫ�ֱ��ҵ���������������������ͷ�ڵ�
	//����inorder�����ã�����˳���ɴ洢ͷ�ڵ��preorder����������inorder�ǰ���preorder���������������ģ����ֻ��preorder���Ǻ����ҵ��������ķֽ��
	//Ҳ����inorder����Ҫ�������ǻ�ȡrootIndex_in_inorder���ҵ������������ӽڵ����
	root->left = traversal(preorder_left_tree, inorder_left_tree);
	root->right = traversal(preorder_right_tree, inorder_right_tree);
	return root;
}
