#pragma once
#include "header.h"
class MergeIntervals
{
private:
	void printVector(vector<vector<int>>& nums);
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals);
	static void test_MergeIntervals();
};

