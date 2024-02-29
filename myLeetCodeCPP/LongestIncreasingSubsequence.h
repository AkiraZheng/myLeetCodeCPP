#pragma once
#include "header.h"
class LongestIncreasingSubsequence
{
public:
    int lengthOfLIS(vector<int>& nums) {
        /*��300�⣺�����������
        * ��̬�滮
        * 1. ��������
        *    dp[i]��ʾ����i��ǰ������������������У�����ʵ��������п��ܲ�����i�����Ի���Ҫһ��result�������ֵ
        * 2. ���ƹ�ʽ
        *    ����iǰ����������ݣ���������jʱ�����nums[j]<nums[i],��ô�����ǿ��Լ���j����ǰ�����������ǿ��Ը���ǰnums[i]��ɵ��������е�
        *    ���ʱj��������������������Ѿ�������ˣ���ôdp[i]=dp[j]+1,���ϵ�������dp����
        */
        vector<int> dp(nums.size(), 1);//��Ľ���ǵ�ǰnums[i]������Ϊ�µĵ������飬�������м������ֵ1����ô�ô�dp[i]����1��
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    //�п�������µ������������
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(dp[i], result);
        }
        return result;
    }
};

