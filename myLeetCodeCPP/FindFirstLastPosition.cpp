#include "FindFirstLastPosition.h"
vector<int> FindFirstLastPosition::searchRange(vector<int>& nums, int target) {
	int rightBorder = findRightBorder(nums, target);
	int leftBorder = findLeftBorder(nums, target);
	/*1. 如果 rightBorder - leftBorder > 1的话，说明在数组中除了nums[i] > target的值和nums[i] < target的值外，还存在nums[i] = target的值
	比如 rightBorder - leftBorder = 1，则数组中最后二分后得到了nums[leftBorder], target, nums[rightBorder];*/
	if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };

	/*2. 如果rightBorder - leftBorder = 1的话，说明数组二分后最后得到了nums[leftBorder], nums[rightBorder]，
	targte的数值虽然在nums[leftBorder]和nums[rightBorder]之间，但是数组中并不存在target这个数，此次需要返回[-1, -1]*/

	/*3. 如果 rightBorder - leftBorder = 0的话，说明是找到了nums数组的最左值和最右值，也就是index为0或nums.size()
	此时说明target不在{ nums[0], nums[nums.size()] }，也就是不在已排序nums数组的范围内，因此需要返回[-1, -1]*/

	//综合上述2和3两种情况，均应该返回[-1, -1]
	return { -1, -1 };

};

//找到nums[i]>target的最右边界
int FindFirstLastPosition::findRightBorder(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right) {
		mid = (right + left) >> 1;
		if (target < nums[mid]) {
			right = mid - 1;//在找右边界的过程中，只有target<nums[mid]一种情况能移动右边界
		}
		else {
			left = mid + 1;//而左边界是需要一直向右移的，逐步靠近右边界
		}
	}
	//最后返回的是left，因为当遍历到最后一轮left==right==mid后，由于right有永远在target右边的性质，因此最后一轮必定进入target < nums[right]，也就是target < nums[mid]的循环中
	//因此跳出循环后的right实际上不是右边界了，而最后一轮left是不改变的，因此输出需要跟随left才是正确的
	return left;
};

//找到nums[i]<target的最左边界
int FindFirstLastPosition::findLeftBorder(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right) {
		mid = (right + left) >> 1;
		if (target > nums[mid]) {
			left = mid + 1;//在找左边界的过程中，只有target>nums[mid]一种情况能移动左边界
		}
		else {
			right = mid - 1;//而右边界是需要一直向左移的，逐步靠近左边界
		}
	}
	//最后返回的是right，因为当遍历到最后一轮left==right==mid后，由于left有永远在target左边的性质，因此最后一轮必定进入target > nums[left]，也就是target > nums[mid]的循环中
	//因此跳出循环后的left实际上不是左边界了，而最后一轮right是不改变的，因此输出right才是正确的
	return right;
};
