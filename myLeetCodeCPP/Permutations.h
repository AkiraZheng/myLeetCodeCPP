#pragma once
#include "header.h"
class Permutations
{
private:
	void printVector(vector<vector<int>>& nums);
public:
	vector<vector<int>> result;
	vector<int> permutationNode;//�ݴ浱ǰ֦�ɵĵ�������
	vector<vector<int>> permute(vector<int>& nums);
	void backtrack(vector<int>& nums, vector<bool>& isChoose); //isChoose��true-false��ʾ��iλ�Ƿ���ȡ
	static void test_Permutations();
};

