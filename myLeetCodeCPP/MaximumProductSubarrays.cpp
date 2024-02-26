#include "MaximumProductSubarrays.h"

int MaximumProductSubarrays::maxProduct(vector<int>& nums) {
	/*��152�⣺�˻����������
	* ��̬�滮
	* 1. ��������
	*	 dpMax[i]��ʾ��i��β��ǰn������������˻�ֵ�����������ֿ��ܣ�һ���Ǽ���nums[i-1]��ƴ�ӳɸ����ֵ�������������ƴ�������ֵ��С�ˣ����ʱnums[i]����¯��
	*	 dpMin[i]��ʾ��i��β��ǰn�����������С�˻�ֵ��������Ҫά��һ����Сֵ��������Ϊǰn��������������˻��п����Ǹ����ģ����п����ں�������һ������ʹ��˻����������
	* 2. ���ƹ�ʽ
	*	 2.1 ����dpMax[i]
	*		 ���������ֿ��ܣ�һ���Ǽ���nums[i-1]��ƴ�ӳɸ����ֵ�������������ƴ�������ֵ��С�ˣ����ʱnums[i]����¯���ǰ�渺���ĳ˻�����nums[i]���������͵�����¯�
	*		 ���������nums[i-1]����ô�п����Ǽ��뵽����max�����У�Ҳ�п��ܼ��뵽����min�����У������Ҫ����max(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i])
	*		 �����ٿ�������¯�������������ǰһ�����е�������бȽ� max(nums[i], max(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i]))
	*	 2.2 ����dpMin[i]
	*		 ����ͬ�������ֿ��ܣ�һ����ƴ�ӵ�ǰ�淢����ֵ��С�ˣ�һ��������¯��������ֵ��С��
	*		 min(nums[i], min(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i]))
	*/
	if (nums.size() == 1) return nums[0];
	vector<int> dpMax(nums.size(), 0);
	vector<int> dpMin(nums.size(), 0);
	dpMax[0] = nums[0];
	dpMin[0] = nums[0];
	int result = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		dpMax[i] = max(nums[i], max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
		dpMin[i] = min(nums[i], min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
		result = max(result, dpMax[i]);
	}
	return result;
}
void MaximumProductSubarrays::test_MaximumProductSubarrays() {
	MaximumProductSubarrays MPS;
	vector<vector<int>> nums{ {2,3,-2,4},{-2,0,-1} };
	for (auto temp : nums) {
		cout << MPS.maxProduct(temp) << endl;
	}
}
