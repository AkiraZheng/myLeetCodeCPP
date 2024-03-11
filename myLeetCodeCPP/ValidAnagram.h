#pragma once
#include "header.h"
class ValidAnagram
{
public:
    bool isAnagram(string s, string t) {
        /*��242�⣺��Ч����ĸ��λ��
        * ������unordered_map�洢�ַ���str�� key:str[i], value:key���ֵĴ���
        * �Ƚ�������map�Ƿ���ȫ��ͬ
        */

        //���s��map
        unordered_map<char, int> sMap;
        for (char c : s) {
            sMap[c]++;//��������c���ֵĴ���
        }
        //���t��map
        unordered_map<char, int> tMap;
        for (char c : t) {
            tMap[c]++;
        }
        //�Ƚ��Ƿ���ͬ
        if (sMap.size() != tMap.size()) return false;//���ַ�������һ�����϶���ͬ
        for (pair<char, int> temp : sMap) {
            char c = temp.first;
            int count = temp.second;
            if (tMap.find(c) != tMap.end() && tMap[c] == count) continue;
            return false;
        }
        return true;
    }
};

