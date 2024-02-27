#pragma once
#include "header.h"
class KthLargestElementinanArray
{
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*可以用priority_queue最大堆，默认队列首就是最大值（直接给你排好序了）*/
        // priority_queue<int> que(nums.begin(), nums.end());
        // int i= 0;
        // while(i!=k-1){
        //     que.pop();
        //     i++;
        // }
        // return que.top();

        /*也可以用sort，自己实现一个lambda降序排列：比queue更快*/
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
        });
        return nums[k - 1];
    }
};

