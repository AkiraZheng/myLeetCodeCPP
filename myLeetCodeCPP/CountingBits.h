#pragma once
#include "header.h"
class CountingBits
{
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);//表示当前i二进制的含1总数
        if (n == 0) return dp;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i / 2] + (i & 1);//i>>1也实现右移
        }
        return dp;
    }
};

