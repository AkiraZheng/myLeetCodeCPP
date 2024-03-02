#pragma once
#include "header.h"
class FindAllNumbersDisappearedinanArray
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*��448��:�ҵ�������������ʧ������
        * ���������ֵת�浽��ϣ����
        * Ȼ���1-nѭ��,ֻҪ�ڹ�ϣ�����Ҳ���i��Ӧ������,���ڽ�������i
        * ����:���Խ�nums sortһ��,Ȼ���������,�ų��ظ�ֵ��,����������nums[i],nums[i+1]֮�����ֵ�����ȱ�ٵĶ�Ӧ��ֵ
        */

        // 1. ��ϣ����
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num] = 1;
        }
        int n = nums.size();
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            if (map.find(i) == map.end()) {
                //i����map��,˵��ȱi
                result.push_back(i);
            }
        }
        return result;
    }
};

