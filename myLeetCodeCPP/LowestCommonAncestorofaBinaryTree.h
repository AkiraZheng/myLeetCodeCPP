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
        /*��236�⣺�������������������
        * ���������ҵ�ǰroot�ڵ���������Ƿ���p��q->�������Ƿ���p��q��û�еĻ���return null����һ��
        * ��ֹ���������жϵ�ǰ�ڵ��Ƿ�Ϊp��q
        * ע�⣺���ﻹҪ����p��q��ͬһ֦�ɵ������������нڵ㴦���У�ֻҪ����left��right��Ϊnull�ͷ��ظýڵ㣨��left��right��ȫΪ�ǿյ������£�
        *      ˵������Ϊ���������ͬһ֦���ϵĻ�����ô���Ǻ���������ݵ�ʱ��ĳ���ڵ��������Ҿ����طǿ�ֵ�����·���ֵΪ��ǰroot
        *           �����pq�����ͬһ֦���ϵĻ�����ô��ʱ�򷵻ص�ǰ�ǿսڵ���ܱ�֤����ȷ�������������ô����Ҳ�Ҳ���ĳ��root���������Ҿ�Ϊ�ǿ���
        */
        return find_pq(root, p, q);
    }
    TreeNode* find_pq(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        //����������ҵ���ǰroot���������Ƿ���p��q��û�оͷ���null���������������Ƿ���p��q
        TreeNode* left = find_pq(root->left, p, q);//�ҵ�ǰ�ڵ��������
        TreeNode* right = find_pq(root->right, p, q);//�ҵ�ǰ�ڵ��������
        //�нڵ㴦��
        if (left != nullptr && right != nullptr) {
            //�ҵ���
            return root;
        }
        //���������ڵ㲻��root���ߣ�������rootͬһ�ߵ������
        //1. �������ͬһ�ߣ���ô���Ǵ�ʱ���ز�Ϊ�յ��Ǹ��ڵ���ûë���ģ���Ϊͨ��������ж��Ѿ�ȷ�����뵽���д���Ļ���
        //   ��ǰroot�����������һ�߲�����p-q��
        //2. �����ͬһ�ߵĻ�����ô��ʱ���ز�Ϊ�յ��Ǹ��ڵ�͸����ˣ���Ϊ�������p��q������ڵ㱾�������������ڵ��ˣ�
        //   �����ټ�������Ҳ�Ҳ�������p��q�ĵ��ˣ������⽫��Ϊ����returnֵ
        if (left != nullptr) return left;
        if (right != nullptr) return right;

        return nullptr;//root����û�ҵ�ƥ��Ľڵ㣬����null��ʾû��
    }
};

