#include "MaximalRectangle.h"

int MaximalRectangle::maximalRectangle(vector<vector<char>>& matrix) {
	/*第85题：最大矩形
	* 采用动规法，用dp数组来解题：数组的意义、递推公式、初始化数组、遍历顺序、输出
	* 1. dp数组的意义
	*	 定义一个rows×cols的二维数组，dp[i][j]用于存储包含该点在内，同一行中j及其前面的连续1的总数
	* 2. 递推公式
	*	 2.1 由于dp[i][j]表示同一行中j及其前面的连续1的总数，也就是说如果 matrix[i][j]!=1，则dp[i][j]=0
	*	 2.2 而当 matrix[i][j]==1 时，由于其前一个数dp[i][j-1]代表的是 同一行中j-1及其前面的连续1的总数，因此 dp[i][j] = dp[i][j-1]+1;
	* 3. 初始化数组 和 遍历顺序
	*	 由递推公式可知，要求dp[i][j]则必须直到同一行j前面一个的dp[i][j-1]值，因此遍历顺序是按一行一行从左往右扫过去
	*	 因此刚开始扫描时必须直到dp[i][0]，也就是第一列的值（因为第一列没有dp[0][0-1]的已知值）
	*	 将dp[i][0]初始化为 dp[i][0] = (matrix[i][0]==1) ? 1 : 0
	* 4. 输出
	*	 本题中光有dp数组还不够，每更新完一个dp[i][j]的值，还要从该点开始，往上面一行一行更新由该点往上所能组成的最大矩形的值
	*	 而由该点往上所能组成的矩形就是比如说要求 dp[i][j]处与上面一行所能围成的矩形面积，那么就是要求 min(dp[i][j]到dp[i-1][j]);因为相邻行能否围成矩形由短边决定
	*	 那么同理当一行一行往上搜索的时候就可以不断更新最短边并计算 dp[i][j]处与上面某行所能围成的矩形面积
	*	 由参数maxRect存储更新最新的最大矩形面积并return maxRect
	*/

	int maxRect = 0;
	int rows = matrix.size(); int cols = matrix[0].size();
	vector<vector<int>> dp(rows, vector<int>(cols, 0));
	//初始化数组
	int maxLen = 0;//用于记录第一列的最大连续1的个数
	for (int i = 0; i < rows; i++) {
		if (matrix[i][0] == '1') {
			dp[i][0] = 1;
			maxLen++;
		}
		else {
			dp[i][0] = 0;
			maxRect = max(maxLen, maxRect);
			maxLen = 0;
		}
	}
	maxRect = max(maxLen, maxRect);//更新第一列的最大矩形

	//遍历整个二维数组
	for (int i = 0; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			dp[i][j] = (matrix[i][j] == '1') ? dp[i][j - 1] + 1 : 0;

			//从dp[i][j]往上搜索更新最大矩形面积
			int min_w = dp[i][j];
			for (int row = i; row >= 0; row--) {//往上遍历到第row行
				min_w = min(min_w, dp[row][j]); int h = i - row + 1;
				maxRect = max(maxRect, min_w * h);
			}
		}
	}
	//printVector(dp);
	return maxRect;
}

void MaximalRectangle::test_MaximalRectangle() {
	MaximalRectangle MR;
	vector<vector<char>> matrix1{ {'1','0','1','0','0'} ,{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
	vector<vector<char>> matrix2{ {'0'} };
	vector<vector<char>> matrix3{ {'1'} };
	cout << MR.maximalRectangle(matrix1) << endl;
	cout << MR.maximalRectangle(matrix2) << endl;
	cout << MR.maximalRectangle(matrix3) << endl;
}

void MaximalRectangle::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << endl;
	}
}
