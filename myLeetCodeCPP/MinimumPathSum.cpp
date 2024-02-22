#include "MinimumPathSum.h"

int MinimumPathSum::minPathSum(vector<vector<int>>& grid) {
	/*第64题：最小路径和
	* 这道题与第62题不同路径类似，采用动规法，不同的是用dp数组来表示当前[i][j]位所有走法中的最小和
	* 其中dp[i][j]的上一步一定是dp[i-1][j]或dp[i][j-1]，因此找二者与grid[i][j]和最小的值作为当前[i][j]位所有走法中的最小和
	*/
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = grid[0][0];
	//1. 第一行和第一列都只有一种走法
	for (int j = 1; j < n; j++) {
		//补齐第一行
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < m; i++) {
		//补齐第一列
		dp[i][0] = dp[i-1][0] + grid[i][0];
	}
	//2. 补齐dp数组：一列一列开始补
	for (int j = 1; j < n; j++) {
		for (int i = 1; i < m; i++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}
	return dp[m - 1][n - 1];
}
void MinimumPathSum::test_MinimumPathSum() {
	MinimumPathSum MPS;
	vector<vector<int>> nums{ {1,3,1 },{1, 5, 1}, {4, 2, 1} };
	vector<vector<int>> nums1{ {1,2,3},{4,5,6}};
	cout << MPS.minPathSum(nums) << endl;
	cout << MPS.minPathSum(nums1) << endl;
}
