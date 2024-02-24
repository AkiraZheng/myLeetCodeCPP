#pragma once
#include "header.h"
class SymmetricTree
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
	bool isSymmetric(TreeNode* root);
	bool compare(TreeNode* left, TreeNode* right);
};

