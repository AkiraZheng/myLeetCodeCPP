#include "BestTimetoBuyandSellStock.h"

int BestTimetoBuyandSellStock::maxProfit(vector<int>& prices) {
	/*第121题：买卖股票的最佳时机
	* 动规方法
	* 1. 数组的意义
	*	 定义一个prices.size()×2大小的二维数组，我们可以知道第i天可能存在的持股情况有两种，一种是保持持股的状态，另一种是保持不持股的状态
	*	 所以dp[i][0]是第i天保持持股状态的累计可得利润，其中若第i天刚好是买入股票，则需要减去当天的prices[i]
	*	 dp[i][1]是第i天保持不持股状态的累计可得利润，其中若第i天刚好是抛出股票，则需要加上当天的prices[i]
	* 2. 递推公式
	*	 2.1 计算dp[i][0]
	*		 当我们遍历到第i天时，当天是保持持股状态的话，有两种可能：
	*		 a. 保持前面几天的持股状态（也就是股票是前几天买的，今天保持不变），那么需要由dp[i-1][0]来计算，此时保持不变的利润延续前一天的利润，也就是dp[i-1][0]
	*		 b. 前一天是不持股状态，今天入股，那么需要有前一天不持股的状态dp[i-1][1]来决定，则此时的利润应该是dp[i-1][1]-prices[i]
	*		 计算a和b两种情况的最大利润值max(dp[i-1][0], dp[i-1][1]-prices[i])（也就是保持前i天中买入股票的最低价格）
	*	 2.2 计算dp[i][1]
	*		 当我们遍历到第i天时，当天是不持股状态的话，也有两种可能：
	*		 a. 前几天是持股的状态，今天抛出股票，那么当天就是不持股的；前几天是持股的状态则需要由dp[i-1][0]来决定，计算利润为dp[i-1][0]+prices[i]
	*		 b. 前几天是不持股的状态，今天延续不持股的状态，那么就需要前一天累计的不持股的利润，也就是保持dp[i-1][1]
	*		 计算a和b两种情况的最大利润值max(dp[i-1][0]+prices[i], dp[i-1][1])（也就是保持前i天中某天卖出股票的最高利润，此时是在前i天中最低价格买入的情况下进行卖出）
	*	 2.3 距离说明
	*	 当天股票价格			[7,  1, 5, 3, 6, 4]
	*	 保持持股的利润			[-7,-1,-1,-1,-1,-1](最低购入价的更新)
	*	 保持不持股状态下的利润 [0,  0, 4, 4, 5, 5]（最高抛出收益的更新）
	* 3. 数组初始化
	*	 初始化dp[0][0]=-prices[0]和dp[0][1]=0
	* 4. 遍历顺序
	*	 天数从前往后遍历
	* 5. 输出
	*	 dp[size-1][1]
	*/
	if (prices.size() == 0) return 0;
	vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
	dp[0][0] = -prices[0];
	for (int i = 1; i < prices.size(); i++) {
		dp[i][0] = max(dp[i - 1][0], -prices[i]);
		dp[i][1] = max(prices[i]+dp[i-1][0], dp[i-1][1]);
	}
	return dp[prices.size() - 1][1];
}
void BestTimetoBuyandSellStock::test_BestTimetoBuyandSellStock() {
	BestTimetoBuyandSellStock BTBSS;
	vector<vector<int>> nums{ {7,1,5,3,6,4},{7,6,4,3,1} };
	for (auto& temp : nums) {
		cout << BTBSS.maxProfit(temp) << endl;
	}
}
