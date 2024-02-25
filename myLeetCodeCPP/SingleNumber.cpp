#include "SingleNumber.h"

int SingleNumber::singleNumber(vector<int>& nums) {
	/*第136题：只出现一次的数字
	* 除了某个数在数组中只出现一次外，其他数都会出现两次
	* 那么我们可以想到：两数异或计算的规律
	* 比如数组中出现了两个5，那么他们的二进制为 101 异或 101，异或计算时两位均为1或均为0就会被重新计算为0，相异才为1，所以通过异或可以将偶数个相同的数逐个异或后计算为0
	* 而单独存在的那个数与全0的数异或后将会被保留下来
	*/
	int result = 0;
	for (int i : nums) {
		result ^= i;
	}
	return result;
}
void SingleNumber::test_SingleNumber() {
	SingleNumber SN;
	vector<vector<int>> nums{ {2,2,1},{4,1,2,1,2},{1} };
	for (auto& temp : nums) {
		cout << SN.singleNumber(temp) << endl;
	}
}
