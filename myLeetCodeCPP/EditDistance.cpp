#include "EditDistance.h"

int EditDistance::minDistance(string word1, string word2) {
	/*第72题：编辑距离
	* 采用动态规划方法：数组意义、推导公式、初始化数组、遍历顺序
	* 我们首先认为字符串从0开始，也就是word1的第0个字符串和word2的第0个字符串
	* 其次也要意识到通过增删改的方法，肯定能让两个不一样长的字符串达到相同的效果（这为后面dp[i][j]意义的假设做铺垫）
	* 1. 数组意义
	*	 用dp[i][j]表示，假设通过增、删、换后，要令word1的前[0,i]范围内的字符串 与 word2的前[0,j]范围内的字符串相同时的所需的最少操作数
	* 2. 推导公式
	*	 当循环到dp[i][j]时，也就意味着在当计算到dp[i][j]时，我们已经将word1的前[0,i-1]范围内的字符串 转换成与 word2的前[0,j-1]范围内的字符串相同了
	*	 ||||||||||||word1[i]
	*	 |||word2[j]
	*	 当前循环下，有两种可能性：word1[i]==word2[j]和word1[i]!=word2[j]
	*	 2.1 word1[i]==word2[j]
	*		 这种情况下，由于word1的前i-1已经被转换成与word2的前j-1相同了，那么此时所需的最小操作数就是word1[i]不做任何操作，dp[i][j]=dp[i-1][j-1]
	*		 ps：word1的前i-1 转换成与 word2的前j-1相同 所需的最小操作数在前面的dp[i-1][j-1]中以算出来了
	*	 2.2 word1[i]!=word2[j]
	*		 这种情况下就需要考虑对字符word1[i]进行什么操作了？
	*		 2.2.1 删word1[i]：删word1[i]的前提是dp[i-1][j]已知，也就是word1的前i-1 已经转换成与 word2的前j相同
	*			   此时删掉word1[i]操作数在dp[i-1][j]的基础上加1，dp[i][j]（可能）=dp[i-1][j] + 1
	*		 2.2.2 换word1[i]：将word1[i]替换成与word2[j]一样的字符，这里的前提是dp[i-1][j-1]已知，也就是word1的前i-1 已经转换成与 word2的前j-1相同
	* 			   此时换掉word1[i]操作数在dp[i-1][j-1]的基础上加1，dp[i][j]（可能）=dp[i-1][j-1] + 1
	* 		 2.2.3 增word1[i]：当需要word1[i]增一个字符时，说明对应的word2是多出来了一个字符，那么我们可以把增word1的操作转换为删word2的操作
	*			   删掉这个多余的word2字符后，word1自然也就不需要增了，但是达到了相同的效果
	*			   删word2[j]的前提是已经直到dp[i][j-1]，也就是word1的前i 已经转换成与 word2的前j-1相同
	*			   此时删掉word2[j]操作数在dp[i][j-1]的基础上加1，dp[i][j]（可能）=dp[i][j-1] + 1
	*		 2.3 word1[i]处删换增的操作只能选一个，那么选的肯定是令它的dp[i][j]值，也就是操作数最小的操作，也就是取经过这三个可能的操作后令dp[i][j]最小的作为当前操作
	* 3. 初始化数组和遍历顺序
	*	 由2.可知，推导更新操作与dp[i-1][j-1]、dp[i-1][j]和dp[i][j-1]相关，那么此时推导dp[i][j]的前提就是知道这三个值。
	*	 所以需要先把第一列和第一行初始化，并从[1,1]开始一行一行地循环
	*	 我们需要在word1和word2字符串最前面分别加一个空字符，那么也就是dp需要多出一行和一列，主要是为了初始化用
	*	 如word1的每一位与word2的空字符之间的最少操纵数都是i（也就是每一步都要进行一次删除操作，直至变为空才能与word2的空字符转换成相同的）
	*/

	vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
	for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;//补齐第一行
	for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;//补齐第一列
	for (int i = 1; i <= word1.size(); i++) {
		for (int j = 1; j <= word2.size(); j++) {
			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
			}
		}
	}
	return dp[word1.size()][word2.size()];
}
void EditDistance::test_EditDistance() {
	EditDistance ED;
	vector<vector<string>> words{ {"horse", "ros"},{"intention","execution"} };
	for (const auto &wordi : words) {
		cout << ED.minDistance(wordi[0], wordi[1]) << endl;
	}
}
