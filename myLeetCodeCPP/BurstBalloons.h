#pragma once
#include "header.h"
class BurstBalloons
{
public:
	int maxCoins(vector<int>& nums) {
		/*第312题：戳气球
		* 1. 根据题意，左右两墙壁代表的气球硬币数是1，因此在左右各加入1个1，这样方便后面计算 1[3,1,5,8]1
		* 2. 采用左开右开的区间（因为左壁右壁都是不可戳破的），用dp[i][j]表示戳破区间(i,j)所有气球的最大收益
		* 3. 假定在区间内我们选择最后戳破的气球为k（每个气球都有可能成为k）
		*    此时计算在最后戳破k的情况下，dp[i][j] = dp[i][k-1] + nums[k-1]*nums[k]*nums[k+1] + dp[k+1][j]
		*    这是因为最后戳破k也意味着k前一个数k-1和k后一个数k+1也是最后戳破的
		*    而由于区间是开区间，所以dp[i][k-1]不包含k-1这个数的，所以通过上式我们得到的是区间(i,k-1)、(k+1,j)所得的最大数量值
		*    再加上戳破k后的值就可以得到在区间(i,j)下最后一个戳破k所能得到的最大数量
		* 4. 根据上面3.的递推公式，我们也就知道需要先拥有dp[i][k-1]和dp[k+1][j]
		*    也就是要先有dp[i][j]同一行左边的所有值，以及dp[i][j]同一列上边的所有值
		*    因此遍历顺序就是从上到下，从左往右。
		* 5. i是左值,j是右值,所以i<j永远成立
		*/
		int n = nums.size();
		vector<vector<int>> dp(n + 2, vector<int>(n + 2));
		nums.insert(nums.begin(), 1); nums.insert(nums.end(), 1);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 2; j <= n + 1; j++) {
				for (int k = i + 1; k < j; k++) {
					int sum = nums[i] * nums[k] * nums[j];
					sum += dp[i][k] + dp[k][j];
					dp[i][j] = max(dp[i][j], sum);
				}
			}
		}
		return dp[0][n + 1];
	}

};

