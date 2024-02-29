#pragma once
#include "header.h"
class CoinChange
{
public:
    int coinChange(vector<int>& coins, int amount) {
        /*��322�⣺��Ǯ�һ�
        * �������⣬������amount����Ʒ�ǿ��ظ��õ�coins����ȫ������
        * ����������Ҳ����ϣ����԰ѱ�����������㣬����ѡ�����
        * dp[i]�����i����С��Ʒ��
        */
        vector<int> dp(amount + 1, INT_MAX);//����һ��ֵΪ0�ı���
        dp[0] = 0;//��¼������i��Ӳ��coins[i]���ʱ��Ҫ�Ķ������Ʒ��Ϊ0
        for (int i = 1; i <= amount; i++) {//��������
            for (int j = 0; j < coins.size(); j++) {//������Ʒ
                //���赱ǰcoins[j]�Ǳ���������һ����ɣ���ô����Ҫ֪��ʣ�µ�i-coins[j]����С������ֵ
                if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {//������i-coins[j]��Ҫ����Ʒ��λINT_MAX˵����ǰconis��������������Ӧ������
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

