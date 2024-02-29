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
	string serizeStr;//存储序列化后的字符串

    void serializeBFS(TreeNode* root) {
        if (root == nullptr) {
            serizeStr += "#";//用#号代表空字符
            return;
        }
        serizeStr += (to_string(root->val) + "_");//中:因为val可能不止1位数，所以1需要做标识符来代表这是非空节点值
        serializeBFS(root->left);//左
        serializeBFS(root->right);//右
    }
    TreeNode* deserializeBFS(const vector<string>& dataList, int& i) {
        if (dataList[i] == "#") {
            return nullptr;
        }
        //中
        TreeNode* midNode = new TreeNode(stoi(dataList[i]));
        //左
        midNode->left = deserializeBFS(dataList, ++i);
        //右
        midNode->right = deserializeBFS(dataList, ++i);

        return midNode;//返回中节点给上一层
    }
public:

};

