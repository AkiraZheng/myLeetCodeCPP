#pragma once
#include "header.h"
class KthLargestElementinanArray
{
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*������priority_queue���ѣ�Ĭ�϶����׾������ֵ��ֱ�Ӹ����ź����ˣ�*/
        // priority_queue<int> que(nums.begin(), nums.end());
        // int i= 0;
        // while(i!=k-1){
        //     que.pop();
        //     i++;
        // }
        // return que.top();

        /*Ҳ������sort���Լ�ʵ��һ��lambda�������У���queue����*/
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
        });
        return nums[k - 1];
    }
};

