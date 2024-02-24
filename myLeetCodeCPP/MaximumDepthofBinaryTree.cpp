#include "MaximumDepthofBinaryTree.h"

int MaximumDepthofBinaryTree::maxDepth(TreeNode* root) {
	/*��104�⣺��������������
	* ����Ҫ����ȣ���˲��ò�������ķ�������ʣ���Ϊ�����ǰ���˳��һ��һ����ҵ�
	* ���ڲ�������ķ������Կ���һ��102�⣬���ﲻ��׸��
	*/

	if (root == nullptr) return 0;

	queue<TreeNode*> que;
	que.push(root);
	int depth = 0;
	while (!que.empty()) {
		depth++;
		int size = que.size();
		for (int i = 0; i < size; i++) {
			TreeNode* nodeTemp = que.front();
			que.pop();
			if (nodeTemp->left != nullptr) que.push(nodeTemp->left);
			if (nodeTemp->right != nullptr) que.push(nodeTemp->right);
		}
	}
	return depth;
}
