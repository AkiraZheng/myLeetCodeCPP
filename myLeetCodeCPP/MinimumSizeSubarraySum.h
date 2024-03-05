#pragma once
#include "header.h"
class MinimumSizeSubarraySum
{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*第209题:长度最小的子数组
        * 滑动窗口法:
        *   1. 由左闭右闭
        *   2. 右窗口不断右滑
        *   3. 左窗口当遇到sum>=target时触发缩小信号
        *      需要首先执行更新最小窗口的result值,然后在缩窗口直到sum<target再继续进行扩右窗口
        */

        int result = INT_MAX;
        int left = 0;//窗口左右点,左闭右闭的区间:sum=[nums[left], nums[right]]
        int sum = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target && left <= right) {
                result = min(result, right - left + 1);//更新最小窗口数
                sum -= nums[left++];
            }
        }
        return (result == INT_MAX) ? 0 : result;
    }
};

