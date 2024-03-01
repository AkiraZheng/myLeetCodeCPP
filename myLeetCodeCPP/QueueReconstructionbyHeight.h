#pragma once
#include "header.h"
class QueueReconstructionbyHeight
{
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        //自定义数组sort方式:先按身高降序排,相同身高的前面站的更高的人数少的放在前面
        if (a[0] == b[0]) return a[1] < b[1];//降序排第二个参数
        return a[0] > b[0];//升序排第一个参数(身高)
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*第406题:根据身高重建队列
        * 首先确定对数组二次排序的顺序,因为关键点在某个人前面比它高的人的数量,所以我们首先可以根据身高从高往低重新排数组
        * 遇到相同身高的怎么处理?肯定是具有更少的比它本人身高高或相同的那个人站在前面,这样同样身高下,站在后面的那个允许更多同身高的人在前面,所以是符合逻辑的
        * 也就是先把数组排成[[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
        * 然后在找一个list数据,通过不断地将对应的人插到对应的位置(一个个取出前面粗排好的顺序来进行细排)
        插入[7,0]：[[7,0]]
        插入[7,1]：[[7,0],[7,1]]        说明:此时[7,0]和[7,1]都是满足条件了,就算后面有矮的人插进来,也不会影响(已经满足前面只有0个/1个比它高的人)
        插入[6,1]：[[7,0],[6,1],[7,1]]
        插入[5,0]：[[5,0],[7,0],[6,1],[7,1]]
        插入[5,2]：[[5,0],[7,0],[5,2],[6,1],[7,1]]
        插入[4,4]：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
        */
        sort(people.begin(), people.end(), compare);//粗排序
        list<vector<int>> sortedList;
        for (auto temp : people) {
            int count = temp[1];
            list<vector<int>>::iterator it = sortedList.begin();
            while (count > 0) {
                it++;
                count--;
            }
            sortedList.insert(it, temp);//插入
        }
        vector<vector<int>> result(sortedList.begin(), sortedList.end());
        return result;
    }
};

