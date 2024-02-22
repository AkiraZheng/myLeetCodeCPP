#include "ClimbingStairs.h"

int ClimbingStairs::climbStairs(int n) {
	/*第70题：爬楼梯
	* 采用动态规划方法：通过dp的一维数组来存储走到i处的总方法数，注意你现在是在index=-1阶（还没上第一阶）
	* 1. 数组含义
	*	 dp[i]表示走到i处的总方法数
	* 2. 推导规则
	*	 由于只能走1-2步，因此第i阶楼梯只可能从第i-1或第i-2阶楼梯走上来，因此走到第i阶共有dp[i-1]+dp[i-2]种方法
	*	 dp[i] = dp[i-1] + dp[i-2]
	* 3. 数组初始化：注意你现在是在index=-1阶（还没上第一阶）
	*	 dp[0]第一阶台阶只有一种可能，为1
	*	 dp[1]第二阶台阶有2种可能，一种是从第一阶一步上来，一种是从-1阶直接两步上来
	* 4. 遍历顺序
	*	 由于是一维数组，遍历顺序很简单，从i=2开始遍历就行
	*/

	if (n == 1) return 1;
	vector<int> dp(n, 0);
	dp[0] = 1; dp[1] = 2;
	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n - 1];
}
void ClimbingStairs::test_ClimbingStairs() {
	ClimbingStairs CS;
	vector<int> n{ 1, 2, 3, 4, 5, 6 };
	for (int temp : n) {
		cout << CS.climbStairs(temp) << endl;
	}
}
