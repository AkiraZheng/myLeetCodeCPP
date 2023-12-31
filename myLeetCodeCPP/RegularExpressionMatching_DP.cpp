#include "RegularExpressionMatching_DP.h"
bool RegularExpressionMatching_DP::isMatch(const string s, const string p) {
    int m = s.size() + 1; // 状态数组 dp 的行数，其中包含第一位自添加的 ''
    int n = p.size() + 1; // 状态数组 dp 的列数，其中包含第一位自添加的 ''
    //bool dp[m + 0][n + 0];//g++和letcode的编译器可以编译成功
    //fill_n(&dp[0][0], m * n, false); // 补0//g++和letcode的编译器可以编译成功
    
    //visual studio中二维数组不能用变量来定义，只能用常量，因此这里用vector来定义
    //用vector的方法运行时间和占用内存都增加了
    vector<vector<bool>> dp(m, vector<bool>(n, false));

    // 由于状态数组在行列首位中都添加了''，因此后面的循环中，状态数组为i-j时，对应s中[i-1]以及p中[j-1]的字符
    // 1. 初始化状态数组的首行
    /*规则：
    若要dp[0][j] == true，则只有当p[j-1]='*'时才有机会，此时的'*'只能指代前一字符为0个的情况（这样才有可能表示p的前j-1个字符串能匹配全空字符串s的前0个字符串）
    在p[j-1]='*'且满足dp[0][j-2]==true，也就是首行的前j-2个字符串也能匹配全空时，此时的dp[0][j]才能表示全空，也就是设为true
    */
    dp[0][0] = true;
    dp[0][1] = (p[0] == '*'); // 防止在p[0]就遇到'*'
    for (int j = 2; j < n; j++)
    {
        if (p[j - 1] == '*' && dp[0][j - 2])
            dp[0][j] = true;
    }
    // 2. 动态规划填充剩下的状态转移数组：从第二行开始一行一行扫过去
    // 2.1 若p[j-1]=='*'，想要dp[i][j]=true，则有三种情况能实现
    /*规则：
    2.1.1 第一种情况是'*'代表前一个字符的0个
    这种情况下，需要该行(i)的第前2个状态为true，也就是dp[i][j-2]==true
    （这种情况其实还有个隐形条件就是前1个状态dp[i][j-1]==false，但是这个条件的反向条件是dp[i][j-1]==true，该情况是下面要讲的'*'代表1个字符的情况）
    （因此只要dp[i][j-2]==true，无论dp[i][j-1]为什么，这里的dp[i][j]都能赋值为true）
    2.1.2 第二种情况是'*'代表前一个字符的1个
    这种情况下，需要该行(i)的第前1个状态为true，也就是dp[i][j-1]==true
    （这种情况可以跟第一种情况合并为dp[i][j-2]==true，不需要再判断dp[i][j-1]的情况了）
    2.1.3 第三种情况是'*'代表前一个字符的多个
    这种情况下，首先需要保证本轮[i][j]下，上一轮[i-1][j]的状态也为匹配，也就是前p[j-1]个字符能匹配前s[i-2]个字符，这里不用p[j-2]是因为p[j-1]的'*'可能可以匹配多个s[i-k]状态
    同时需要本轮的s表示的字符[i-1]跟p的上一个字符[j-2]需要相匹配，这里的相匹配指p[j-2]==s[i-1] 或者 p[j-2]=='.'
    */

    // 2.2 若p[j-1]!='*'，则情况比较简单
    /*规则
    这种情况则类似2.1.3的判断规则，首先需要保证本轮[i][j]下，上一轮[i-1][j-1]的状态也为匹配，也就是前p[j-2]个字符能匹配前s[i-2]个字符
    同时需要保证本轮s表示的字符[i-1]跟本轮p的字符[j-1]需要相匹配，这里的相匹配指p[j-2]==s[i-1] 或者 p[j-2]=='.'
    */
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
    }

    return dp[m - 1][n - 1];
}