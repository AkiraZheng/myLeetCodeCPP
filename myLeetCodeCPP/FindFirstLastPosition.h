#pragma once
#include "header.h"
class FindFirstLastPosition
{
public:
	vector<int> searchRange(vector<int>& nums, int target);
private:
	int findRightBorder(vector<int>& nums, int target);//�ҵ�nums[i]>target�����ұ߽�
	int findLeftBorder(vector<int>& nums, int target);//�ҵ�nums[i]<target������߽�
};

