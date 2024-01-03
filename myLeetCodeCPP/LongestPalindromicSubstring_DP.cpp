#include "LongestPalindromicSubstring_DP.h"
string LongestPalindromicSubstring_DP::longestPalindrome(const string& s) {
    const int s_size = s.size();
    //vs�޷��ó���������ά���飬�����vector���棬���ٶȻ���һЩ
    //bool f[s_size][s_size];//�洢f[i,j]���ַ����Ƿ���ϻ�������
    //fill_n(&f[0][0], s_size * s_size, false);//��ʼ��f[i,j]���ַ����������ϻ�������
    
    vector<vector<bool>> f(s_size, vector<bool>(s_size, false));//��ʼ��f[i,j]���ַ����������ϻ�������
    int max_len = 1; int longestPalindrome_start = 0;//�����ַ����Ĵ�Ϊ1����j=0��ʼ����
    /**
        �����ַ����������������ľ���
        ��s[i]=s[j]ʱ�����������������
    **/
    //1. ��i=j����ʾͬһ���ַ����϶�Ϊ���Ĵ�����˶Խ���ȫΪtrue
    //2. ��i=j-1����ʾf[i,j]�м�ֻ��һ���ַ������ҲΪ���Ĵ�
    //3. ��i<j-1��f[i+1,j-1]=true��˵��ǰ�������f[i+1,j-1]Ϊ���Ĵ����Ҵ�ʱs[i]=s[j]�����ҲΪ���Ĵ�
    for (int j = 0; j < s_size; j++) {
        f[j][j] = true;
        for (int i = 0; i < j; i++) {
            f[i][j] = (s[i] == s[j] && ((j - i < 2) || (f[i + 1][j - 1])));
            if (max_len < (j - i + 1) && f[i][j]) {
                //f[i,j]Ϊ���Ĵ��ҳ��ȴ��ڵ�ǰ���ֵ��̰�ķ����������Ĵ�
                max_len = j - i + 1;
                longestPalindrome_start = i;
            }
        }
    }
    return s.substr(longestPalindrome_start, max_len);
}
