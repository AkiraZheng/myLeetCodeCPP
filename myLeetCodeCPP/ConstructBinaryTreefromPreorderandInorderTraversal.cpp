#include "ConstructBinaryTreefromPreorderandInorderTraversal.h"

ConstructBinaryTreefromPreorderandInorderTraversal::TreeNode* ConstructBinaryTreefromPreorderandInorderTraversal::buildTree(vector<int>& preorder, vector<int>& inorder) {
	return traversal(preorder, inorder);
}
ConstructBinaryTreefromPreorderandInorderTraversal::TreeNode* ConstructBinaryTreefromPreorderandInorderTraversal::traversal(vector<int>& preorder, vector<int>& inorder) {
	if (inorder.size() == 0) return nullptr;

	TreeNode* root = new TreeNode(preorder[0]);//preorder用于遍历当前树（子树）的头节点，每次进入下一层遍历前都要erase一下
	int rootIndex_in_inorder;
	for (int i = 0; i < inorder.size(); i++) {
		//当前树中，中序排列的数组会被当前树中的root分为左右子树，因此需要找到中序数组中，preorder[0]值的对应下标
		if (inorder[i] == preorder[0]) {
			rootIndex_in_inorder = i;
			break;
		}
	}

	preorder.erase(preorder.begin());//移除当前的头节点，便于后面递归查找剩下的节点

	vector<int> inorder_left_tree = vector<int>(inorder.begin(), inorder.begin() + rootIndex_in_inorder);//copy 左子树对应中序排序范围内的数组[0,rootIndex_in_inorder)
	vector<int> inorder_right_tree = vector<int>(inorder.begin() + rootIndex_in_inorder + 1, inorder.end());//这里需要加一是因为要抛弃掉当前的root节点，只保留root下左右子树的子节点
	vector<int> preorder_left_tree = vector<int>(preorder.begin(), preorder.begin() + inorder_left_tree.size());//copy 左子树对应前序排序范围内的数组:左闭右开
	vector<int> preorder_right_tree = vector<int>(preorder.begin() + inorder_left_tree.size(), preorder.end());
	//以第一层作为root节点为例，我们需要分别找到左子树和右子树的左右头节点
	//这里inorder的作用：遍历顺序由存储头节点的preorder来决定，而inorder是帮助preorder划分左树和右树的，如果只有preorder我们很难找到左右树的分界点
	//也就是inorder最主要的左右是获取rootIndex_in_inorder，找到左右树的总子节点个数
	root->left = traversal(preorder_left_tree, inorder_left_tree);
	root->right = traversal(preorder_right_tree, inorder_right_tree);
	return root;
}
