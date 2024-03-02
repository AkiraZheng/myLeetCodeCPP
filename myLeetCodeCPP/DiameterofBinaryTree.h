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
	int maxDepth;//��¼���±��������·��(����)
public:
    int diameterOfBinaryTree(TreeNode* root) {
        /*��543��:��������ֱ��
        * �������ʵ��ǰ��124��:�������е����·���� ����,����ı�����ʵ�������·���ڵ���-1
        * Ҫע����������ڵ㶼������Ϊ���·���ĸ��ڵ�(�ݹ鵽�ĵ�ǰ����Ǹ��ڵ�)
        * ����Ҫ�ݹ鵱ǰ����Ϊ���ڵ�ʱ,���Ӻ��Һ��ӷֱ�����·��;
        * ���ҳ��˸��ڵ����ѡ���Һ��ӵĺ���Ϊ���·����,�����ڵ㶼ֻ��ѡ���������һ���ϳ�·��,����ᵼ��·����Ψһ(word��ͼ)
        *       ���retrun��ǰ��ѡ���·������һ���ڵ�ʱ,ֻ��ѡ��max(l,r)
        *       ��Ϊ��ǰ�㷵�ص���һ��Ͳ��Ǹ��ڵ���,ֻ��ѡ��һ�����򷵻�
        */
        maxDepth = 0;
        maxDepthBFS(root);
        return maxDepth;
    }

    int maxDepthBFS(TreeNode* root) {
        if (root == nullptr) return 0;
        //�Ե�ǰrootΪ���ڵ�,�ֱ�����������ڵ�/�ҽڵ���·��
        int l = maxDepthBFS(root->left);
        int r = maxDepthBFS(root->right);
        maxDepth = max(maxDepth, l + r);
        return max(l + 1, r + 1);//�����뵱ǰ���ڵ����Ӻ��·��,��Ҫ��һ�������ӵı�
    }
};

