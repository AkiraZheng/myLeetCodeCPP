#pragma once
#include "header.h"
class HouseRobberIII
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
    unordered_map<TreeNode*, int> map;
public:
    int rob(TreeNode* root) {
        /*第337题：打家劫舍 III
        * 通过后序遍历的方式，才能同时拿到左孩子最金额和右孩子最高金额的值
        * 递归函数表示从包括当前root节点开始往下的最高金额
        * 由于左右孩子很可能会重复计算因此用map存储投当前root的最高金额
        */
        if (root == nullptr) return 0;
        if (root->right == nullptr && root->left == nullptr) {
            //到最后一个节点了
            map[root] = root->val;
            return root->val;
        }

        if (map.find(root) != map.end()) {
            //之前找过偷该节点的最大值了
            return map[root];
        }

        //偷父节点root的情况下：下一个节点不能偷，跳过root->left和root->right
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right);//root的下下个节点有可能是null，所以退出条件要加上root==null的判断
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
        //不偷父节点的情况下：下一个节点都可以考虑进去
        int val2 = rob(root->left) + rob(root->right);
        int result = max(val1, val2);
        map[root] = result;
        return result;
    }
};

