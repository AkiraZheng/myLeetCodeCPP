#include "Subsets.h"

vector<vector<int>> Subsets::subsets(vector<int>& nums) {
	/*��78�⣺�Ӽ�
	* �������������û��ݷ������������˳�����������չ��
	* 1. ����
	*	 1.1 ���ݲ�����nums��startIndex
	*		 ��ΪҪ�󼯽��в������ظ����Ӽ��������ҪstartIndex��¼��ǰ������Ŀ�չ���ķ�Χ[startIndex,nums.size())
	*	 1.2 public������result�洢��� subSet�洢ÿ��֦���ϵĵ����Ӽ�
	* 2. �˳�����
	*	 �ݹ����Ϊnums.size()���� startIndex == nums.size()ʱ˵����return��
	* 3. ����չ��
	*	 ������Ҫȥ�أ����չ����Ҫ��startIndex����չ����ͬʱ�˲��subSetҲ����һ�����ϣ����Ҫ�Ȱѱ���Ľ��push��result���ٽ��л���
	*/

	result.clear();
	subSet.clear();
	backtrack(nums, 0);
	return result;
}

void Subsets::backtrack(vector<int>& nums, int startIndex) {
	result.push_back(subSet);//Ҫ�Ȱѱ���Ľ��push��result���ٽ��л���

	//�˳�����
	if (startIndex >= nums.size()) {
		return;
	}

	//����չ��
	for (int i = startIndex; i < nums.size(); i++) {
		subSet.push_back(nums[i]);
		backtrack(nums, i + 1);
		subSet.pop_back();
	}
}

void Subsets::test_Subsets() {
	Subsets S;
	vector<vector<int>> nums{ {1, 2, 3}, {0} };
	for (auto& temp : nums) {
		vector<vector<int>> result = S.subsets(temp);
		S.printVector(result);
		cout << endl;
	}
}

void Subsets::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << ", ";
	}
}
