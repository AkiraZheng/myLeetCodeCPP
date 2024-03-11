#pragma once
#include "header.h"
class ValidAnagram
{
public:
    bool isAnagram(string s, string t) {
        /*第242题：有效的字母异位词
        * 用两个unordered_map存储字符串str的 key:str[i], value:key出现的次数
        * 比较这两个map是否完全相同
        */

        //获得s的map
        unordered_map<char, int> sMap;
        for (char c : s) {
            sMap[c]++;//计数符号c出现的次数
        }
        //获得t的map
        unordered_map<char, int> tMap;
        for (char c : t) {
            tMap[c]++;
        }
        //比较是否相同
        if (sMap.size() != tMap.size()) return false;//连字符数都不一样，肯定不同
        for (pair<char, int> temp : sMap) {
            char c = temp.first;
            int count = temp.second;
            if (tMap.find(c) != tMap.end() && tMap[c] == count) continue;
            return false;
        }
        return true;
    }
};

