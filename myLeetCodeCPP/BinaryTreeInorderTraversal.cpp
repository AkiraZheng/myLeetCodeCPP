#include "BinaryTreeInorderTraversal.h"

vector<int> BinaryTreeInorderTraversal::inorderTraversal(TreeNode* root) {
	/*第94题：二叉树的中序遍历
	* 中序遍历就是：左（中）右，也就是中间节点的遍历顺序放在第二个
	* 采用递归方法三部曲：传参、退出条件、单层展开
	* 1. 传参：
	*	 TreeNode* node和vector<int>& result
	* 2. 退出条件
	*	 当递归到某个点值是nullptr就return，说明结束了，也就是 node == nullptr
	* 3. 单层展开
	*	 递归函数中的（中）指的就是当前层的node，那么按照中序遍历顺序展开就是左中右：
	*	 backtrack(node->left)	再result.push_back(node->val)	最后再backtrack(node->right)
	*/
	vector<int> result;
	backtrack(root, result);
	return result;
}

void BinaryTreeInorderTraversal::backtrack(TreeNode* node, vector<int>& result) {
	if (node == nullptr) return;
	backtrack(node->left, result);//左
	result.push_back(node->val);//中
	backtrack(node->right, result);//右
}
