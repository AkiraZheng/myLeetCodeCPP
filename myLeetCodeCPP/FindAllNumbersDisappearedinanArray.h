#pragma once
#include "header.h"
class FindAllNumbersDisappearedinanArray
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*第448题:找到所有数组中消失的数字
        * 将数组里的值转存到哈希表中
        * 然后从1-n循环,只要在哈希表中找不到i对应的数据,就在结果中添加i
        * 进阶:可以将nums sort一下,然后遍历数组,排除重复值后,相邻两个数nums[i],nums[i+1]之间的数值差就是缺少的对应的值
        */

        // 1. 哈希表方法
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num] = 1;
        }
        int n = nums.size();
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            if (map.find(i) == map.end()) {
                //i不在map中,说明缺i
                result.push_back(i);
            }
        }
        return result;
    }
};

