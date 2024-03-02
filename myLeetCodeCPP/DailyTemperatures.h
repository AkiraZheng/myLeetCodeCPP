#pragma once
#include "header.h"
class DailyTemperatures
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*第739题:每日温度
        * 找某一边第一个最大/最小值,可以维护一个单调栈
        * 这里找的是第一个更大的,所以维护单调递减栈  栈底[高->低
        * 当遇到temp[i]比栈顶大的值时,就逐个出栈,出栈的右边第一个更高温度就是当前的i
        */
        stack<int> temp_st;
        vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!temp_st.empty() && temperatures[i] > temperatures[temp_st.top()]) {
                //出栈
                int j = temp_st.top();
                temp_st.pop();
                result[j] = i - j;
            }
            temp_st.push(i);
        }
        return result;
    }
};

