#include "BinaryTreeLevelOrderTraversal.h"

vector<vector<int>> BinaryTreeLevelOrderTraversal::levelOrder(TreeNode* root) {
	/*第102题：二叉树的层序遍历
	* 1. 递归方法
	*	 这道题是可以用递归方法的，定义一个二维数组result，result.size()与树的深度相同
	*	 可以按照三种方法中的一种进行递归（只要保证先左后右就行），每递归到中时就把这个数push进result[layer]中，由于每一层都放在数组的不同layer（行）中
	*	 因此在递归中我们发现是先将左半棵树全部填进数组后再将右半棵树填进数组的，但是这并没有关系，因为依然保证了数组中每层layer（行）都是从左往右填的，跟是先填哪一层没关系
	* 2. 迭代方法
	*	 用一个队列来放depth深度时每一层的所有node，然后在下一个循环中，一个个pop出来同时更新下一层从左往右对应的node
	*	 由于队列有先进先出的特点，因此pop当前层的一个node同时push进下一层的node不会影响当前层的pop顺序的，因为当前层是在上一个循环就进队列的，会更早出来
	*/

	vector<vector<int>> result;
	queue<TreeNode*> que;//队列存储每层从左往右的node
	if (root == nullptr) return result;

	//处理第一层
	que.push(root);//先将第一层放进队列，因为循环i中完成的事情是pop上一层的值加入result中 并 push进下一层的值

	while (!que.empty()) {//最后一层pop完数据后不会再有下一层的数据被push进来了，因此最后一层结束后que是空队列
		int layerSize = que.size();
		vector<int> layerResult;
		for (int i = 0; i < layerSize; i++) {
			//1. 取出上一层的第i个节点并存入结果
			TreeNode* nodeTemp = que.front();
			layerResult.push_back(nodeTemp->val);
			que.pop();

			//2. 将该节点下一层的值从左往右依次入队列
			if (nodeTemp->left != nullptr) que.push(nodeTemp->left);//该节点下一层的左边节点入队列
			if (nodeTemp->right != nullptr) que.push(nodeTemp->right);//该节点下一层的右边节点入队列
		}
		result.push_back(layerResult);
	}
	return result;
}
