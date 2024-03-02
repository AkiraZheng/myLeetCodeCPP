#pragma once
#include "header.h"
class PalindromicSubstrings
{
public:
    int countSubstrings(string s) {
        /*第647题:回文子串
        * 注意:某个字符本身也是一种回文子串,如"a"
        * 使用双指针的方法,遍历s,当遍历到i时,以i为中心和以[i,i+1]为中心,向两边搜索该中心的最大回文子串
        */
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += searchPalindrome(s, i, i);//以i为中心找回文串
            res += searchPalindrome(s, i, i + 1);//以i为中心找回文串
        }
        return res;
    }

    int searchPalindrome(string& s, int i, int j) {//i为左指针,j为右指针
        int n = s.size();
        int res = 0;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
            res++;//没扩一次都是一个新的回文串
        }
        return res;
    }
};

