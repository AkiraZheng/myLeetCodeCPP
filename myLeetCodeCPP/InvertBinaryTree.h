#pragma once
#include "header.h"
class InvertBinaryTree
{
private:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
    TreeNode* invertTree(TreeNode* root) {
        reversalTree(root);
        return root;
    }
    void reversalTree(TreeNode* root) {
        if (root == nullptr) return;

        //前序遍历：从上到下交换左节点和右节点
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        reversalTree(root->left);
        reversalTree(root->right);
    }
};

