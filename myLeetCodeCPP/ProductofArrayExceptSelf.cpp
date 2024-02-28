#include "ProductofArrayExceptSelf.h"

vector<int> ProductofArrayExceptSelf::productExceptSelf(vector<int>& nums) {
	/*��238�⣺��������������ĳ˻�
	* 1. ��ǰ�������ǰ׺�˻�����result����洢����������result[i]��������i���ǰ�����г˻�
	* 2. �Ӻ���ǰ����i�����ĳ˻��ͣ���һ��int���������ϸ��º�׺������Ҫ���⿪һ������ռ�
	*/
	vector<int> result(nums.size(),1);
	//1.��ǰ׺
	for (int i = 1; i < nums.size(); i++) {
		result[i] = nums[i - 1] * result[i - 1];
		//cout << result[i] << " ";
	}
	//2. ���׺
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
