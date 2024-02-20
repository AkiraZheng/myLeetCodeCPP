#include "NextPermutation.h"

void NextPermutation::nextPermutation(vector<int>& nums) {
	/*��31�⣺��һ������
	* 1. ���ڽ���һ����ֵ��ֱ�ӷ���
	* 2. ������������ֵ��ֱ��swap
	* 3. ���ڳ���������ֵ��
	*	 3.0 ����>����
	*	 3.1 ���ȴӺ���ǰ�ҵ���һ������������λ֮�����nums[i]>nums[i-1]������λ��index��¼Ϊsmall_num
	*	 3.2 �ٴӺ���ǰ�ҵ���һ����small_numλ������ļ�¼Ϊbig_num
	*	 3.3 ������������
	*	 3.4 ��small_num��������������е���
	* 4. �����������nums�������ǰ��ս������е�����������ֱ�Ӱ�λǰ��swap����ȫ�������С������
	*/

	int nums_size = nums.size();

	//1. ���ڽ���һ����ֵ��ֱ�ӷ���
	if (nums_size == 1) return;
	//2. ������������ֵ��ֱ��swap
	if (nums_size == 2) {
		swap(nums[0], nums[1]);
		return;
	}

	//3. ���ڳ���������ֵ��
	//3.1 ���ȴӺ���ǰ�ҵ���һ������������λ֮�����nums[i] > nums[i - 1]������λ��index��¼Ϊsmall_num
	int small_num = -1;
	for (int i = nums_size - 1; i > 0; i--) {
		if (nums[i] > nums[i - 1]) {
			small_num = i-1;
			break;
		}
	}
	//3.2 �ٴӺ���ǰ�ҵ���һ����small_numλ������ļ�¼Ϊbig_num
	if (small_num != -1) {
		for (int big_num = nums_size - 1; big_num > small_num; big_num--) {
			if (nums[big_num] > nums[small_num]) {
				//3.3 ����������������return
				swap(nums[big_num], nums[small_num]);
				break;
			}
		}
	}
	//4. �����������nums�������ǰ��ս������е�����������ֱ�Ӱ�λǰ��swap����ȫ�������С������
	//��Ϊ������ζ��õ������飬���һ����λ
	reverse(nums.begin() + small_num + 1, nums.end());
}


void NextPermutation::test_NextPermutation() {
	NextPermutation NP;
	vector<int> nums{ 1,1,5 };
	for (int temp : nums) {
		cout << temp << " ";
	}
	cout << endl;
	NP.nextPermutation(nums);
	for (int temp : nums) {
		cout << temp << " ";
	}
}