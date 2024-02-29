#pragma once
#include "header.h"
class CoinChange
{
public:
    int coinChange(vector<int>& coins, int amount) {
        /*第322题：零钱兑换
        * 背包问题，背包是amount，物品是可重复用的coins（完全背包）
        * 这道题非排列也非组合，可以把背包放外层或里层，这里选择外层
        * dp[i]：组成i的最小物品数
        */
        vector<int> dp(amount + 1, INT_MAX);//还有一个值为0的背包
        dp[0] = 0;//记录当背包i跟硬币coins[i]相等时需要的额外的物品数为0
        for (int i = 1; i <= amount; i++) {//遍历背包
            for (int j = 0; j < coins.size(); j++) {//遍历物品
                //假设当前coins[j]是背包的其中一个组成，那么还需要知道剩下的i-coins[j]的最小被填满值
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {//如果组成i-coins[j]需要的物品数位INT_MAX说明当前conis不能组成这个数，应该跳过
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

