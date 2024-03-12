#pragma once
#include "header.h"
class RansomNote
{
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mapR;//背包
        unordered_map<char, int> mapM;//物品

        //构成map
        for (char c : ransomNote) mapR[c]++;
        for (char c : magazine) mapM[c]++;

        //判断是否能由物品组成背包（这里并不是用01背包方法，只是为了方便理解）
        for (const auto temp : mapR) {
            char c = temp.first;
            int count = temp.second;
            if (mapM.find(c) == mapM.end() || mapM[c] < count) return false;//只要有一个数组找不到或者个数不满足就return
        }
        return true;
    }
};

