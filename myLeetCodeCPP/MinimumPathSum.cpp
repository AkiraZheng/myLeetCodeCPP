#include "MinimumPathSum.h"

int MinimumPathSum::minPathSum(vector<vector<int>>& grid) {
	/*��64�⣺��С·����
	* ��������62�ⲻͬ·�����ƣ����ö��淨����ͬ������dp��������ʾ��ǰ[i][j]λ�����߷��е���С��
	* ����dp[i][j]����һ��һ����dp[i-1][j]��dp[i][j-1]������Ҷ�����grid[i][j]����С��ֵ��Ϊ��ǰ[i][j]λ�����߷��е���С��
	*/
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = grid[0][0];
	//1. ��һ�к͵�һ�ж�ֻ��һ���߷�
	for (int j = 1; j < n; j++) {
		//�����һ��
		dp[0][j] = dp[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < m; i++) {
		//�����һ��
		dp[i][0] = dp[i-1][0] + grid[i][0];
	}
	//2. ����dp���飺һ��һ�п�ʼ��
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
