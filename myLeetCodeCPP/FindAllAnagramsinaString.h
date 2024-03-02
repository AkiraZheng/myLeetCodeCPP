#pragma once
#include "header.h"
class FindAllAnagramsinaString
{
public:
    vector<int> findAnagrams(string s, string p) {
        /*第438题:找到字符串中所有字母异位词
        * 滑动窗口,窗口大小就是p.size()
        * 用unordered_map维护目标p所有要配齐的字母key,以及字母对应需要的个数value
        *                维护窗口中存在的与目标p相同字母key,以及key在窗口中对应的数量value
        * 窗口中某个字母的key可能会比目标的数量多,所以还要一个int valid参数来维护窗口中完全满足目标字母需求的个数(map_p.size())
        */

        vector<int> result;//存放匹配窗口的左指针
        if (s.size() < p.size()) return result;

        unordered_map<char, int> map_p, map_window;
        //1. 生成目标p的哈希表
        for (char c : p) {
            map_p[c]++;
        }
        int valid = 0, valid_target = map_p.size();
        //2. 滑动窗口计算匹配的位置
        int left = 0, right = 0;
        while (right < s.size()) {
            //a.右窗口
            //处理当前窗口的右值入窗口
            char right_c = s[right];
            if (map_p.find(right_c) != map_p.end()) {
                //该字符在目标字符内
                map_window[right_c]++;
                if (map_window[right_c] == map_p[right_c]) valid++;
            }
            //右窗口扩
            right++;

            //缩左窗口
            while (right - left + 1 > p.size()) {//当窗口比目标窗口大时,需要缩左窗口,窗口左闭右开[left,right)
                char left_c = s[left];
                //出窗口前先判断当前窗口是否满足要求了
                if (valid == valid_target) result.push_back(left);//添加结果
                //左点出窗口:处理left字符,如果在目标p的话,需要窗口中对应的值减1;不在目标值的话,那么说明它其实也不在窗口值中,可以直接忽略
                if (map_p.find(left_c) != map_p.end()) {
                    //减之前还要先考虑当前字符是不是在已经valid的值中
                    if (map_window[left_c] == map_p[left_c]) valid--;//在valid的值中
                    map_window[left_c]--;
                }
                left++;//处理完后就可以出窗口了
            }
        }
        return result;
    }
};

