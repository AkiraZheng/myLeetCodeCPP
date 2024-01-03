#include "LongestPalindromicSubstring_DP.h"
string LongestPalindromicSubstring_DP::longestPalindrome(const string& s) {
    const int s_size = s.size();
    //vs无法用常量创建二维数组，因此用vector代替，但速度会慢一些
    //bool f[s_size][s_size];//存储f[i,j]内字符串是否符合回文条件
    //fill_n(&f[0][0], s_size * s_size, false);//初始化f[i,j]内字符串均不符合回文条件
    
    vector<vector<bool>> f(s_size, vector<bool>(s_size, false));//初始化f[i,j]内字符串均不符合回文条件
    int max_len = 1; int longestPalindrome_start = 0;//单个字符回文串为1，从j=0开始便利
    /**
        便利字符串，填满回文与否的矩阵
        当s[i]=s[j]时，有以下三种情况：
    **/
    //1. 若i=j，表示同一个字符，肯定为回文串，因此对角线全为true
    //2. 若i=j-1，表示f[i,j]中间只有一个字符，因此也为回文串
    //3. 若i<j-1且f[i+1,j-1]=true，说明前面遍历过f[i+1,j-1]为回文串，且此时s[i]=s[j]，因此也为回文串
    for (int j = 0; j < s_size; j++) {
        f[j][j] = true;
        for (int i = 0; i < j; i++) {
            f[i][j] = (s[i] == s[j] && ((j - i < 2) || (f[i + 1][j - 1])));
            if (max_len < (j - i + 1) && f[i][j]) {
                //f[i,j]为回文串且长度大于当前最大值，贪心法更新最大回文串
                max_len = j - i + 1;
                longestPalindrome_start = i;
            }
        }
    }
    return s.substr(longestPalindrome_start, max_len);
}
