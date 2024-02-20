#include "NextPermutation.h"

void NextPermutation::nextPermutation(vector<int>& nums) {
	/*第31题：下一个排列
	* 1. 对于仅有一个数值的直接返回
	* 2. 对于有两个数值的直接swap
	* 3. 对于超过两个数值的
	*	 3.0 降序>升序
	*	 3.1 首先从后往前找到第一个出现相邻两位之间出现nums[i]>nums[i-1]的升序位，index记录为small_num
	*	 3.2 再从后往前找到第一个比small_num位的数大的记录为big_num
	*	 3.3 交换这两个数
	*	 3.4 把small_num后面的所有数进行倒序
	* 4. 第四种情况是nums本来就是按照降序排列的最大数，因此直接按位前后swap成完全升序的最小数就行
	*/

	int nums_size = nums.size();

	//1. 对于仅有一个数值的直接返回
	if (nums_size == 1) return;
	//2. 对于有两个数值的直接swap
	if (nums_size == 2) {
		swap(nums[0], nums[1]);
		return;
	}

	//3. 对于超过两个数值的
	//3.1 首先从后往前找到第一个出现相邻两位之间出现nums[i] > nums[i - 1]的升序位，index记录为small_num
	int small_num = -1;
	for (int i = nums_size - 1; i > 0; i--) {
		if (nums[i] > nums[i - 1]) {
			small_num = i-1;
			break;
		}
	}
	//3.2 再从后往前找到第一个比small_num位的数大的记录为big_num
	if (small_num != -1) {
		for (int big_num = nums_size - 1; big_num > small_num; big_num--) {
			if (nums[big_num] > nums[small_num]) {
				//3.3 交换这两个数即可return
				swap(nums[big_num], nums[small_num]);
				break;
			}
		}
	}
	//4. 第四种情况是nums本来就是按照降序排列的最大数，因此直接按位前后swap成完全升序的最小数就行
	//因为无论如何都得倒序数组，因此一步到位
	reverse(nums.begin() + small_num + 1, nums.end());
}


void NextPermutation::test_NextPermutation() {
	NextPermutation NP;
	vector<int> nums{ 1,1,5 };
	for (int temp : nums) {
		cout << temp << " ";
	}
	cout << endl;
	NP.nextPermutation(nums);
	for (int temp : nums) {
		cout << temp << " ";
	}
}