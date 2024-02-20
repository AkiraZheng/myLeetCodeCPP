#include "SearchinRotatedSortedArray.h"

int SearchinRotatedSortedArray::search(vector<int>& nums, int target) {
	/*第33题：搜索旋转排序数组
	* 采用二分法，但是要注意双指针的搜索规律有所变动
	* 在旋转数组中，数组将被隐性分为左右两部分，两部分都是分别属于升序的。其中右部分的数据永远小于左部分的
	* 0. 二分法中最重要的是mid和target之间的比较，在该题中，mid和target有三种可能出现的位置情况，二分法的收缩情况也将从这三种大类情况入手：
	*	 0.1 第一种是都在左部分
	*	 0.2 第二种是都在右部分
	*	 0.3 第三种是一个在左部分，一个在右部分（要注意左边永远>右边）
	* 1. 二分法第一种判断：target > mid
	*	 1.1 都在左边：从左到右有 mid->target 故缩left
	*	 1.2 都在右边：从左到右有 mid->target 故缩left
	*	 1.3 一左一右：从左到右有 target->mid 故缩right，此时判断target在左边，mid在右边(如果数组没旋转则不存在这种情况)
	* 2. 二分法第二种判断：target < mid
	*	 2.1 都在左边：从左到右有 target->mid 故缩right
	*	 2.2 都在右边：从左到右有 target->mid 故缩right
	*	 2.3 一左一右：从左到右有 mid->target 故缩left，此时判断target在右边，mid在左边(如果数组没旋转则不存在这种情况)
	* 3. 总结1和2可知，只有当一左一右的情况下，收缩情况才跟以前的二分法不同，因此需要有一个判断某个数字在左边还是右边的算法
	*	 由于左边>右边永远成立，因此若nums[i]在左边，则有nums[i]>=nums[begin];反之若nums[i]<=nums[end]则在右边
	*/

	int nums_left = nums[0], nums_right = nums[nums.size()-1];
	int left = 0, right = nums.size() - 1;
	int mid = 0;
	bool target_flag = (target >= nums_left) ? true : false;//先判断target在左边还是右边：左边为true，右边为false
	bool is_Rotated_flag = (nums_left >= nums_right) ? true : false;//判断是否旋转了
	while (left <= right) {
		mid = (left + right) >> 1;//右移一位相当于除2

		//1. 二分法第一种判断：target > mid
		if (target > nums[mid]) {
			//1.3 一左一右：从左到右有 target->mid 故缩right，此时判断target在左边，mid在右边(如果数组没旋转则不存在这种情况)
			if (is_Rotated_flag && target_flag && nums[mid] <= nums_right) {
				right = mid - 1;
			}
			else {
				//1.1和1.2 在同一边，缩left
				left = mid + 1;
			}
		}
		else if (target < nums[mid]) {
			//2.3 一左一右：从左到右有 mid->target 故缩left，此时判断target在右边，mid在左边(如果数组没旋转则不存在这种情况)
			if (is_Rotated_flag && !target_flag && nums[mid] >= nums_left) {
				left = mid + 1;
			}
			else {
				//2.1和2.2 在同一边，缩right
				right = mid - 1;
			}
		}
		else {
			//找到了
			return mid;
		}
	}
	//没找到
	return -1;
}

void SearchinRotatedSortedArray::test_SearchinRotatedSortedArray() {
	SearchinRotatedSortedArray SRSA;
	vector<int> nums{1,3};
	cout << SRSA.search(nums, 3);
	/*vector<int> nums{ 4,5,6,7,0,1,2 };
	vector<int> terget{ 0, 3 };
	for (int t : terget) {
		cout << SRSA.search(nums, t) << endl;
	}*/
}
