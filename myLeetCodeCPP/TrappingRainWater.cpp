#include "TrappingRainWater.h"

//1.采用优化的双指针方法
int TrappingRainWater::trap_doublePtr(vector<int>& height) {
	/*第42题：接雨水
	* 该题需要确认的采用按行扫描还是按列扫描
	* 对于使用双指针方法，采用按列扫描，对于每一列的计算，分别循环取出左边的最高点和右边的最高点位置
	* 按列的话则行的宽度是固定的，为1，那么该列i的可接雨水面积就是 1 * (min(h[left],h[right])-height[i])
	* 但是这种暴力解法会超时，每一列都要重复扫描一遍整个数组，而其实很多左边最大值是公用的，如在一个大凹槽内的index而言，这几个数的左右最大值是一样的
	* 因此考虑优化双指针算法：用两个vector分别存储当前位置及其左（右）范围内的最大值，那么只需要遍历一次存在数组中就行
	*/

	int h_size = height.size();
	//0. 最左没有左边界了，最右没有右边界了，因此最左和最右无法存雨水，所以自然数组大小不大于2也无法接
	if (h_size <= 2) return 0;

	vector<int> maxLeft(h_size, 0);
	vector<int> maxRight(h_size, 0);
	//1. 遍历存储第i点左边的最大值于maxLeft[i]中：从左往右遍历
	maxLeft[0] = height[0]; 
	for (int i = 1; i < h_size; i++) {
		maxLeft[i] = (height[i] > maxLeft[i - 1]) ? height[i] : maxLeft[i - 1];
	}
	maxRight[h_size - 1] = height[h_size - 1];
	//2. 遍历存储第i点右边的最大值于maxRight[i]中：从右往左遍历
	for (int i = h_size - 1 - 1; i >= 0; i--) {
		maxRight[i] = (height[i] > maxRight[i + 1]) ? height[i] : maxRight[i + 1];
	}

	int sum = 0;
	//3. 按列计算接雨水面积：双指针方法：最左和最右不接雨水
	for (int i = 1; i < h_size - 1; i++) {
		int min_h = min(maxLeft[i], maxRight[i]);
		sum += (min_h > height[i]) ? (min_h- height[i]) : 0;//出现凹槽
	}
	return sum;
}
void TrappingRainWater::test_TrappingRainWater_doublePtr() {
	TrappingRainWater TRW;
	vector<vector<int>> nums;
	nums.push_back({ 0,1,0,2,1,0,1,3,2,1,2,1 });
	nums.push_back({ 4,2,0,3,2,5 });
	for (int i=0; i < nums.size(); i++) {
		cout << TRW.trap_doublePtr(nums[i]) << endl;
	}
}
//2.采用单调栈方法
int TrappingRainWater::trap(vector<int>& height) {
	/*第42题：接雨水
	* 采用单调栈的方法，使用搜索坐标行的方法来计算接水，栈存储坐标点index
	* 整体思路：当出现i点值大于栈顶对应的值时；说明出现凹槽了，要不断pop栈中的值来计算距离前一个位置的距离（行宽度）来计算面积，同时不断pop后也能更新最新的最高点位置
	* 0. 最左没有左边界了，最右没有右边界了，因此最左和最右无法存雨水，所以自然数组大小不大于2也无法接
	* 1. 当循环某个点时，该点处的值跟栈顶的值有以下三种关系：(注意循环中虽然第一个点和最后一个点是不接水的，但是有可能是左边值和右边值)
	*	 1.1 height[i] < height[stack.top]：说明是凹槽可能形成的位置，将 i pusuh进栈
	*	 1.2 height[i] == height[stack.top]：两个相邻一样高的柱子只取靠右的柱子i，将stack pop栈顶->将i push进栈
	*	 1.3 height[i] > height[stack.top]：说明出现右边界的柱子了，这里需要开始执行面积计算，并更新新的栈右边界
	*		 1.3.1 采用while遍历栈，找到该柱子对应的左边界（也就是找到行的宽度）
	*			   首先此时的height[i]作为右边界，它左边所包围的凹槽底为stack.top，因此bottom=stack.top
	*			   进一步将stack.top pop出栈，用于下面查询该凹槽与i点对应的左边界（凹槽底不可能是左边界）
	*		 1.3.4 while循环计算完面积后，i将作为新的左边界pop进栈
	*/

	//0. 最左没有左边界了，最右没有右边界了，因此最左和最右无法存雨水，所以自然数组大小不大于2也无法接
	int h_size = height.size();
	if (h_size <= 2) return 0;
	stack<int> leftStack;
	int sum = 0;
	//1. 循环查找
	leftStack.push(0);
	for (int i = 1; i < h_size; i++) {
		if (height[i] < height[leftStack.top()]) {
			//1.1 说明是凹槽可能形成的位置，将 i pusuh进栈
			leftStack.push(i);
		}
		else if (height[i] == height[leftStack.top()]) {
			//1.2 两个相邻一样高的柱子只取靠右的柱子i，将stack pop栈顶->将i push进栈
			leftStack.pop();
			leftStack.push(i);
		}
		else {
			//1.3 height[i] > height[stack.top]：说明出现右边界的柱子了，这里需要开始执行面积计算，并更新新的栈右边界
			while (!leftStack.empty() && height[i] > height[leftStack.top()]) {
				int bottom = leftStack.top();
				leftStack.pop();

				if (!leftStack.empty()) {
					int h = min(height[i], height[leftStack.top()]) - height[bottom];
					int w = i - leftStack.top() - 1;
					sum += h * w;
				}
			}
			if (!leftStack.empty() && height[i] == height[leftStack.top()]) {//两个相邻一样高的柱子只取靠右的柱子i，将stack pop栈顶->将i push进栈
				leftStack.pop();
			}
			leftStack.push(i);
		}
	}
	return sum;
}
void TrappingRainWater::test_TrappingRainWater() {
	TrappingRainWater TRW;
	vector<vector<int>> nums;
	nums.push_back({ 0,1,0,2,1,0,1,3,2,1,2,1 });
	nums.push_back({ 4,2,0,3,2,5 });
	for (int i = 0; i < nums.size(); i++) {
		cout << TRW.trap(nums[i]) << endl;
	}
}
