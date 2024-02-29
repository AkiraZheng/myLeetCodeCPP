#pragma once
#include "header.h"
class SerializeandDeserializeBinaryTree
{
private:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	string serizeStr;//�洢���л�����ַ���

    void serializeBFS(TreeNode* root) {
        if (root == nullptr) {
            serizeStr += "#";//��#�Ŵ�����ַ�
            return;
        }
        serizeStr += (to_string(root->val) + "_");//��:��Ϊval���ܲ�ֹ1λ��������1��Ҫ����ʶ�����������Ƿǿսڵ�ֵ
        serializeBFS(root->left);//��
        serializeBFS(root->right);//��
    }
    TreeNode* deserializeBFS(const vector<string>& dataList, int& i) {
        if (dataList[i] == "#") {
            return nullptr;
        }
        //��
        TreeNode* midNode = new TreeNode(stoi(dataList[i]));
        //��
        midNode->left = deserializeBFS(dataList, ++i);
        //��
        midNode->right = deserializeBFS(dataList, ++i);

        return midNode;//�����нڵ����һ��
    }
public:

};

