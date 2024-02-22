#include "JumpGame.h"
int JumpGame::maxSubArray(vector<int>& nums){
	/*第53题：最大数组和
	* 0. 采用动规法：将子串想象成按照不同大小的窗口滑动，需要找到某个令sum值最大的窗口
	* 1. 我们遍历整个数组
	*	 1.1 用 f 来存储离当前位置i最近前面窗口中子串的总合（这里的窗口不是从0开始的，而是从前面遍历过的某个0<=j<=i-1开始的）
	*	 1.2 用 maxResult 来存储当前i以前存在的子串最大数之和
	*		 注意，由于当前位置i可能加入前一个子串，也可能另起炉灶开始一个新子串，如果i加入前一个子串，那么前一个子串的值有可能变小
	*		 我们可以想象允许他变小，因为当前子串有可能在等待i之后一个更大的值加入该子串来达到正效应，但是又要防止后面加入的值只会对子串带来负效应
	*		 因此必须要有一个maxResult来记录以前的最大子串值的结果
	* 2. 前面提到当前位置i的数字有两种选择：
	*	 2.1 第1种是i加入前一个子串中
	*		 当 f + nums[i] > nums[i] 时，另起炉灶是没有意义的，因为就算后面有更大的数存在，假设后面某个小串最大值为m，使得f + nums[i] + m > maxResult
	*		 那么也肯定是加上f子串的值会 > i另起子串再加上这个数值较大的小串m；因为f + nums[i] > nums[i]，则f + nums[i] + m > nums[i] + m 恒成立
	*		 因此综上所述，出现 f + nums[i] > nums[i] 时肯定是令i加入前面的子串
	*		 ps：这里前面的子串由于需要保证串的连续性，所以如果想迎接后面更大的小串值，必须把i加入当前串中，不能抛弃
	*	 2.2 第2种情况是i另起炉灶开始一个新子串
	*		 根据2.1的分析，当 f + nums[i] <= nums[i] 时，如果后面有更大的数存在，假设后面某个小串最大值为m，使得 nums[i] + m > maxResult
	*		 那么肯定是抛弃前面的f串更划算，因为如果f + nums[i] < nums[i]，前面的f串会变成累赘，减小总数值
	*		 而如果f + nums[i] == nums[i]则抛不抛弃都无所谓
	*/

	int maxResult = nums[0]; int f = nums[0];//串的遍历从i=0开始
	for (int i = 1; i < nums.size(); i++) {
		if (f + nums[i] > nums[i]) {
			//2.1 第1种是i加入前一个子串中
			f += nums[i];
			maxResult = max(maxResult, f);//因为子串后面的数值是未知的，有可能会给子串带来负效应，因此每次都要暂存一下当前最大值
		}
		else {
			//2.2 第2种情况是i另起炉灶开始一个新子串
			f = nums[i];
			maxResult = max(maxResult, f);//因为子串后面的数值是未知的，有可能会给子串带来负效应，因此每次都要暂存一下当前最大值
		}
	}
	return maxResult;
}
void JumpGame::test_JumpGame() {
	JumpGame JG;
	vector<vector<int>> nums{ {-2,1,-3,4,-1,2,1,-5,4}, {1}, {5,4,-1,7,8} };
	for (int i = 0; i < nums.size(); i++) {
		cout << JG.maxSubArray(nums[i]) << endl;
	}
}
