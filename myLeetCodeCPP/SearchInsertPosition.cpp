#include "SearchInsertPosition.h"
//���ַ�
//4ms--9.79MB, 78.49%-- 47.25%
int SearchInsertPosition::searchInsert(vector<int>& nums, int target) {
	int n = nums.size();
	int left = 0;
	int right = n - 1;
	int mid = 0;
	while (left <= right) {
		mid = (right + left) / 2;
		if (target > nums[mid]) {
			left = mid + 1;
		}
		else if (target < nums[mid]) {
			right = mid - 1;
		}
		else {
			//��һ��������ҵ���ȵ���ֵ��ֱ�ӷ��ظô�index�Ϳ�
			return mid;
		}
	}
	//�������Ҳ�����Ӧ����target����ֵ������ѭ��
	//��ѭ����left==right==midʱ�����target>nums[right]��left++����ʱ��ȷ�Ĳ���λ�þ���right+1
	//��ѭ����left==right==midʱ�����target<nums[right]��right--����ʱ��ȷ�Ĳ���λ��Ҳ��right+1
	//���ʣ�µ����ֱ�����right+1����
	return right + 1;
};