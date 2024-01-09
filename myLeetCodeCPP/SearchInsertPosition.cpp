#include "SearchInsertPosition.h"
//二分法
//4ms--9.79MB, 78.49%-- 47.25%
int SearchInsertPosition::searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	int left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right) {
		mid = (right + left) / 2;
		if (target > nums[mid]) {
			left = mid + 1;
		}
		else if (target < nums[mid]) {
			right = mid - 1;
		}
		else {
			//第一种情况，找到相等的数值，直接返回该处index就可
			return mid;
		}
	}
	//数组中找不到对应等于target的数值会跳出循环
	//当循环到left==right==mid时，如果target>nums[right]，left++，此时正确的插入位置就是right+1
	//当循环到left==right==mid时，如果target<nums[right]，right--，此时正确的插入位置也是right+1
	//因此剩下的情况直接输出right+1就行
	return right + 1;
};