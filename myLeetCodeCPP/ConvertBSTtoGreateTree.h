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
        /*��538��:�Ѷ���������ת�����ۼ���
        * ��ȫ����������ͨ������������Դ���ֵ��С�Ľڵ�->��ֵ���Ľڵ����.
        * �����⵱ǰ�ڵ���Ҫ��node������нڵ���ܺ�,��������Ҫ��취���ȱ������������ۼƺ�,�ٰ�ֵ�ʹ�����һ����nodeС����
        * Ҳ������Ҫά��һ��int preֵ��Ϊ��ǰnodeǰ��������ۼƺ�
        * ��ô��ʲô�취����ʵ�ִӴ�����С��������?
        *    ���������С����,��ô������������ǴӴ�С,����������Ҫ ���������
        */
        pre = 0;
        bfs(root);
        return root;
    }
    void bfs(TreeNode* node) {
        if (node == nullptr) return;

        //���������
        bfs(node->right);//��
        node->val += pre;//��
        pre = node->val;//��
        bfs(node->left);//��
    }
};

