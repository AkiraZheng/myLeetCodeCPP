#pragma once
#include "header.h"
class n_4Sum
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*第18题：四数之和
        * 这道题的结题思路其实跟三数之和是一样的，只是从三树枝和target为0变为 target-nums中的任意数
        * 每一层循环都从后一个数开始（不取前面取过的数）
        * 去重处理：出现nums[rand]==nums[rand-1]的都不计算（4个数都得去重）
        * 剪枝处理：由于nums先排序了，所以如果nums[k]>target,后面更大的值就不可能累加成target了
        *          同理，nums[i]>target-nums[k],后面更不可能累加成
        */

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int k = 0; k < n; k++) {//三数之和的目标层
            //剪枝处理
            if (nums[k] > target && target > 0)  return result;//target有可能是负数
            if ((n - 1) - k + 1 < 4) return result;//不够凑成4个数了

            //去重处理：已经查找过的数值nums[k]就不再找了
            while (k > 0 && nums[k] == nums[k - 1]) k++;


            int new_target = target - nums[k];//三树之和的新目标

            //根据三数之和的思路计算三树之和为new_target，i从t+1开始查找（也是一种去重，因为前面的数都查过了）
            for (int i = k + 1; i < n; i++) {
                //剪枝处理
                if (nums[i] > new_target && new_target > 0) break;//target有可能是负数

                //去重处理
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;

                //双指针查找三数和为new_target的个数
                int left = i + 1;
                int right = n - 1;

                while (left < right) {

                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                        // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
    static void test_4Sum() {
        n_4Sum s;
        vector<int> test = { 0,0,0,0 };
        s.fourSum(test, 0);
    }
};

