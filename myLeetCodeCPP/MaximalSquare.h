#pragma once
#include "header.h"
class MaximalSquare
{
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*第221题：最大正方形
        * 跟第85题最大矩形一样，采用动规法
        * 1.定义一个rows×cols的二维数组，dp[i][j]用于存储包含该点在内，同一行中j及其前面的连续1的总数。
        * 2.每更新完一个dp[i][j]的值，还要从该点开始，往上面一行一行更新由该点往上所能组成的最大正方形的值min(dp[i][j]到dp[i-1][j])，由于需要组成正方形，所以minWidth起码得跟height相等，否则就直接continue
        */
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));//表示dp[i][j]同一行包含i的最大连续1数
        int maxRect = 0;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                maxRect = 1;
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') continue;
                dp[i][j] = dp[i][j - 1] + 1;
                maxRect = max(1, maxRect);//在当前层的正方形面积只能是1
                if (i == 0) continue;//第一层的正方形最大也只能是1，因为没有上一层
                //搜索第[i,j]点往上的最大矩形
                int minW = dp[i][j];
                for (int k = i - 1; k >= 0; k--) {
                    int h = i - k + 1;
                    minW = min(minW, dp[k][j]);//更新最短边
                    if (minW < h) break;//最短边没有h大，没办法组成正方形，正方形的前提是宽起码得跟高一样
                    maxRect = max(h * h, maxRect);//高度决定了正方形的面积
                }
            }
        }
        return maxRect;
    }
};

