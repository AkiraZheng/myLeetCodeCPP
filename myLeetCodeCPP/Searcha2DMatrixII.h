#pragma once
#include "header.h"
class Searcha2DMatrixII
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*第240题：搜索二维矩阵II
        * 从左下角那个点开始展开搜索，对于每个当前点来说都有上小右大的特点
        * 根据数组的有序性，当前值比target小时，col++向右变大数值；当比target大时，row--向上变小
        */
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;//从左下角开始
        while (i >= 0 && j < col) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) j++;//列++，增大值
            else i--;//行--，减小值
        }
        return false;
    }
};

