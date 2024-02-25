#pragma once
class FlattenBinaryTreetoLinkedList
{
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	};
	struct TreeList {
		TreeNode* node;
		TreeList* next;
		TreeList() :node(nullptr), next(nullptr){}
		TreeList(TreeNode* node) :node(node), next(nullptr) {}
		TreeList(TreeList* next) :node(nullptr), next(next) {}
	};
	void flatten(TreeNode* root);
	void traversal(TreeNode* root);
};

