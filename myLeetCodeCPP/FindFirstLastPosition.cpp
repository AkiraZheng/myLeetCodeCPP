#include "FindFirstLastPosition.h"
vector<int> FindFirstLastPosition::searchRange(vector<int>& nums, int target) {
	int rightBorder = findRightBorder(nums, target);
	int leftBorder = findLeftBorder(nums, target);
	/*1. ��� rightBorder - leftBorder > 1�Ļ���˵���������г���nums[i] > target��ֵ��nums[i] < target��ֵ�⣬������nums[i] = target��ֵ
	���� rightBorder - leftBorder = 1���������������ֺ�õ���nums[leftBorder], target, nums[rightBorder];*/
	if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };

	/*2. ���rightBorder - leftBorder = 1�Ļ���˵��������ֺ����õ���nums[leftBorder], nums[rightBorder]��
	targte����ֵ��Ȼ��nums[leftBorder]��nums[rightBorder]֮�䣬���������в�������target��������˴���Ҫ����[-1, -1]*/

	/*3. ��� rightBorder - leftBorder = 0�Ļ���˵�����ҵ���nums���������ֵ������ֵ��Ҳ����indexΪ0��nums.size()
	��ʱ˵��target����{ nums[0], nums[nums.size()] }��Ҳ���ǲ���������nums����ķ�Χ�ڣ������Ҫ����[-1, -1]*/

	//�ۺ�����2��3�����������Ӧ�÷���[-1, -1]
	return { -1, -1 };

};

//�ҵ�nums[i]>target�����ұ߽�
int FindFirstLastPosition::findRightBorder(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right) {
		mid = (right + left) >> 1;
		if (target < nums[mid]) {
			right = mid - 1;//�����ұ߽�Ĺ����У�ֻ��target<nums[mid]һ��������ƶ��ұ߽�
		}
		else {
			left = mid + 1;//����߽�����Ҫһֱ�����Ƶģ��𲽿����ұ߽�
		}
	}
	//��󷵻ص���left����Ϊ�����������һ��left==right==mid������right����Զ��target�ұߵ����ʣ�������һ�ֱض�����target < nums[right]��Ҳ����target < nums[mid]��ѭ����
	//�������ѭ�����rightʵ���ϲ����ұ߽��ˣ������һ��left�ǲ��ı�ģ���������Ҫ����left������ȷ��
	return left;
};

//�ҵ�nums[i]<target������߽�
int FindFirstLastPosition::findLeftBorder(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	int mid = 0;
	while (left <= right) {
		mid = (right + left) >> 1;
		if (target > nums[mid]) {
			left = mid + 1;//������߽�Ĺ����У�ֻ��target>nums[mid]һ��������ƶ���߽�
		}
		else {
			right = mid - 1;//���ұ߽�����Ҫһֱ�����Ƶģ��𲽿�����߽�
		}
	}
	//��󷵻ص���right����Ϊ�����������һ��left==right==mid������left����Զ��target��ߵ����ʣ�������һ�ֱض�����target > nums[left]��Ҳ����target > nums[mid]��ѭ����
	//�������ѭ�����leftʵ���ϲ�����߽��ˣ������һ��right�ǲ��ı�ģ�������right������ȷ��
	return right;
};
