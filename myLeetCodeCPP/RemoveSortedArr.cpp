#include "RemoveSortedArr.h"
int RemoveSortedArr::removeDuplicates(vector<int>& nums) {
	int nums_size = nums.size();
	int slowIndex = 0;
	//ѭ�����ܴ�0��ʼ����Ϊnums[0]==nums[0]�ǿ϶�������
	for (int fastIndex = 1; fastIndex < nums_size; fastIndex++) {
		if (nums[fastIndex] != nums[slowIndex]) {
			nums[++slowIndex] = nums[fastIndex];
		}
	}
	return (slowIndex + 1);
}