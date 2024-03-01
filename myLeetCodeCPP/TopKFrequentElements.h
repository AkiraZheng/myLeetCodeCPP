#pragma once
#include "header.h"
class compare {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;//自定义比较逻辑，返回a是否应该排在b之前
    }
};
class TopKFrequentElements
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*第347题:前k个高频元素
        * 循环第一遍:用map来存某个数值对应的计数频率
        * 循环第二遍:1.循环获取map中的pair,通过自定义compare实现一个priority_queue,使有优先等级的队列是一个小顶堆
        *             由于队列是pop队列的顶,所以如果是大顶堆,那么每次发现有新的高频次时,会把当前最高频率的队列顶pop出去,不符合要求
        *           2.每个pair入栈的时候,通过自定义的compare规则都会被放到对应的位置
        *             小顶堆pop的条件是当队列>k时就把最小的堆顶pop出去
        */

        //1.构建频率map
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }
        //2.小顶堆实现前k个高频元素的获取
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;//三个参数:数据类型-存数据的容器-自定义优先级规则
        for (unordered_map<int, int>::iterator it = freq_map.begin(); it != freq_map.end(); it++) {
            que.push(*it);//将pair一个一个放进去
            if (que.size() > k) {
                que.pop();//保持只有k个数
            }
        }
        //3.小顶堆逆序存入结果
        vector<int> result(que.size());
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] = que.top().first;
            que.pop();
        }
        return result;
    }
};

