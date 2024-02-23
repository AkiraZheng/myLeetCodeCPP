#pragma once
#include "header.h"
class Subsets
{
private:
	void printVector(vector<vector<int>>& nums);
public:
	vector<vector<int>> result;
	vector<int> subSet;
	vector<vector<int>> subsets(vector<int>& nums);
	void backtrack(vector<int>& nums, int startIndex);
	static void test_Subsets();
};

