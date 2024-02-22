#include "MergeIntervals.h"

vector<vector<int>> MergeIntervals::merge(vector<vector<int>>& intervals) {
	/*��56�⣺�ϲ�����
	* ����̰���㷨
	* 1. ������std��sort��ÿ������ĵ�1��ֵ������������ʹ���ڵ����龡�����ǿ����ģ������intervals[i][0]>=intervals[i-1][0]�ǿ϶�����
	* 2. ��������Ƚ�intervals[i][0]��intervals[i-1][1]�Ĺ�ϵ��Ҳ���ǵ�ǰ�������߽�����һ��������ұ߽���бȽϣ���Ҫһ��result���洢���µ��ް�����ϵ������
	*	 ���intervals[i][0]<=intervals[i-1][1]���������ǰ�������һ������϶��а�����ϵ����ʱ���Ҫ�ϲ����ߣ��ϳ��µ���߽���ұ߽磩
	*		����intervals[i][0]>=intervals[i-1][0]�ǿ϶��ģ���˺ϲ���ı߽���left = intervals[i-1][0]��right = max(intervals[i-1][1], intervals[i][1]);
	*		�����µı߽����result��
	*	 ���intervals[i][0]>intervals[i-1][1]����intervals[i][0]>=intervals[i-1][0]�Ļ����Ͽ���֪��i��i-1�ް�����ϵ�����ֱ�ӽ���i������result����
	*	 
	*	 �ص㣺����������Ƶ�����ʵ��ǰ��intervals[i][0]���Ǹ�intervals[i-1][1]�Ƚϣ����Ǹ����µ�result��������һ�����бȽ�
	*/

	vector<vector<int>> result;
	//1. ������std��sort��ÿ������ĵ�1��ֵ������������ʹ���ڵ����龡�����ǿ����ģ������intervals[i][0] >= intervals[i - 1][0]�ǿ϶�����
	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] < b[0];//�Զ���lambda��ʵ��sort�߼�������ÿ��������λ���Ƚϣ�����������
	});
	//2. ��������Ƚ�intervals[i][0]��intervals[i-1][1]�Ĺ�ϵ,��ʵ��ǰ��intervals[i][0]���Ǹ�intervals[i-1][1]�Ƚϣ����Ǹ����µ�result��������һ�����бȽ�
	result.push_back(intervals[0]);//�ȷ����һ��������Ϊ�Ƚϻ���
	for (const auto& temp : intervals) {
		if (temp[0] <= result.back()[1]) {
			//�������ˣ�����result:intervals[i][0]>=result.back()[0]�ǿ϶����ˣ������߽�϶���result.back()[0]
			result.back()[1] = max(temp[1], result.back()[1]);//����result���һ��������
		}
		else {
			//û��ǰ�������ֱ�Ӵ���result
			result.push_back(temp);
		}
	}
	return result;
}
void MergeIntervals::test_MergeIntervals() {
	MergeIntervals MI;
	vector<vector<int>> nums1{ {1,3} ,{2,6},{8,10},{15,18} };
	vector<vector<int>> nums2{ {1,4} ,{4,5} };
	auto result = MI.merge(nums1);
	MI.printVector(result);
	cout << endl;
	result = MI.merge(nums2);
	MI.printVector(result);
}

void MergeIntervals::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << ",";
	}
}
