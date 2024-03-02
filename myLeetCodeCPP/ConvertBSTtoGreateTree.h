#pragma once
#include "header.h"
class ConvertBSTtoGreateTree
{
private:
	int pre;
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
    TreeNode* convertBST(TreeNode* root) {
        /*第538题:把二叉搜索树转换成累加树
        * 完全二叉树我们通过中序遍历可以从数值最小的节点->数值最大的节点遍历.
        * 而本题当前节点需要比node大的所有节点的总和,所以我们要想办法能先遍历到大数的累计和,再把值和传给下一个比node小的数
        * 也就是需要维护一个int pre值作为当前node前面大数的累计和
        * 那么有什么办法可以实现从大数到小数遍历呢?
        *    中序遍历从小到大,那么反中序遍历就是从大到小,所以这里需要 右中左遍历
        */
        pre = 0;
        bfs(root);
        return root;
    }
    void bfs(TreeNode* node) {
        if (node == nullptr) return;

        //反中序遍历
        bfs(node->right);//右
        node->val += pre;//中
        pre = node->val;//中
        bfs(node->left);//右
    }
};

