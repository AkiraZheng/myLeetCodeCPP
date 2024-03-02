#pragma once
#include "header.h"
class MergeTwoBinaryTrees
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        /*第617题:合并二叉树
        * 前序遍历,从上往下找,当root1或root2出现null时,把另一个的剩下节点直接作为拼接的节点返回就行
        */
        return link2Tree(root1, root2);
    }

    TreeNode* link2Tree(TreeNode* root1, TreeNode* root2) {
        //当有一棵树其中一个节点走尽了,就可以将另一棵树作为子节点传给上一层进行拼接
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        //前序遍历
        root1->val += root2->val;//同一节点以root1为最终返回节点
        root1->left = link2Tree(root1->left, root2->left);
        root1->right = link2Tree(root1->right, root2->right);
        return root1;//将当前拼接好的节点返回给上一层
    }
};

