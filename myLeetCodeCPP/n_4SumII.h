#pragma once
#include "header.h"
class n_4SumII
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        /*第454题：四数之和
        * 用两个map分别存A+B的结果和C+D的结果，key:A[i]+B[j]，value:出现过的次数
        * 这样一定程度上可以减少计算量
        */

        unordered_map<int, int> sumAB;
        unordered_map<int, int> sumCD;
        int n = A.size();

        //构建两个map
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumAB[A[i] + B[j]]++;//表示A[i]+B[j]==key的组合有count种
                sumCD[C[i] + D[j]]++;
            }
        }

        //计算四数和为0的个数
        int result = 0;
        for (const auto temp : sumAB) {
            int sum = temp.first;
            int count = temp.second;
            int gap = 0 - sum;
            if (sumCD.find(gap) != sumCD.end()) {
                result += count * sumCD[gap];
            }
        }

        return result;
    }
};

