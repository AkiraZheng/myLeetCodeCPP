#pragma once
#include "header.h"
class Permutations
{
private:
	void printVector(vector<vector<int>>& nums);
public:
	vector<vector<int>> result;
	vector<int> permutationNode;//暂存当前枝干的单个排列
	vector<vector<int>> permute(vector<int>& nums);
	void backtrack(vector<int>& nums, vector<bool>& isChoose); //isChoose用true-false表示第i位是否已取
	static void test_Permutations();
};

