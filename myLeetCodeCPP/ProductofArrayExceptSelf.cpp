#include "ProductofArrayExceptSelf.h"

vector<int> ProductofArrayExceptSelf::productExceptSelf(vector<int>& nums) {
	/*第238题：除自身以外数组的乘积
	* 1. 从前往后查找前缀乘积，用result数组存储，该轮搜索result[i]代表不包括i点的前面所有乘积
	* 2. 从后往前计算i点后面的乘积和，用一个int数据来不断更新后缀，不需要额外开一个数组空间
	*/
	vector<int> result(nums.size(),1);
	//1.查前缀
	for (int i = 1; i < nums.size(); i++) {
		result[i] = nums[i - 1] * result[i - 1];
		//cout << result[i] << " ";
	}
	//2. 查后缀
	int suffix = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		result[i] *= suffix;
		suffix *= nums[i];
		//cout << result[i] << " ";
	}
	return result;
}

void ProductofArrayExceptSelf::test_ProductofArrayExceptSelf() {
	ProductofArrayExceptSelf PAES;
	vector<vector<int>> nums{ {1,2,3,4},{-1,1,0,-3,3} };
	vector<vector<int>> results;
	results.push_back(PAES.productExceptSelf(nums[0]));
	results.push_back(PAES.productExceptSelf(nums[1]));
	PAES.printVector(results);
}

void ProductofArrayExceptSelf::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << endl;
	}
}
