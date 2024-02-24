#include "MaximumDepthofBinaryTree.h"

int MaximumDepthofBinaryTree::maxDepth(TreeNode* root) {
	/*第104题：二叉树的最大深度
	* 由于要求深度，因此采用层序遍历的方法最合适，因为层序是按照顺序一层一层查找的
	* 关于层序遍历的方法可以看上一题102题，这里不再赘述
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
