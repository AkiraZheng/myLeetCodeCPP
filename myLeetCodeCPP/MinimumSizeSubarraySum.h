#pragma once
#include "header.h"
class MinimumSizeSubarraySum
{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*��209��:������С��������
        * �������ڷ�:
        *   1. ������ұ�
        *   2. �Ҵ��ڲ����һ�
        *   3. �󴰿ڵ�����sum>=targetʱ������С�ź�
        *      ��Ҫ����ִ�и�����С���ڵ�resultֵ,Ȼ����������ֱ��sum<target�ټ����������Ҵ���
        */

        int result = INT_MAX;
        int left = 0;//�������ҵ�,����ұյ�����:sum=[nums[left], nums[right]]
        int sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target && left <= right) {
                result = min(result, right - left + 1);//������С������
                sum -= nums[left++];
            }
        }
        return (result == INT_MAX) ? 0 : result;
    }
};

