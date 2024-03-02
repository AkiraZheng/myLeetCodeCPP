#pragma once
#include "header.h"
class SubarraySumEqualsK
{
public:
    int subarraySum(vector<int>& nums, int k) {
        /*��560��:��Ϊk��������
        * ����Ҫ�������������������,������ǿ���ά��һ��ǰ׺ֵ,map[pre]=count
        * Ҳ���Ǳ���nums[i],map�д�j��ǰ���д�[0,j]��Χ�ڵ��ۼ�ֵ
        * �����Ǳ�����iʱ:
        *       ������Ҫ����ȫ���ۼӵ�pre_i=sum([0,i]);����֪map�д��key��pre=sum([0,j])
        *       ��������Ҫȷ����iΪ��β,ǰ���Ƿ������������������i��ɺ�Ϊk����
        *       ��ǰ��������(j,i]�ĺ�Ϊk,��ô������������ [0,j](j,i]��֪,ȫ��pre_i���Ǵ�0��i���ܺ�
        *       ����ֻҪ����sum([0,j])+k=pre_i�Ϳ���ȷ����������(j,i]�ĺ�Ϊk
        *       ����sum([0,j])=pre_i-k,��sum([0,j])��ǰ���Ѿ�����map����,��������ֻҪȷ��map(pre_i-k)�Ƿ���ھ���
        * Ϊʲômap��valueҪ��count?��Ϊ���麬����,����ǰ׺��Ϊĳ��key�Ŀ����кܶദ,ÿһ����������Ϊ�������(j,i]����Ҫ�����j
        */

        int pre_i = 0;
        int count = 0;//����ȫ���ܹ��ж��ٸ�������
        unordered_map<int, int> pre_map;//keyΪ[0,j]��ǰ׺��,countΪǰ׺��Ϊkey�Ķ�Ӧj�ж��ٸ�(��Ϊ�и���,���Կ����кܶ��)
        pre_map[0] = 1;//��ʼ����0�����ǰ׺��0
        for (int i = 0; i < nums.size(); i++) {
            pre_i += nums[i];//[0,i]�ۺ�
            if (pre_map.find(pre_i - k) != pre_map.end()) {
                //����
                count += pre_map[pre_i - k];//�ۼ��ж��ٸ�����ǰ׺��Ϊpre_i-k��
            }
            pre_map[pre_i]++;
        }
        return count;
    }
};

