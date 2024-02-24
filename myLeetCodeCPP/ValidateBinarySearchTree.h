#pragma once
#include "header.h"
class ValidateBinarySearchTree
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
	vector<int> result;
	bool isValidBST(TreeNode* root);
	void backtrack(TreeNode* node);
};

