#include "ValidateBinarySearchTree.h"

bool ValidateBinarySearchTree::isValidBST(TreeNode* root) {
	/*第98题：验证二叉搜索树
	* 用递归方法遍历整个搜索树，那么改用那种遍历顺序呢？
	* 有效的二叉搜索树在使用中序遍历（左中右）时从坐下往上遍历的过程中应该是递增的
	* 因此用中序遍历的方法从下往上遍历，用一个数组来存储遍历的结果（递归结束后，数组应该是递增的）
	*/
	result.clear();
	backtrack(root);//获得二叉树对应的数组
	for (int i = 0; i < result.size()-1; i++) {
		if (result[i] >= result[i + 1]) {
			//数组必须是递增的，前一个数不应该小于后一个数
			return false;
		}
	}
	return true;
}

void ValidateBinarySearchTree::backtrack(TreeNode* node) {
	if (node == nullptr) return;//遍历到最后一个了

	backtrack(node->left);//左
	result.push_back(node->val);//中
	backtrack(node->right);//右
}
