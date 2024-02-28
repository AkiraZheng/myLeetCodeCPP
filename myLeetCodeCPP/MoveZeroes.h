#pragma once
#include "header.h"
class MoveZeroes
{
public:
    void moveZeroes(vector<int>& nums) {
        /*��283�⣺�ƶ���
        * ��һ��int���ۼ�iǰ���0����������ǰŲ����Ӧ��λ��
        */
        int zeroCounts = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[i - zeroCounts] = nums[i];//i��Ӧ��ֵ��ǰ��zeroCountsλ
                continue;
            }
            zeroCounts++;//nums[i]Ϊ0
        }
        //��0���ں���
        for (int i = nums.size() - zeroCounts; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

