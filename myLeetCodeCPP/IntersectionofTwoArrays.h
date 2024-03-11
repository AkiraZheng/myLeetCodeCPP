#pragma once
#include "header.h"
class IntersectionofTwoArrays
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;//存唯一的nums1[i]
        unordered_set<int> set2;//存唯一的nums1[i]

        for (int i : nums1) set1.insert(i);
        for (int i : nums2) set2.insert(i);

        //比对两个set:不要求数量相等，只要存在就行
        unordered_set<int> res_temp;//保证数据的唯一性
        for (const auto temp : set1) {
            if (set2.find(temp) != set2.end()) res_temp.insert(temp);
        }

        vector<int> result(res_temp.begin(), res_temp.end());
        return result;

    }
};

