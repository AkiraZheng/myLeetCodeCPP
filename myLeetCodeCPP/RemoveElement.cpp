#include "RemoveElement.h"
int RemoveElement::removeElement(vector<int>& nums, int val) {
	//int arr_size = nums.size();
	////slowIndex用于更新覆盖前面的数组，当遇到等于val值时则跳过不更新
	////fasetIndex用于搜索遍历整个数组
	//int slowIndex = 0, fastIndex = 0;
	//for (; fastIndex < arr_size; fastIndex++) {
	//	if (nums[fastIndex] != val) {
	//		//先执行nums[slowIndex] = nums[fastIndex]操作，再执行slowIndex++的更新操作
	//		nums[slowIndex++] = nums[fastIndex];
	//	}
	//}
	//return slowIndex;

	/*用val_temp代替fastIndex*/
	int arr_size = nums.size();
	//slowIndex用于更新覆盖前面的数组，当遇到等于val值时则跳过不更新
	//fasetIndex用于搜索遍历整个数组
	int slowIndex = 0;
	for (int val_temp:nums) {
		if (val_temp != val) {
			//先执行nums[slowIndex] = nums[fastIndex]操作，再执行slowIndex++的更新操作
			nums[slowIndex++] = val_temp;
		}
	}
	return slowIndex;

}
