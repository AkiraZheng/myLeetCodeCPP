#include "UniquePaths.h"

int UniquePaths::uniquePaths(int m, int n) {
	/*第62题：不同路径
	* 采用动规法，动规法四部曲：dp数组意义、递推公式、数组初始化值、遍历顺序
	* 1. dp数组意义
	*	 定义一个m*n的dp数组，dp[i][j]表示机器人从start的（0，0）到（i，j）位置总共可能的走法总数
	* 2，递推公式
	*	 由于机器人只能往右或者往下走，是比较有规律的走动
	*	 因此对于dp[i][j]而言，机器人走到(i,j)处只可能是从(i,j)的正上方(i-1,j)或者正左方(i,j-1)走一步过来
	*	 因此dp[i][j]是由(i-1,j)和(i,j-1)两个位置的走法总和决定的，也就是 dp[i][j] = dp[i-1][j] + dp[i][j-1]
	* 3. 数组初始化值
	*	 由于机器人只能往右或者往下走，因此第一行和第一列的所有格子都只有1中做法，dp[0][]和dp[][0]都初始化为1
	* 4. 遍历顺序
	*	 由于dp[i][j] = dp[i-1][j] + dp[i][j-1]，因此需要保证计算dp[i][j]时，dp[i-1][j]和dp[i][j-1]已经被计算完了
	*	 因此遍历顺序从左向右扩散，也就是从(1,1)开始，一列一列计算，因为一列上按从上往下计算，能保证它的上方和左方都被计算过了
	*/

	vector<vector<int>> dp(m, vector<int>(n, 0));
	//3. 数组初始化值:dp[0][]和dp[][0]都初始化为1
	for (int i = 0; i < m; i++) {
		//第一列全为1
		dp[i][0] = 1;
	}
	for (int j = 0; j < n; j++) {
		//第一行全为1
		dp[0][j] = 1;
	}
	//2.和3. 一列一列遍历递推dp：dp[i][j] = dp[i-1][j] + dp[i][j-1]
	for (int j = 1; j < n; j++) {
		//按列
		for (int i = 1; i < m; i++) {
			//遍历一列的每行
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

void UniquePaths::test_UniquePaths() {
	UniquePaths UP;
	vector<vector<int>> mn{ {3, 7}, {3,2},{7,3},{3,3} };
	for (const auto temp : mn) {
		cout << UP.uniquePaths(temp[0], temp[1]) << endl;
	}
}
