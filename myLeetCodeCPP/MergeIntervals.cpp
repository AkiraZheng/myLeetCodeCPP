#include "MergeIntervals.h"

vector<vector<int>> MergeIntervals::merge(vector<vector<int>>& intervals) {
	/*第56题：合并区间
	* 采用贪心算法
	* 1. 首先用std的sort按每个数组的第1个值进行升序排序，使相邻的数组尽可能是靠近的，排序后intervals[i][0]>=intervals[i-1][0]是肯定的了
	* 2. 遍历逐个比较intervals[i][0]与intervals[i-1][1]的关系：也就是当前数组的左边界与上一个数组的右边界进行比较，需要一个result来存储最新的无包含关系的数组
	*	 如果intervals[i][0]<=intervals[i-1][1]，则表明当前数组跟上一个数组肯定有包含关系，这时候就要合并二者（合成新的左边界和右边界）
	*		由于intervals[i][0]>=intervals[i-1][0]是肯定的，因此合并后的边界有left = intervals[i-1][0]；right = max(intervals[i-1][1], intervals[i][1]);
	*		将最新的边界存入result中
	*	 如果intervals[i][0]>intervals[i-1][1]，在intervals[i][0]>=intervals[i-1][0]的基础上可以知道i和i-1无包含关系，因此直接将第i个存入result就行
	*	 
	*	 重点：有了上面的推导，其实当前的intervals[i][0]不是跟intervals[i-1][1]比较，而是跟最新的result数组的最后一个进行比较
	*/

	vector<vector<int>> result;
	//1. 首先用std的sort按每个数组的第1个值进行升序排序，使相邻的数组尽可能是靠近的，排序后intervals[i][0] >= intervals[i - 1][0]是肯定的了
	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];//自定义lambda来实现sort逻辑，按照每个数组首位来比较，按升序排列
	});
	//2. 遍历逐个比较intervals[i][0]与intervals[i-1][1]的关系,其实当前的intervals[i][0]不是跟intervals[i-1][1]比较，而是跟最新的result数组的最后一个进行比较
	result.push_back(intervals[0]);//先放入第一个数组作为比较基础
	for (const auto& temp : intervals) {
		if (temp[0] <= result.back()[1]) {
			//被包含了，更新result:intervals[i][0]>=result.back()[0]是肯定的了，因此左边界肯定是result.back()[0]
			result.back()[1] = max(temp[1], result.back()[1]);//更新result最后一个的数组
		}
		else {
			//没被前面包含，直接存入result
			result.push_back(temp);
		}
	}
	return result;
}
void MergeIntervals::test_MergeIntervals() {
	MergeIntervals MI;
	vector<vector<int>> nums1{ {1,3} ,{2,6},{8,10},{15,18} };
	vector<vector<int>> nums2{ {1,4} ,{4,5} };
	auto result = MI.merge(nums1);
	MI.printVector(result);
	cout << endl;
	result = MI.merge(nums2);
	MI.printVector(result);
}

void MergeIntervals::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << ",";
	}
}
