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
        /*��617��:�ϲ�������
        * ǰ�����,����������,��root1��root2����nullʱ,����һ����ʣ�½ڵ�ֱ����Ϊƴ�ӵĽڵ㷵�ؾ���
        */
        return link2Tree(root1, root2);
    }

    TreeNode* link2Tree(TreeNode* root1, TreeNode* root2) {
        //����һ��������һ���ڵ��߾���,�Ϳ��Խ���һ������Ϊ�ӽڵ㴫����һ�����ƴ��
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;

        //ǰ�����
        root1->val += root2->val;//ͬһ�ڵ���root1Ϊ���շ��ؽڵ�
        root1->left = link2Tree(root1->left, root2->left);
        root1->right = link2Tree(root1->right, root2->right);
        return root1;//����ǰƴ�ӺõĽڵ㷵�ظ���һ��
    }
};

