#pragma once
#include "header.h"
class IntersectionofTwoArrays
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;//��Ψһ��nums1[i]
        unordered_set<int> set2;//��Ψһ��nums1[i]

        for (int i : nums1) set1.insert(i);
        for (int i : nums2) set2.insert(i);

        //�ȶ�����set:��Ҫ��������ȣ�ֻҪ���ھ���
        unordered_set<int> res_temp;//��֤���ݵ�Ψһ��
        for (const auto temp : set1) {
            if (set2.find(temp) != set2.end()) res_temp.insert(temp);
        }

        vector<int> result(res_temp.begin(), res_temp.end());
        return result;

    }
};

