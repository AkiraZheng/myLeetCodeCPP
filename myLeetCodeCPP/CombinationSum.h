#pragma once
#include "header.h"
class CombinationSum
{
private:
	vector<vector<int>> result;
	vector<int> layer_nums;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
	void backtrack(vector<int>& candidates, int target, int sum, int startIndex);
	static void test_CombinationSum();
};

