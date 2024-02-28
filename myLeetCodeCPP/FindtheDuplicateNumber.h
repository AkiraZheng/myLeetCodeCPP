#pragma once
#include "header.h"
class FindtheDuplicateNumber
{
public:
    int findDuplicate(vector<int>& nums) {
        /*第287题：寻找重复数
        * 二分法：left和right指针
        * 由于题目说了nums包含n+1个数，数字范围在[1, n]之间，如果[1,n]范围内的数没有重复的话，那么刚好每个数都有，此时数组中有n个数
        * 但是由于nums有n+1个数，所以必定会有重复
        * 1. 不重复的话，那么整个数组的中位数应该是(n+1)/2，有(n+1)/2个数是小于或等于(n+1)/2的
        * 2. 但是由于重复数的存在，因此假设小于或等于(n+1)/2的数共有k个，k>(n+1)/2，那么说明在0~(n+1)/2中肯定有重复的数（因为这部分不止(n+1)/2个）
        * 根据上面的方式不断二分，
        */
        int left = 1, right = nums.size() - 1;//数值是从1开始的
        while (left < right) {
            int mid = (left + right) / 2;
            int k = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) k++;
            }
            if (k > mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        //当最后找到left==right时就可以return
        return left;
    }
};

