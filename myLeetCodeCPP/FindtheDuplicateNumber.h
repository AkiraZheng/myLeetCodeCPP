#pragma once
#include "header.h"
class FindtheDuplicateNumber
{
public:
    int findDuplicate(vector<int>& nums) {
        /*��287�⣺Ѱ���ظ���
        * ���ַ���left��rightָ��
        * ������Ŀ˵��nums����n+1���������ַ�Χ��[1, n]֮�䣬���[1,n]��Χ�ڵ���û���ظ��Ļ�����ô�պ�ÿ�������У���ʱ��������n����
        * ��������nums��n+1���������Աض������ظ�
        * 1. ���ظ��Ļ�����ô�����������λ��Ӧ����(n+1)/2����(n+1)/2������С�ڻ����(n+1)/2��
        * 2. ���������ظ����Ĵ��ڣ���˼���С�ڻ����(n+1)/2��������k����k>(n+1)/2����ô˵����0~(n+1)/2�п϶����ظ���������Ϊ�ⲿ�ֲ�ֹ(n+1)/2����
        * ��������ķ�ʽ���϶��֣�
        */
        int left = 1, right = nums.size() - 1;//��ֵ�Ǵ�1��ʼ��
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
        //������ҵ�left==rightʱ�Ϳ���return
        return left;
    }
};

