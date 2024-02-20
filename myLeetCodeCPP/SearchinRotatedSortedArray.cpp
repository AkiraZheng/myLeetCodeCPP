#include "SearchinRotatedSortedArray.h"

int SearchinRotatedSortedArray::search(vector<int>& nums, int target) {
	/*��33�⣺������ת��������
	* ���ö��ַ�������Ҫע��˫ָ����������������䶯
	* ����ת�����У����齫�����Է�Ϊ���������֣������ֶ��Ƿֱ���������ġ������Ҳ��ֵ�������ԶС���󲿷ֵ�
	* 0. ���ַ�������Ҫ����mid��target֮��ıȽϣ��ڸ����У�mid��target�����ֿ��ܳ��ֵ�λ����������ַ����������Ҳ���������ִ���������֣�
	*	 0.1 ��һ���Ƕ����󲿷�
	*	 0.2 �ڶ����Ƕ����Ҳ���
	*	 0.3 ��������һ�����󲿷֣�һ�����Ҳ��֣�Ҫע�������Զ>�ұߣ�
	* 1. ���ַ���һ���жϣ�target > mid
	*	 1.1 ������ߣ��������� mid->target ����left
	*	 1.2 �����ұߣ��������� mid->target ����left
	*	 1.3 һ��һ�ң��������� target->mid ����right����ʱ�ж�target����ߣ�mid���ұ�(�������û��ת�򲻴����������)
	* 2. ���ַ��ڶ����жϣ�target < mid
	*	 2.1 ������ߣ��������� target->mid ����right
	*	 2.2 �����ұߣ��������� target->mid ����right
	*	 2.3 һ��һ�ң��������� mid->target ����left����ʱ�ж�target���ұߣ�mid�����(�������û��ת�򲻴����������)
	* 3. �ܽ�1��2��֪��ֻ�е�һ��һ�ҵ�����£���������Ÿ���ǰ�Ķ��ַ���ͬ�������Ҫ��һ���ж�ĳ����������߻����ұߵ��㷨
	*	 �������>�ұ���Զ�����������nums[i]����ߣ�����nums[i]>=nums[begin];��֮��nums[i]<=nums[end]�����ұ�
	*/

	int nums_left = nums[0], nums_right = nums[nums.size()-1];
	int left = 0, right = nums.size() - 1;
	int mid = 0;
	bool target_flag = (target >= nums_left) ? true : false;//���ж�target����߻����ұߣ����Ϊtrue���ұ�Ϊfalse
	bool is_Rotated_flag = (nums_left >= nums_right) ? true : false;//�ж��Ƿ���ת��
	while (left <= right) {
		mid = (left + right) >> 1;//����һλ�൱�ڳ�2

		//1. ���ַ���һ���жϣ�target > mid
		if (target > nums[mid]) {
			//1.3 һ��һ�ң��������� target->mid ����right����ʱ�ж�target����ߣ�mid���ұ�(�������û��ת�򲻴����������)
			if (is_Rotated_flag && target_flag && nums[mid] <= nums_right) {
				right = mid - 1;
			}
			else {
				//1.1��1.2 ��ͬһ�ߣ���left
				left = mid + 1;
			}
		}
		else if (target < nums[mid]) {
			//2.3 һ��һ�ң��������� mid->target ����left����ʱ�ж�target���ұߣ�mid�����(�������û��ת�򲻴����������)
			if (is_Rotated_flag && !target_flag && nums[mid] >= nums_left) {
				left = mid + 1;
			}
			else {
				//2.1��2.2 ��ͬһ�ߣ���right
				right = mid - 1;
			}
		}
		else {
			//�ҵ���
			return mid;
		}
	}
	//û�ҵ�
	return -1;
}

void SearchinRotatedSortedArray::test_SearchinRotatedSortedArray() {
	SearchinRotatedSortedArray SRSA;
	vector<int> nums{1,3};
	cout << SRSA.search(nums, 3);
	/*vector<int> nums{ 4,5,6,7,0,1,2 };
	vector<int> terget{ 0, 3 };
	for (int t : terget) {
		cout << SRSA.search(nums, t) << endl;
	}*/
}
