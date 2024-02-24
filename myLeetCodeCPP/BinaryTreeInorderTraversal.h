#pragma once
#include "header.h"
class BinaryTreeInorderTraversal
{
private:
	vector<int> result;
public:
	struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		int val;
		TreeNode() :val(0), left(nullptr), right(nullptr) {};//默认构造函数
		TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};//构造函数
		TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {};//构造函数
	};
	vector<int> inorderTraversal(TreeNode* root);
	void backtrack(TreeNode* node, vector<int>& result);
};

