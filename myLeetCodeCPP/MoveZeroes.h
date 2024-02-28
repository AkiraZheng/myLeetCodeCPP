#pragma once
#include "header.h"
class MoveZeroes
{
public:
    void moveZeroes(vector<int>& nums) {
        /*第283题：移动零
        * 用一个int数累计i前面的0个数，并往前挪到对应的位置
        */
        int zeroCounts = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[i - zeroCounts] = nums[i];//i对应的值往前推zeroCounts位
                continue;
            }
            zeroCounts++;//nums[i]为0
        }
        //把0补在后面
        for (int i = nums.size() - zeroCounts; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

