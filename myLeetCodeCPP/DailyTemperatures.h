#pragma once
#include "header.h"
class DailyTemperatures
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*��739��:ÿ���¶�
        * ��ĳһ�ߵ�һ�����/��Сֵ,����ά��һ������ջ
        * �����ҵ��ǵ�һ�������,����ά�������ݼ�ջ  ջ��[��->��
        * ������temp[i]��ջ�����ֵʱ,�������ջ,��ջ���ұߵ�һ�������¶Ⱦ��ǵ�ǰ��i
        */
        stack<int> temp_st;
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!temp_st.empty() && temperatures[i] > temperatures[temp_st.top()]) {
                //��ջ
                int j = temp_st.top();
                temp_st.pop();
                result[j] = i - j;
            }
            temp_st.push(i);
        }
        return result;
    }
};

