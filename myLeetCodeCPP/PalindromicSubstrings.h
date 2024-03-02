#pragma once
#include "header.h"
class PalindromicSubstrings
{
public:
    int countSubstrings(string s) {
        /*��647��:�����Ӵ�
        * ע��:ĳ���ַ�����Ҳ��һ�ֻ����Ӵ�,��"a"
        * ʹ��˫ָ��ķ���,����s,��������iʱ,��iΪ���ĺ���[i,i+1]Ϊ����,���������������ĵ��������Ӵ�
        */
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += searchPalindrome(s, i, i);//��iΪ�����һ��Ĵ�
            res += searchPalindrome(s, i, i + 1);//��iΪ�����һ��Ĵ�
        }
        return res;
    }

    int searchPalindrome(string& s, int i, int j) {//iΪ��ָ��,jΪ��ָ��
        int n = s.size();
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;//û��һ�ζ���һ���µĻ��Ĵ�
        }
        return res;
    }
};

