#pragma once
#include "header.h"
class DiameterofBinaryTree
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
	int maxDepth;//记录更新遍历到的最长路径(边数)
public:
    int diameterOfBinaryTree(TreeNode* root) {
        /*第543题:二叉树的直径
        * 这道题其实跟前面124题:二叉树中的最大路径和 类似,这里的边数其实就是最大路径节点数-1
        * 要注意树中任意节点都可能作为最大路径的根节点(递归到的当前层就是根节点)
        * 所以要递归当前层作为根节点时,左孩子和右孩子分别的最大路径;
        * 而且除了根节点可以选左右孩子的和作为最大路径外,其它节点都只能选左或右其中一条较长路径,否则会导致路径不唯一(word有图)
        *       因此retrun当前层选择的路径到上一个节点时,只能选择max(l,r)
        *       因为当前层返回到上一层就不是根节点了,只能选择一个方向返回
        */
        maxDepth = 0;
        maxDepthBFS(root);
        return maxDepth;
    }

    int maxDepthBFS(TreeNode* root) {
        if (root == nullptr) return 0;
        //以当前root为根节点,分别搜索包含左节点/右节点的最长路径
        int l = maxDepthBFS(root->left);
        int r = maxDepthBFS(root->right);
        maxDepth = max(maxDepth, l + r);
        return max(l + 1, r + 1);//返回与当前根节点连接后的路径,需要加一条新连接的边
    }
};

