#pragma once
#include "header.h"
class TaskScheduler
{
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*��621��:���������
        * ����Ͱ˼��,Ͱ��=������������������N,Ͱ��=�䶳ʱ��n+1
        * ���һ��Ͱ��������(��Ϊ���һ��������Ҫ�ⶳ),���һ��Ͱ��ͬΪ�������������������types�й�
        * Ͱʵ�ʴ�С:(N-1)*(n+1)+types
        * ʵ�������������ܻ��Ͱʵ�ʴ�СҪ��(Ͱ�Ĵ�Сʵ���Ͽ������Ϊ������Ҫ���������ʱ��,�����������Ǹ��������)
        *       ���Ի���Ҫ��Ͱ��tasks.size()�Ƚ�,ȡ���ֵ
        */
        unordered_map<char, int> task_map;//key:tasks,value:counts
        //1. ����Ͱ����
        int N = 0;
        for (char c : tasks) {
            N = max(N, ++task_map[c]);
        }
        //2. ����types��С
        int types = 0;
        for (unordered_map<char, int>::iterator it = task_map.begin(); it != task_map.end(); it++) {
            pair<char, int> temp = *it;
            if (temp.second == N) {
                types++;
            }
        }
        int size = tasks.size();
        return max(size, (N - 1) * (n + 1) + types);
    }
};

