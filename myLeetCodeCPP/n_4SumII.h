#pragma once
#include "header.h"
class n_4SumII
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        /*��454�⣺����֮��
        * ������map�ֱ��A+B�Ľ����C+D�Ľ����key:A[i]+B[j]��value:���ֹ��Ĵ���
        * ����һ���̶��Ͽ��Լ��ټ�����
        */

        unordered_map<int, int> sumAB;
        unordered_map<int, int> sumCD;
        int n = A.size();

        //��������map
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sumAB[A[i] + B[j]]++;//��ʾA[i]+B[j]==key�������count��
                sumCD[C[i] + D[j]]++;
            }
        }

        //����������Ϊ0�ĸ���
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

