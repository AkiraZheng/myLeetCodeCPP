#include "three3Sum.h"

vector<vector<int>> three3Sum::threeSum(vector<int>& nums) {
	/*˵���������i_a��left_b��right_c����ָnums�����������index
	* ����˫ָ�뷽����forѭ��һ��i��Ϊi_a����forѭ����ʹ��˫ָ��left_b��right_c
	* 1. ����Ҫ�����������������
	* 2. ˫ָ��������м�ƽ��ķ������ƽ�����Ϊ��
	*	2.1 ��(a+b+c)>0ʱ��ʾrightֵ����right_c--
	*	2.2 ��(a+b+c)<0ʱ��ʾleftֵ��С��left_b++
	* 3. ���������˼·����Ҫ����ظ����⣺ȥ��
	*	3.1 ���ȶ�������i_a��������ͬ��nums[i]ֵ���е���Ԫ����һ���ģ���˵�ǰnums[i]������ǰһ��Ҳ����nums[i-1]
	*	3.2 ����˫ָ�룬���ҵ�һ��left_b��right_c�󣬶��ڵ�ǰ�ִε�i_a��˵��a�ǹ̶��ģ���ô��ͬ��left_b��right_cҲӦ�ñ��ų�
	*		�ų���֮���ٸ���left_b��right_c��������˫ָ�����
	*/

	vector<vector<int>> result;//result��һ��n��3���飬ÿ���ҵ�һ����Ԫ���push_back��vector
	//1. ���������������:sort������std�У���Ҫinclude <algorithm>
	sort(nums.begin(), nums.end());
	for (int i_a = 0; i_a < nums.size(); i_a++) {
		if (nums[i_a] > 0) return result;//a��Ϊ��Ԫ����С��ֵ������0�Ǿ�û��Ҫ�ٲ�ѯ��

		//3.1 �ȶ�i_a����ȥ��
		if (i_a > 0 && nums[i_a] == nums[i_a - 1])continue;

		//2. ����˫ָ�뷽����ѯa�¶�Ӧ��b��c
		int left_b = i_a + 1;
		int right_c = nums.size() - 1;
		int sum_abc = 0;
		while (left_b < right_c) {
			sum_abc = nums[i_a] + nums[left_b] + nums[right_c];
			if (sum_abc > 0) {//2.1 ��(a+b+c)>0ʱ��ʾrightֵ����right_c--
				right_c--;
			}
			else if (sum_abc < 0) {//2.2 ��(a + b + c) < 0ʱ��ʾleftֵ��С��left_b++
				left_b++;
			}
			else {//�ҵ�(a + b + c) = 0����Ԫ��
				result.push_back(vector<int>{nums[i_a], nums[left_b], nums[right_c]});//������Ԫ��
				//3.2 ˫ָ��ȥ��
				while (left_b < right_c && nums[left_b] == nums[left_b + 1]) left_b++;
				while (left_b < right_c && nums[right_c] == nums[right_c - 1]) right_c--;

				//ȥ�غ������һ��˫ָ��
				left_b++;
				right_c--;
			}	
		}
	}
	return result;
}

void three3Sum::test_threeSum() {
	three3Sum threeS;
	vector<int> test_nums = { -1,0,1,2,-1,-4 };
	vector<int> test_nums2 = { -2, 0, 0, 2, 2 };
	vector<vector<int>> result = threeS.threeSum(test_nums2);
	for (vector<int> x_temp : result) {
		for (int y_temp : x_temp) {
			cout << y_temp << " ";
		}
		cout << endl;
	}
}
