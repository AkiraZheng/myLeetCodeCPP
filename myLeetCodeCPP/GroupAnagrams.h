#pragma once
#include "header.h"
class GroupAnagrams
{
private:
	void printVector(vector<vector<string>>& nums);
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs);
	static void test_GroupAnagrams();
};

