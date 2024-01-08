#include "BinarySearch.h"
//���ַ�
//28ms--27.12MB, 86.74%-- 95.90%
int BinarySearch::search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right) {
		//left==rightҲ���ȥ����Ϊ�п��ܳ���ֻʣ���һ����ֵ�����
		int mid = (left + right) / 2;//int ��С����Ĵ�����ȡ��ֵ
		if (target > nums[mid]) {//Ŀ��ֵ��[mid+1, right]��������
			++left;
		}
		else if (target < nums[mid]) {//Ŀ��ֵ��[left, mid-1]��������
			--right;
		}
		else {
			return mid;//�ҵ�target
		}
	}
	return -1;
};
