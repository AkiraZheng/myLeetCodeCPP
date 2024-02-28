#pragma once
#include "header.h"
class LowestCommonAncestorofaBinaryTree
{
private:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*第236题：二叉树的最近公共祖先
        * 后续遍历找当前root节点的左子树是否有p或q->右子树是否有p或q，没有的话就return null给上一级
        * 终止条件就是判断当前节点是否为p或q
        * 注意：这里还要考虑p和q在同一枝干的情况，因此在中节点处理中，只要发现left或right不为null就返回该节点（在left和right不全为非空的条件下）
        *      说明：因为如果不是在同一枝干上的话，那么我们后面继续回溯的时候某个节点碰到左右均返回非空值则会更新返回值为当前root
        *           而如果pq真的在同一枝干上的话，那么这时候返回当前非空节点才能保证答案正确，否则后面再怎么回溯也找不到某个root能满足左右均为非空了
        */
        return find_pq(root, p, q);
    }
    TreeNode* find_pq(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        //后序遍历，找到当前root的左子树是否有p或q（没有就返回null），再找右子树是否有p或q
        TreeNode* left = find_pq(root->left, p, q);//找当前节点的左子树
        TreeNode* right = find_pq(root->right, p, q);//找当前节点的右子树
        //中节点处理：
        if (left != nullptr && right != nullptr) {
            //找到了
            return root;
        }
        //考虑两个节点不在root两边，而是在root同一边的情况：
        //1. 如果不在同一边，那么我们此时返回不为空的那个节点是没毛病的，因为通过上面的判断已经确定进入到这行代码的话，
        //   当前root左和右至少有一边不存在p-q了
        //2. 如果在同一边的话，那么此时返回不为空的那个节点就更对了，因为这个等于p或q的这个节点本身就是最近公共节点了，
        //   后面再继续遍历也找不到等于p或q的点了，所以这将作为最后的return值
        if (left != nullptr) return left;
        if (right != nullptr) return right;

        return nullptr;//root下面没找到匹配的节点，返回null表示没有
    }
};

