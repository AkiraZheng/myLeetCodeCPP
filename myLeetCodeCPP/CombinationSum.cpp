#include "CombinationSum.h"

vector<vector<int>> CombinationSum::combinationSum(vector<int>& candidates, int target) {
	/*第39题：组合总和
	* 组合采用递归回溯方法解决：传参、结束条件、单层展开
	* 1. 传参
	*	 首先是将数组candidates和target传入
	*	 其次，考虑结束条件跟sum有关，因此也要传入sum;(结束条件中还要存入前几层所取的数据，因此也要有一个变量存储所取的数据，这里与result都不作传参，而是放在全局参数中)
	*	 考虑单层展开进行递归时，需要本层取出的数chooseNum = nums[index]
	* 2. 结束条件
	*	 因为数组中的数字可以被无限取出，所以只要sum>=target就可以退出了（题目有说数组中无0，因此不用担心无限取值造成递归死循环）
	*	 2.1 sum>target：说明没有继续递归取值的必要了，这个枝干不符合条件，直接return
	*	 2.2 sum==target：push进result中
	* 3. 单层展开
	*	 这里虽然对于每一层的同个元素来说可以无限取出，但是对于同一枝干上的一个组合输出结果来说，每个数只能被取一次
	*	 因此需要一个startIndex参数来表示本层可以从哪个数开始循环取起，每一层都可以有nums.size()-startIndex-1个展开（递归）
	*/
	result.clear();
	layer_nums.clear();
	backtrack(candidates, target, 0, 0);
	return result;
}

void CombinationSum::backtrack(vector<int>& candidates, int target, int sum, int startIndex) {
	//2. 结束条件
	if (sum > target) {
		//2.1 sum > target：说明没有继续递归取值的必要了，这个枝干不符合条件，直接return
		return;
	}
	else if (sum == target) {
		//2.2 sum == target：push进result中
		result.push_back(layer_nums);
		return;
	}

	//3. 单层展开
	for (int i = startIndex; i < candidates.size(); i++) {//若这里减枝的话，主函数中就需要先对candidates进行排序，&& (sum + candidates[i]) > target
		sum += candidates[i];
		layer_nums.push_back(candidates[i]);
		backtrack(candidates, target, sum, i);
		sum -= candidates[i];//回溯
		layer_nums.pop_back();//回溯
	}
}

void CombinationSum::test_CombinationSum() {
	CombinationSum CS;
	vector< vector<int> > nums;
	nums.push_back({ 2,3,6,7 });
	nums.push_back({ 2,3,5 });
	nums.push_back({ 2 });
	vector<int> targets{ 7,8,1 };
	for (int i = 0; i < nums.size() - 1; i++) {
		vector<vector<int> > result_temp = CS.combinationSum(nums[i], targets[i]);
		for (int i = 0; i < result_temp.size(); i++) {
			for (int temp : result_temp[i]) {
				cout << " " << temp;
			}
		}
		cout << endl;
	}
}