#pragma once
#include "header.h"
class BinaryTreeMaximumPathSum
{
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	int maxResult;
	int maxPathSum(TreeNode* root);
	int dfs(TreeNode* root);//返回经过root节点的最大路径和
};

