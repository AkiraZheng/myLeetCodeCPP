#include "MaximumProductSubarrays.h"

int MaximumProductSubarrays::maxProduct(vector<int>& nums) {
	/*第152题：乘积最大子数组
	* 动态规划
	* 1. 数组意义
	*	 dpMax[i]表示以i结尾的前n个子数组的最大乘积值，这里有两种可能，一种是加入nums[i-1]来拼接成更大的值，但是如果发现拼接完后数值更小了，则此时nums[i]另起炉灶
	*	 dpMin[i]表示以i结尾的前n个子数组的最小乘积值，这里需要维护一个最小值数组是因为前n个连续的子数组乘积有可能是负数的，它有可能在后面遇到一个负数使其乘积起来变大了
	* 2. 递推公式
	*	 2.1 更新dpMax[i]
	*		 这里有两种可能，一种是加入nums[i-1]来拼接成更大的值，但是如果发现拼接完后数值更小了，则此时nums[i]另起炉灶（如前面负数的乘积遇上nums[i]是正数，就得另起炉灶）
	*		 而如果加入nums[i-1]，那么有可能是加入到它的max队列中，也有可能加入到它的min队列中，因此需要先求max(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i])
	*		 接着再考虑另起炉灶的情况来与加入前一个队列的情况进行比较 max(nums[i], max(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i]))
	*	 2.2 更新dpMin[i]
	*		 这里同样有两种可能，一种是拼接到前面发现数值更小了，一种是另起炉灶后后发现数值更小了
	*		 min(nums[i], min(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i]))
	*/
	if (nums.size() == 1) return nums[0];
	vector<int> dpMax(nums.size(), 0);
	vector<int> dpMin(nums.size(), 0);
	dpMax[0] = nums[0];
	dpMin[0] = nums[0];
	int result = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		dpMax[i] = max(nums[i], max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
		dpMin[i] = min(nums[i], min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
		result = max(result, dpMax[i]);
	}
	return result;
}
void MaximumProductSubarrays::test_MaximumProductSubarrays() {
	MaximumProductSubarrays MPS;
	vector<vector<int>> nums{ {2,3,-2,4},{-2,0,-1} };
	for (auto temp : nums) {
		cout << MPS.maxProduct(temp) << endl;
	}
}
