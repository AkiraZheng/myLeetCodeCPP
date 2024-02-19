#include "three3Sum.h"

vector<vector<int>> three3Sum::threeSum(vector<int>& nums) {
	/*说明：这里的i_a、left_b和right_c都是指nums数组里的索引index
	* 采用双指针方法：for循环一层i作为i_a，在for循环内使用双指针left_b和right_c
	* 1. 首先要对数组进行升序排序
	* 2. 双指针采用向中间逼近的方法，逼近规则为：
	*	2.1 当(a+b+c)>0时表示right值过大，right_c--
	*	2.2 当(a+b+c)<0时表示left值过小，left_b++
	* 3. 解决了整体思路，还要解决重复问题：去重
	*	3.1 首先对于外层的i_a，两个相同的nums[i]值具有的三元组是一样的，因此当前nums[i]不能与前一个也就是nums[i-1]
	*	3.2 对于双指针，当找到一组left_b和right_c后，对于当前轮次的i_a来说，a是固定的，那么相同的left_b和right_c也应该被排除
	*		排除完之后再更新left_b和right_c继续进行双指针查找
	*/

	vector<vector<int>> result;//result是一个n×3数组，每次找到一个三元组就push_back进vector
	//1. 数组进行升序排序:sort函数在std中，需要include <algorithm>
	sort(nums.begin(), nums.end());
	for (int i_a = 0; i_a < nums.size(); i_a++) {
		if (nums[i_a] > 0) return result;//a作为三元组最小的值，大于0那就没必要再查询了

		//3.1 先对i_a进行去重
		if (i_a > 0 && nums[i_a] == nums[i_a - 1])continue;

		//2. 采用双指针方法查询a下对应的b和c
		int left_b = i_a + 1;
		int right_c = nums.size() - 1;
		int sum_abc = 0;
		while (left_b < right_c) {
			sum_abc = nums[i_a] + nums[left_b] + nums[right_c];
			if (sum_abc > 0) {//2.1 当(a+b+c)>0时表示right值过大，right_c--
				right_c--;
			}
			else if (sum_abc < 0) {//2.2 当(a + b + c) < 0时表示left值过小，left_b++
				left_b++;
			}
			else {//找到(a + b + c) = 0的三元组
				result.push_back(vector<int>{nums[i_a], nums[left_b], nums[right_c]});//存入三元组
				//3.2 双指针去重
				while (left_b < right_c && nums[left_b] == nums[left_b + 1]) left_b++;
				while (left_b < right_c && nums[right_c] == nums[right_c - 1]) right_c--;

				//去重后更新下一个双指针
				left_b++;
				right_c--;
			}	
		}
	}
	return result;
}

void three3Sum::test_threeSum() {
	three3Sum threeS;
	vector<int> test_nums = { -1,0,1,2,-1,-4 };
	vector<int> test_nums2 = { -2, 0, 0, 2, 2 };
	vector<vector<int>> result = threeS.threeSum(test_nums2);
	for (vector<int> x_temp : result) {
		for (int y_temp : x_temp) {
			cout << y_temp << " ";
		}
		cout << endl;
	}
}
