#include "LongestConsecutiveSequence.h"

int LongestConsecutiveSequence::longestConsecutive(vector<int>& nums) {
	/*第128：最长连续序列
	* 其实可以先sort函数排一下nums，再用个left左指针和i遍历整个数组更新最长连续序列，但是没试，这里用的是map存储整个数组，然后通过一个数一个数查找对应的最长连续序列
	*/

	//这个方法会超时
	if (nums.size() == 0) return 0;
	unordered_map<int, bool> map;//key是nums[i]
	unordered_map<int, bool> used;//记录已经遍历过的数字，遍历过的就不用继续测了
	//构建哈希表
	for (int num : nums) {
		map[num] = true;
	}
	
	int maxLen = 1;
	for (int i = 0; i < nums.size(); i++) {
		if (used[i]) continue;
		int tempLen = 1;
		//1. 找nums[i]的左边连续长度
		for (int j = nums[i]-1; map[j]; j--) {
			tempLen++;
			used[j] = true;
		}
		//2. 找nums[i]的右边连续长度
		for (int j = nums[i]+1; map[j]; j++) {
			tempLen++;
			used[j] = true;
		}
		maxLen = max(maxLen, tempLen);
	}
	return maxLen;
}

int LongestConsecutiveSequence::longestConsecutive2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int tempLen = 0;
	int maxLen = 0;
	int last;//上一个数的数值
	bool isFirst = true;
	for (int i = 0; i < nums.size(); i++) {
		if (i != nums.size()-1 && nums[i] == nums[i + 1]) continue;
		if (isFirst) {
			//针对第一个出现的后面无相同数
			last = nums[i];
			tempLen = 1;
			maxLen = 1;
			isFirst = false;
			continue;
		}
		if (nums[i] == last + 1) {
			//跟上一个数是连续的
			tempLen++;
		}
		else {
			//跟上一个数不是连续的，说明要重新计算了
			maxLen = max(maxLen, tempLen);
			tempLen = 1;
		}
		last = nums[i];
	}
	maxLen = max(maxLen, tempLen);
	return maxLen;
}

void LongestConsecutiveSequence::test_LongestConsecutiveSequence() {
	LongestConsecutiveSequence LCS;
	vector<vector<int>> nums{ {100,4,200,1,3,2},{0,3,7,2,5,8,4,6,0,1} ,{0,-1} };
	/*for (auto& temp : nums) {
		cout << LCS.longestConsecutive2(temp) << endl;
	}*/
	cout << LCS.longestConsecutive2(nums[2]) << endl;
}
