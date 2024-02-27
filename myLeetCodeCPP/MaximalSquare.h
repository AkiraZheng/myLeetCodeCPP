#pragma once
#include "header.h"
class MaximalSquare
{
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*��221�⣺���������
        * ����85��������һ�������ö��淨
        * 1.����һ��rows��cols�Ķ�ά���飬dp[i][j]���ڴ洢�����õ����ڣ�ͬһ����j����ǰ�������1��������
        * 2.ÿ������һ��dp[i][j]��ֵ����Ҫ�Ӹõ㿪ʼ��������һ��һ�и����ɸõ�����������ɵ���������ε�ֵmin(dp[i][j]��dp[i-1][j])��������Ҫ��������Σ�����minWidth����ø�height��ȣ������ֱ��continue
        */
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));//��ʾdp[i][j]ͬһ�а���i���������1��
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
                maxRect = max(1, maxRect);//�ڵ�ǰ������������ֻ����1
                if (i == 0) continue;//��һ������������Ҳֻ����1����Ϊû����һ��
                //������[i,j]�����ϵ�������
                int minW = dp[i][j];
                for (int k = i - 1; k >= 0; k--) {
                    int h = i - k + 1;
                    minW = min(minW, dp[k][j]);//������̱�
                    if (minW < h) break;//��̱�û��h��û�취��������Σ������ε�ǰ���ǿ�����ø���һ��
                    maxRect = max(h * h, maxRect);//�߶Ⱦ����������ε����
                }
            }
        }
        return maxRect;
    }
};

