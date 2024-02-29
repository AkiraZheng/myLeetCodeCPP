#pragma once
#include "header.h"
class BestTimetoBuyandSellStockwithCooldown
{
public:
    int maxProfit(vector<int>& prices) {
        /*第309题：买卖股票的最佳时机含冷冻期（看word的思维导图更清晰）
        * 1. dp数组：n*4
        *    行表示天数，列表示状态，共有四种状态dp[i][j]表示i当天状态j下的最大收益
        * 2. 递推公式
        *    状态0：保持持有
        *          上一个状态保持持有              dp[i-1][0]
        *          上一个状态保持不持有，今天买入   dp[i-1][1]
        *          上一个状态冷冻期，今天买入       dp[i-1][3]
        *    状态1：今天不持股，维持上一天的不持股状态或今天卖出
        *    状态2：今天卖出
        *    状态3：今天是冷冻期，前一天卖出
        */
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0]; dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            dp[i][1] = max(dp[i - 1][3], dp[i - 1][1]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max(max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]), dp[prices.size() - 1][3]);
    }
};

