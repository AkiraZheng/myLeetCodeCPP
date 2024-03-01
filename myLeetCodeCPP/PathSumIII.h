#pragma once
#include "header.h"
class PathSumIII
{
private:
	int count = 0;
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
public:
    int pathSum(TreeNode* root, long targetSum) {
        if (root == nullptr) return count;
        /*第437题:路径总和III
        * bfs递归数组中找到以root为根节点的枝干是否存在和为targetSum 的枝干
        * 但是问题在这道题中每个节点都允许作为根节点来形成targetSum,所以我们还需要遍历所有的节点并让所有节点成为根节点进行一次bfs找到符合条件的
        * 所以这道题需要双递归函数来实现,bfs递归root为根节点下的路径,pathSum用来递归所有的节点都进行一次bfs搜索
        */
        bfs(root, targetSum);//以当前root为根节点搜索
        pathSum(root->left, targetSum);//以左孩子为根节点搜索
        pathSum(root->right, targetSum);//以右孩子为根节点搜索
        return count;
    }
    void bfs(TreeNode* root, long targetSum) {//搜索以root为根节点的枝干是否能形成targetSum
        if (root == nullptr) {
            return;
        }
        if (root->val == targetSum) {
            //找到一个了,要放在root判断的前面,否则如果到
            count++;//还不能return,因为有正负数,可能还有其它分支可以组成该结果
        }
        bfs(root->left, targetSum - root->val);
        bfs(root->right, targetSum - root->val);
    }
};

