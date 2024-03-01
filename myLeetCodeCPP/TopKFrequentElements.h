#pragma once
#include "header.h"
class compare {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;//�Զ���Ƚ��߼�������a�Ƿ�Ӧ������b֮ǰ
    }
};
class TopKFrequentElements
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*��347��:ǰk����ƵԪ��
        * ѭ����һ��:��map����ĳ����ֵ��Ӧ�ļ���Ƶ��
        * ѭ���ڶ���:1.ѭ����ȡmap�е�pair,ͨ���Զ���compareʵ��һ��priority_queue,ʹ�����ȵȼ��Ķ�����һ��С����
        *             ���ڶ�����pop���еĶ�,��������Ǵ󶥶�,��ôÿ�η������µĸ�Ƶ��ʱ,��ѵ�ǰ���Ƶ�ʵĶ��ж�pop��ȥ,������Ҫ��
        *           2.ÿ��pair��ջ��ʱ��,ͨ���Զ����compare���򶼻ᱻ�ŵ���Ӧ��λ��
        *             С����pop�������ǵ�����>kʱ�Ͱ���С�ĶѶ�pop��ȥ
        */

        //1.����Ƶ��map
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }
        //2.С����ʵ��ǰk����ƵԪ�صĻ�ȡ
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que;//��������:��������-�����ݵ�����-�Զ������ȼ�����
        for (unordered_map<int, int>::iterator it = freq_map.begin(); it != freq_map.end(); it++) {
            que.push(*it);//��pairһ��һ���Ž�ȥ
            if (que.size() > k) {
                que.pop();//����ֻ��k����
            }
        }
        //3.С�������������
        vector<int> result(que.size());
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] = que.top().first;
            que.pop();
        }
        return result;
    }
};

