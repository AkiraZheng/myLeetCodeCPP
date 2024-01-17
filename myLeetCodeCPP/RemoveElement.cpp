#include "RemoveElement.h"
int RemoveElement::removeElement(vector<int>& nums, int val) {
	//int arr_size = nums.size();
	////slowIndex���ڸ��¸���ǰ������飬����������valֵʱ������������
	////fasetIndex��������������������
	//int slowIndex = 0, fastIndex = 0;
	//for (; fastIndex < arr_size; fastIndex++) {
	//	if (nums[fastIndex] != val) {
	//		//��ִ��nums[slowIndex] = nums[fastIndex]��������ִ��slowIndex++�ĸ��²���
	//		nums[slowIndex++] = nums[fastIndex];
	//	}
	//}
	//return slowIndex;

	/*��val_temp����fastIndex*/
	int arr_size = nums.size();
	//slowIndex���ڸ��¸���ǰ������飬����������valֵʱ������������
	//fasetIndex��������������������
	int slowIndex = 0;
	for (int val_temp:nums) {
		if (val_temp != val) {
			//��ִ��nums[slowIndex] = nums[fastIndex]��������ִ��slowIndex++�ĸ��²���
			nums[slowIndex++] = val_temp;
		}
	}
	return slowIndex;

}
