#include "FlattenBinaryTreetoLinkedList.h"

void FlattenBinaryTreetoLinkedList::flatten(TreeNode* root) {
	/*第114题：二叉树展开为链表
	* 不用递归的方法，而是不断地循环将左边的树插入到右边的树中（图解看word）
	*/
	while (root) {
		if(root->left) {
			TreeNode* tempLetf = root->left;
			//先将当前root的左边树最右边的最下面那个节点找到，方便后面最左边的枝与当前root的右树拼接
			while (tempLetf->right) {//当存在右枝时就不断循环
				tempLetf = tempLetf->right;
			}
			//拼接
			tempLetf->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}
		//破解完后更新下一个root继续拼接
		root = root->right;
	}
}
void FlattenBinaryTreetoLinkedList::traversal(TreeNode* root) {
	
}
