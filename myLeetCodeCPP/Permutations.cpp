#include "Permutations.h"

vector<vector<int>> Permutations::permute(vector<int>& nums){
	/*第46题：全排列
	* 排列组合问题很容易想到回溯递归：传参、退出条件、单层展开
	* 1. 传参：
	*	 nums
	*	 根据推出条件还需要数组长度和已取的数值个数进行比较，当取够nums.size()了就return，因此还需要传入一个已取数组
	*	 ps:已存数组若存的是已取的index一个加进去，那么在单层展开时还需要一个个判断是否已取，耗时；因此可以设计一个与nums size一样的vector，以true-false表示是否已取
	* 2. 退出条件：
	*	 推出条件也就是深度，每个排列的数组长度为nums.size()，因此深度就是nums.size()
	* 3. 单层展开
	*	 单层展开涉及循环次数，由于前几层取的数值在同一枝干后面层不能重复，因此需要一个vector存储已经取过的值，只有不在vector的数值才需要在此层继续递归
	*/
	result.clear();
	permutationNode.clear();
	vector<bool> isChoose(nums.size(), false);
	backtrack(nums, isChoose);
	return result;
}

void Permutations::backtrack(vector<int>& nums, vector<bool>& isChoose) {
	//2. 退出条件
	if (nums.size() == permutationNode.size()) {
		result.push_back(permutationNode);
		return;
	}

	//3. 单层展开
	for (int i = 0; i < nums.size(); i++) {
		if (isChoose[i]) continue;//已取的不回溯
		isChoose[i] = true;
		permutationNode.push_back(nums[i]);
		backtrack(nums, isChoose);
		isChoose[i] = false;//回溯
		permutationNode.pop_back();//回溯
	}
}

void Permutations::test_Permutations() {
	Permutations P;
	vector<vector<int>> nums;
	nums.push_back({ 1,2,3 });
	nums.push_back({ 0,1 });
	nums.push_back({1});
	for (int i = 0; i < nums.size(); i++) {
		vector<vector<int>> result = P.permute(nums[i]);
		P.printVector(result);
		cout << endl;
	}
}

void Permutations::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << ",";
	}
}
