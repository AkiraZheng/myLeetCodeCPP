#pragma once
#include "header.h"
class ShortestUnsortedContinuousSubarray
{
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy(nums.begin(), nums.end());
        sort(copy.begin(), copy.end());
        int left = 0, right = nums.size() - 1;
        for (; left < nums.size(); left++) {
            if (nums[left] != copy[left]) {//找到左边开始不符合排序的起点
                break;
            }
        }
        for (; right >= 0; right--) {
            if (nums[right] != copy[right]) {//找到右边开始不符合排序的起点
                break;
            }
        }
        if (left == nums.size() && right == -1) return 0;//严格符合排序
        return right - left + 1;
    }
};

