#pragma once
#include "header.h"
class n_4Sum
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        /*��18�⣺����֮��
        * �����Ľ���˼·��ʵ������֮����һ���ģ�ֻ�Ǵ�����֦��targetΪ0��Ϊ target-nums�е�������
        * ÿһ��ѭ�����Ӻ�һ������ʼ����ȡǰ��ȡ��������
        * ȥ�ش�������nums[rand]==nums[rand-1]�Ķ������㣨4��������ȥ�أ�
        * ��֦��������nums�������ˣ��������nums[k]>target,��������ֵ�Ͳ������ۼӳ�target��
        *          ͬ��nums[i]>target-nums[k],������������ۼӳ�
        */

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int k = 0; k < n; k++) {//����֮�͵�Ŀ���
            //��֦����
            if (nums[k] > target && target > 0)  return result;//target�п����Ǹ���
            if ((n - 1) - k + 1 < 4) return result;//�����ճ�4������

            //ȥ�ش����Ѿ����ҹ�����ֵnums[k]�Ͳ�������
            while (k > 0 && nums[k] == nums[k - 1]) k++;


            int new_target = target - nums[k];//����֮�͵���Ŀ��

            //��������֮�͵�˼·��������֮��Ϊnew_target��i��t+1��ʼ���ң�Ҳ��һ��ȥ�أ���Ϊǰ�����������ˣ�
            for (int i = k + 1; i < n; i++) {
                //��֦����
                if (nums[i] > new_target && new_target > 0) break;//target�п����Ǹ���

                //ȥ�ش���
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;

                //˫ָ�����������Ϊnew_target�ĸ���
                int left = i + 1;
                int right = n - 1;

                while (left < right) {

                    // nums[k] + nums[i] + nums[left] + nums[right] > target �����
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                        // nums[k] + nums[i] + nums[left] + nums[right] < target �����
                    }
                    else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // ��nums[left]��nums[right]ȥ��
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // �ҵ���ʱ��˫ָ��ͬʱ����
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
    static void test_4Sum() {
        n_4Sum s;
        vector<int> test = { 0,0,0,0 };
        s.fourSum(test, 0);
    }
};

