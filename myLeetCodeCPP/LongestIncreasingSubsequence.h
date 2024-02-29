#pragma once
#include "header.h"
class LongestIncreasingSubsequence
{
public:
    int lengthOfLIS(vector<int>& nums) {
        /*第300题：最长递增子序列
        * 动态规划
        * 1. 数组意义
        *    dp[i]表示包含i的前面数据中最长递增子序列，但是实际最长子序列可能不包含i，所以还需要一个result更新最大值
        * 2. 递推公式
        *    遍历i前面的所有数据，当遍历到j时，如果nums[j]<nums[i],那么我们是可以假设j及其前面的最长子序列是可以跟当前nums[i]组成递增子序列的
        *    则此时j处的最长递增子序列我们已经求出来了，那么dp[i]=dp[j]+1,不断迭代更新dp数组
        */
        vector<int> dp(nums.size(), 1);//最坏的结果是当前nums[i]单独作为新的递增数组，如数组中间出现数值1，那么该处dp[i]就是1了
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    //有可能组成新的最长递增子序列
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(dp[i], result);
        }
        return result;
    }
};

