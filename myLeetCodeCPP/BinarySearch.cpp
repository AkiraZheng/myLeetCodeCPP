#include "BinarySearch.h"
//二分法
//28ms--27.12MB, 86.74%-- 95.90%
int BinarySearch::search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right) {
		//left==right也算进去，因为有可能出现只剩最后一个数值的情况
		int mid = (left + right) / 2;//int 对小数点的处理是取左值
		if (target > nums[mid]) {//目标值在[mid+1, right]的区间内
			++left;
		}
		else if (target < nums[mid]) {//目标值在[left, mid-1]的区间内
			--right;
		}
		else {
			return mid;//找到target
		}
	}
	return -1;
};
