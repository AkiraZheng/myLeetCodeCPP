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

        //ǰ����������ϵ��½�����ڵ���ҽڵ�
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        reversalTree(root->left);
        reversalTree(root->right);
    }
};

