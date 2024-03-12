#pragma once
#include "header.h"
class RansomNote
{
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mapR;//����
        unordered_map<char, int> mapM;//��Ʒ

        //����map
        for (char c : ransomNote) mapR[c]++;
        for (char c : magazine) mapM[c]++;

        //�ж��Ƿ�������Ʒ��ɱ��������ﲢ������01����������ֻ��Ϊ�˷�����⣩
        for (const auto temp : mapR) {
            char c = temp.first;
            int count = temp.second;
            if (mapM.find(c) == mapM.end() || mapM[c] < count) return false;//ֻҪ��һ�������Ҳ������߸����������return
        }
        return true;
    }
};

