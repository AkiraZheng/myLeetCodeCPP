#include "SortColors.h"

void SortColors::sortColors(vector<int>& nums) {
	/*第75题：颜色分类
	* 红：0 白：1 蓝：2
	* 使用双指针方法，用red来存储红0的最新坐标，用blue来存储蓝2从最右往左排的最新坐标，i表示当前需要进行排序的坐标点
	* 当前存储的坐标都是还未填进对应颜色的（等待被填进）
	* 1. 当nums[i]==0
	*	 表示需要更新红0：swap(nums[i], nums[red])，那么red的指针要指向下一个位置了，执行red++
	*	 这里不需要i--是因为red<=i是成立的，而i以前的数字都被排序过了，因此交换的red位置到i处不需要再排序了
	* 2. 当nums[i]==1
	*	 表示需要更新白1：由于此时i前面的数字都是被排序过的了，因此当遇到白1时直接原地不动就行
	* 3. 当nums[i]==2：
	*	 表示需要更新蓝2：swap(nums[i], nums[blue])，那么blue的指针要指向下一个左边的位置了，指向blue--
	*	 那么交换后此时的nums[i]又是未排序的了，因此还需要指向i--，在下一个循环中继续判断当前轮次中的i
	*/
	int red = 0; int blue = nums.size() - 1;
	for (int i = 0; i <= blue; i++) {//这里需要遍历到left是因为到最后left有可能是还没被排序的，也就是整个数组中根本没有蓝色
		//当nums[i]==1保持原地不动，就不写了
		if (nums[i] == 0) {
			//放红色
			swap(nums[i], nums[red++]);
		}
		else if (nums[i] == 2) {
			swap(nums[i--], nums[blue--]);
		}
	}
}
void SortColors::test_SortColors() {
	SortColors SC;
	vector< vector<int>> nums{ {2,0,2,1,1,0}, {2,0,1} };
	vector< vector<int>> result;
	for (auto &num : nums) {
		SC.sortColors(num);
		result.push_back(num);
	}
	SC.printVector(result);
}

void SortColors::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << endl;
	}
}
