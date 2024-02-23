#include "Subsets.h"

vector<vector<int>> Subsets::subsets(vector<int>& nums) {
	/*第78题：子集
	* 排列组合问题采用回溯方法：参数、退出条件、单层展开
	* 1. 参数
	*	 1.1 传递参数：nums和startIndex
	*		 因为要求集解中不包含重复的子集，因此需要startIndex记录当前层允许的可展开的范围[startIndex,nums.size())
	*	 1.2 public参数：result存储结果 subSet存储每个枝干上的单个子集
	* 2. 退出条件
	*	 递归深度为nums.size()，当 startIndex == nums.size()时说明该return了
	* 3. 单层展开
	*	 由于需要去重，因此展开需要从startIndex往下展开，同时此层的subSet也属于一个集合，因此要先把本层的结果push进result后再进行回溯
	*/

	result.clear();
	subSet.clear();
	backtrack(nums, 0);
	return result;
}

void Subsets::backtrack(vector<int>& nums, int startIndex) {
	result.push_back(subSet);//要先把本层的结果push进result后再进行回溯

	//退出条件
	if (startIndex >= nums.size()) {
		return;
	}

	//单层展开
	for (int i = startIndex; i < nums.size(); i++) {
		subSet.push_back(nums[i]);
		backtrack(nums, i + 1);
		subSet.pop_back();
	}
}

void Subsets::test_Subsets() {
	Subsets S;
	vector<vector<int>> nums{ {1, 2, 3}, {0} };
	for (auto& temp : nums) {
		vector<vector<int>> result = S.subsets(temp);
		S.printVector(result);
		cout << endl;
	}
}

void Subsets::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << ", ";
	}
}
