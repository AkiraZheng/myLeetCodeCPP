#include "RemoveSortedArr.h"
int RemoveSortedArr::removeDuplicates(vector<int>& nums) {
	int nums_size = nums.size();
	int slowIndex = 0;
	//循环不能从0开始，因为nums[0]==nums[0]是肯定成立的
	for (int fastIndex = 1; fastIndex < nums_size; fastIndex++) {
		if (nums[fastIndex] != nums[slowIndex]) {
			nums[++slowIndex] = nums[fastIndex];
		}
	}
	return (slowIndex + 1);
}