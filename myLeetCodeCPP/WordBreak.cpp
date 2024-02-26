#include "WordBreak.h"

bool WordBreak::wordBreak(string s, vector<string>&wordDict) {
	/*��139�⣺���ʲ��
	* ����һ���������⣬��Ʒ���ֵ䣬�������ַ���s��Ҫ������Ʒ�ܷ񽫱���װ��
	* �ö��淽�����
	* 1. ���������
	*	 ��һά����dp[i]����ʾ�ַ���s��ǰi�����ܷ���Ʒ�������ܷ����ֵ���ɣ�
	* 2. ���ƹ�ʽ
	*	 ÿ��dp[i]ֵ��ȷ����Ҫ����iǰ����ֿ��ܳ��ֵ���ϣ���һ��j������ǰ����ܻ���ֵ���ϣ�j��0����i����
	*	 �������dp[j]==1��Ҳ����˵ǰj�����Ѿ���֤�����ǿ������ֵ乹�ɵģ���ô������ͬʱ�ַ���s[j+1,i]���ֵ�����ƥ��ģ����˵��ǰi���ַ��ǿ������ֵ乹�ɵģ���dp[i]��Ϊ1
	* 3. �����ʼ��
	*	 ����Ҫ������ǰ����һ��������Ϊdp[0]��������Ϊ1
	* 4. ����˳��
	*	 ���ַ�����һ�����ֿ�ʼ���ұ���
	* 5. ���
	*	 dp[s.size()]����Ӧ����s��ǰs.size()-1�����
	*/
	unordered_set<string> dict(wordDict.begin(), wordDict.end());//���ֵ����set�У������ѯ
	vector<bool> dp(s.size()+1, false);
	dp[0] = true;
	for (int i = 1; i <= s.size(); i++) {//��s�ĵ�һ���ַ���ʼ��Ҳ����s[0]��ʼ
		for (int j = 0; j < i; j++) {//j�Ǹ�s��index��Ӧ�ģ���i�Ǳ�s��index��1��
			string word = s.substr(j, i - j);//��ȡ�ַ���s[j,i-1]
			if (dict.find(word) != dict.end() && dp[j]) {//����j��Ӧ����s��indexΪj��λ�ã���dp[j]�о��൱��dp��index�����ַ�������ǰŲ��λ
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
