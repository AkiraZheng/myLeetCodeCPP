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
            if (nums[left] != copy[left]) {//�ҵ���߿�ʼ��������������
                break;
            }
        }
        for (; right >= 0; right--) {
            if (nums[right] != copy[right]) {//�ҵ��ұ߿�ʼ��������������
                break;
            }
        }
        if (left == nums.size() && right == -1) return 0;//�ϸ��������
        return right - left + 1;
    }
};

