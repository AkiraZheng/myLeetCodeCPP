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
        /*��337�⣺��ҽ��� III
        * ͨ����������ķ�ʽ������ͬʱ�õ�����������Һ�����߽���ֵ
        * �ݹ麯����ʾ�Ӱ�����ǰroot�ڵ㿪ʼ���µ���߽��
        * �������Һ��Ӻܿ��ܻ��ظ����������map�洢Ͷ��ǰroot����߽��
        */
        if (root == nullptr) return 0;
        if (root->right == nullptr && root->left == nullptr) {
            //�����һ���ڵ���
            map[root] = root->val;
            return root->val;
        }

        if (map.find(root) != map.end()) {
            //֮ǰ�ҹ�͵�ýڵ�����ֵ��
            return map[root];
        }

        //͵���ڵ�root������£���һ���ڵ㲻��͵������root->left��root->right
        int val1 = root->val;
        if (root->left) val1 += rob(root->left->left) + rob(root->left->right);//root�����¸��ڵ��п�����null�������˳�����Ҫ����root==null���ж�
        if (root->right) val1 += rob(root->right->left) + rob(root->right->right);
        //��͵���ڵ������£���һ���ڵ㶼���Կ��ǽ�ȥ
        int val2 = rob(root->left) + rob(root->right);
        int result = max(val1, val2);
        map[root] = result;
        return result;
    }
};

