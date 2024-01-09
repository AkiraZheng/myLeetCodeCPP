#pragma once
#include "header.h"
class FindFirstLastPosition
{
public:
	vector<int> searchRange(vector<int>& nums, int target);
private:
	int findRightBorder(vector<int>& nums, int target);//找到nums[i]>target的最右边界
	int findLeftBorder(vector<int>& nums, int target);//找到nums[i]<target的最左边界
};

