#include "SymmetricTree.h"

bool SymmetricTree::isSymmetric(TreeNode* root) {
	/*第101题：对称二叉树
	* 1. 单层展开
	* 要判断二叉树是否具有对称性，也就是以root节点为中心切割成两个树，在递归中每次判断对称的两个点是否相等
	* 那么左右相当于两棵树，要有相反的遍历顺序（左边的半树按先左后右的顺序遍历，右边的半颗树按先右后左的顺序遍历），这样才能保证对称点的比较
	* 从树最低端的节点来看，每个子节点（中节点）都是一个return的点，因此中的顺序放在最后，而三种遍历方式中只有后序遍历（左右中）具有这种特点
	* 左边的半树按先左后右的顺序遍历，右边的半颗树按先右后左的顺序遍历，因此左半树按照 左右中 的遍历顺序，右半树按照 右左中的遍历顺序一一比对(从外往里中间遍历)
	* 2. 退出条件（返回比对结果）
	*	 left == nullptr && right == nullptr 两个都为空也是相等，但是这里相等后不能继续回溯的了，因此return true
	*	 left == nullptr || right == nullptr 结果上一个条件的判断后，这里就只有一个结果为空，不匹配，因此返回false
	*	 left.val != right.val 不一样了，return false
	*/
	return (root == nullptr) ? true : compare(root->left, root->right);
}
bool SymmetricTree::compare(TreeNode* left, TreeNode* right) {//left永远是左半树的对应节点，right永远是右半边树的对应节点
	if (left == nullptr && right == nullptr) return true;
	if (left == nullptr || right == nullptr) return false;
	if (left->val != right->val) return false;

	//筛选完才是左右对称相等，可以继续递归比较
	//左半边树的递归顺序：左右中；右半边树的递归顺序：右左中
	bool outside = compare(left->left, right->right);//左半边树先 左；右半边先 右
	bool inside  = compare(left->right, right->left);//左半边树后 右；右半边后 左
	return outside && inside;//中：中间节点返回比较结果
}
