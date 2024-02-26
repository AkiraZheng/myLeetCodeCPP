#include "HouseRobber.h"

int HouseRobber::rob(vector<int>& nums) {
	/*第198题：打家劫舍
	* 动规方法
	* 1. 数组含义
	*	 用dp[i]表示包括i在内及其前面所能偷窃的最大金额
	* 2. 递推公式
	*	 当盗窃到i家时，他有两种选择，一种是盗，一种是不盗
	*	 2.1 不盗：如果是不盗的话，那么dp[i]将会延续上一家所能盗窃的最大金额，也就是num[i-1]
	*	 2.2 盗  ：如果盗的话，那么我们铁定不经过第i-1家了，所以可以忽略他，因为如果上一家不盗的话，那么它的金额会延续nums[i-2]，而如果盗的话金额会变成另一个值
	*			   那么我们现在举例的是当前i盗，所以上一家必须不盗，而上一家不盗的话其金额就是nums[i-2]，因此在i盗的情况的话，当前的金额将变为nums[i-2]+nums[i]
	*	 2.3 dp[i]
	*		 我们要求的dp[i]表示包括i在内及其前面所能偷窃的最大金额，因此当前i的状态应该取“盗”“不盗”两种情况下金额的最大值
	*		 dp[i] = max(num[i-1],nums[i-2]+nums[i])
	* 3. 初始化数组
	*	 根据递推公式，我们需要知道num[i-1]和nums[i-2]，所以初始化需要有前两个数，也就是nums[0]和nums[1]
	*	 由于dp[i]表示包括i在内及其前面所能偷窃的最大金额，因此第0家肯定要取盗的情况 dp[0]=max(0,nums[0])=nums[0]
	*	 如果第1家的金额比第0家多的话，那么选择盗第一家nums[1]；反之选盗第0家，第1家不盗，金额延续dp[0]的金额；也就是dp[1]=max(nums[1],dp[0])
	* 4. 递归顺序：从i=2开始往后退
	* 5. 输出：dp[nums.size()-1]
	*/
	if (nums.size() == 1) return nums[0];
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = max(dp[0], nums[1]);
	for (int i = 2; i < nums.size(); i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	return dp[nums.size() - 1];
}
void HouseRobber::test_HouseRobber() {
	HouseRobber HB;
	vector<vector<int>> nums{ {1,2,3,1},{2,7,9,3,1} };
	for (auto &num : nums) {
		cout << HB.rob(num) << endl;
	}
}
