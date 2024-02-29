#pragma once
#include "header.h"
class BestTimetoBuyandSellStockwithCooldown
{
public:
    int maxProfit(vector<int>& prices) {
        /*��309�⣺������Ʊ�����ʱ�����䶳�ڣ���word��˼ά��ͼ��������
        * 1. dp���飺n*4
        *    �б�ʾ�������б�ʾ״̬����������״̬dp[i][j]��ʾi����״̬j�µ��������
        * 2. ���ƹ�ʽ
        *    ״̬0�����ֳ���
        *          ��һ��״̬���ֳ���              dp[i-1][0]
        *          ��һ��״̬���ֲ����У���������   dp[i-1][1]
        *          ��һ��״̬�䶳�ڣ���������       dp[i-1][3]
        *    ״̬1�����첻�ֹɣ�ά����һ��Ĳ��ֹ�״̬���������
        *    ״̬2����������
        *    ״̬3���������䶳�ڣ�ǰһ������
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

