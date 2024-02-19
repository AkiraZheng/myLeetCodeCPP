#include "ContainerWithMostWater.h"

int ContainerWithMostWater::maxArea(vector<int>& height) {
	/*
	* 使用双指针方法，由数组的最两端不断往中间靠
	* 容器的容积与两端的距离有关，因此从最远的两端开始缩，保证宽度
	* 容器的容积还与最短板有关，因此当两端出现较为短的板时，缩该板，另一端暂时不动
	*/
	int left = 0, right = height.size() - 1;
	int max_v = 0, temp_v = 0;
	while (left < right) {
		temp_v = min(height[left], height[right]) * (right - left);//计算此次两端围成的容积
		max_v = max(max_v, temp_v);//取容积最大值
		if (height[left] <= height[right]) {//两端向中间缩：缩短板
			left++;
		}
		else {
			right--;
		}
	}
	return max_v;
}

void ContainerWithMostWater::test_maxArea() {
	ContainerWithMostWater CWMW;
	vector<int> test_num1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << CWMW.maxArea(test_num1) << endl;
}