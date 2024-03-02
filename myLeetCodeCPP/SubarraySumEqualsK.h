#pragma once
#include "header.h"
class SubarraySumEqualsK
{
public:
    int subarraySum(vector<int>& nums, int k) {
        /*第560题:和为k的子数组
        * 由于要求子数组必须是连续的,因此我们可以维护一个前缀值,map[pre]=count
        * 也就是遍历nums[i],map中存j以前所有从[0,j]范围内的累加值
        * 当我们遍历到i时:
        *       我们需要更新全局累加的pre_i=sum([0,i]);而已知map中存的key是pre=sum([0,j])
        *       所以我们要确认以i为结尾,前面是否有连续的区间可以与i组成和为k的数
        *       若前面有区间(j,i]的和为k,那么根据数组排列 [0,j](j,i]可知,全局pre_i就是从0到i的总和
        *       所以只要存在sum([0,j])+k=pre_i就可以确定存在区间(j,i]的和为k
        *       所以sum([0,j])=pre_i-k,而sum([0,j])在前面已经存在map里了,所以我们只要确认map(pre_i-k)是否存在就行
        * 为什么map的value要存count?因为数组含负数,所以前缀和为某个key的可能有很多处,每一处都可以作为组成区间(j,i]所需要的起点j
        */

        int pre_i = 0;
        int count = 0;//更新全局总共有多少个子数组
        unordered_map<int, int> pre_map;//key为[0,j]的前缀和,count为前缀和为key的对应j有多少个(因为有负数,所以可以有很多个)
        pre_map[0] = 1;//初始化第0个点的前缀是0
        for (int i = 0; i < nums.size(); i++) {
            pre_i += nums[i];//[0,i]累和
            if (pre_map.find(pre_i - k) != pre_map.end()) {
                //存在
                count += pre_map[pre_i - k];//累加有多少个满足前缀和为pre_i-k的
            }
            pre_map[pre_i]++;
        }
        return count;
    }
};

