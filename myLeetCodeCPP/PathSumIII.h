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
        /*��437��:·���ܺ�III
        * bfs�ݹ��������ҵ���rootΪ���ڵ��֦���Ƿ���ں�ΪtargetSum ��֦��
        * �����������������ÿ���ڵ㶼������Ϊ���ڵ����γ�targetSum,�������ǻ���Ҫ�������еĽڵ㲢�����нڵ��Ϊ���ڵ����һ��bfs�ҵ�����������
        * �����������Ҫ˫�ݹ麯����ʵ��,bfs�ݹ�rootΪ���ڵ��µ�·��,pathSum�����ݹ����еĽڵ㶼����һ��bfs����
        */
        bfs(root, targetSum);//�Ե�ǰrootΪ���ڵ�����
        pathSum(root->left, targetSum);//������Ϊ���ڵ�����
        pathSum(root->right, targetSum);//���Һ���Ϊ���ڵ�����
        return count;
    }
    void bfs(TreeNode* root, long targetSum) {//������rootΪ���ڵ��֦���Ƿ����γ�targetSum
        if (root == nullptr) {
            return;
        }
        if (root->val == targetSum) {
            //�ҵ�һ����,Ҫ����root�жϵ�ǰ��,���������
            count++;//������return,��Ϊ��������,���ܻ���������֧������ɸý��
        }
        bfs(root->left, targetSum - root->val);
        bfs(root->right, targetSum - root->val);
    }
};

