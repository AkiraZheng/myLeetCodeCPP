#include "WordBreak.h"

bool WordBreak::wordBreak(string s, vector<string>&wordDict) {
	/*第139题：单词拆分
	* 这是一个背包问题，物品是字典，背包是字符串s，要求问物品能否将背包装满
	* 用动规方法解决
	* 1. 数组的意义
	*	 用一维数组dp[i]来表示字符串s的前i个数能否被物品填满（能否由字典组成）
	* 2. 递推公式
	*	 每个dp[i]值的确定需要遍历i前面各种可能出现的组合，用一个j来遍历前面可能会出现的组合，j由0逐渐向i靠近
	*	 如果出现dp[j]==1，也就是说前j个数已经被证明了是可以由字典构成的，那么当我们同时又发现s[j+1,i]在字典中有匹配的，这就说明前i个字符是可以由字典构成的，将dp[i]改为1
	* 3. 数组初始化
	*	 还需要在数组前面添一个数字作为dp[0]，将其置为1
	* 4. 遍历顺序
	*	 从字符串第一个数字开始往右遍历
	* 5. 输出
	*	 dp[s.size()]，对应的是s中前s.size()-1的情况
	*/
	unordered_set<string> dict(wordDict.begin(), wordDict.end());//将字典存入set中，方便查询
	vector<bool> dp(s.size()+1, false);
	dp[0] = true;
	for (int i = 1; i <= s.size(); i++) {//从s的第一个字符开始，也就是s[0]开始
		for (int j = 0; j < i; j++) {//j是跟s的index对应的，而i是比s的index多1的
			string word = s.substr(j, i - j);//截取字符串s[j,i-1]
			if (dict.find(word) != dict.end() && dp[j]) {//这里j对应的是s中index为j的位置，在dp[j]中就相当于dp中index比在字符串中往前挪移位
				dp[i] = true;
				break;
			}
		}
	}
	return dp[s.size()];
}
void WordBreak::test_WordBreak() {
	WordBreak WB;
	vector<string> s{ "leetcode",  "applepenapple" , "catsandog" };
	vector<vector<string>> wordDict{ {"leet", "code"} ,{"apple", "pen"} ,{"cats", "dog","sand", "and", "cat" } };
	/*for (int i = 0; i < s.size(); i++) {
		cout << WB.wordBreak(s[i], wordDict[i]) <<endl;
	}*/
	string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> words = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
	cout << WB.wordBreak(s1, words) << endl;
}
