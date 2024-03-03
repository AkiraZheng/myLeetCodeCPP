#pragma once
#include "header.h"
class TaskScheduler
{
public:
    int leastInterval(vector<char>& tasks, int n) {
        /*第621题:任务调度器
        * 采用桶思想,桶数=任务数最大的任务总数N,桶长=冷冻时间n+1
        * 最后一个桶不是满的(因为最后一个任务不需要解冻),最后一个桶与同为任务最大数的任务总量types有关
        * 桶实际大小:(N-1)*(n+1)+types
        * 实际总任务量可能会比桶实际大小要大(桶的大小实际上可以理解为至少需要满足的任务时长,由任务最多的那个种类决定)
        *       所以还需要将桶与tasks.size()比较,取最大值
        */
        unordered_map<char, int> task_map;//key:tasks,value:counts
        //1. 计算桶个数
        int N = 0;
        for (char c : tasks) {
            N = max(N, ++task_map[c]);
        }
        //2. 计算types大小
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

