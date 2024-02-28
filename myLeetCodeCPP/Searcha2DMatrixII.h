#pragma once
#include "header.h"
class Searcha2DMatrixII
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*��240�⣺������ά����II
        * �����½��Ǹ��㿪ʼչ������������ÿ����ǰ����˵������С�Ҵ���ص�
        * ��������������ԣ���ǰֵ��targetСʱ��col++���ұ����ֵ������target��ʱ��row--���ϱ�С
        */
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0;//�����½ǿ�ʼ
        while (i >= 0 && j < col) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) j++;//��++������ֵ
            else i--;//��--����Сֵ
        }
        return false;
    }
};

