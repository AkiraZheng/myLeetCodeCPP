#include "LongestConsecutiveSequence.h"

int LongestConsecutiveSequence::longestConsecutive(vector<int>& nums) {
	/*��128�����������
	* ��ʵ������sort������һ��nums�����ø�left��ָ���i�����������������������У�����û�ԣ������õ���map�洢�������飬Ȼ��ͨ��һ����һ�������Ҷ�Ӧ�����������
	*/

	//��������ᳬʱ
	if (nums.size() == 0) return 0;
	unordered_map<int, bool> map;//key��nums[i]
	unordered_map<int, bool> used;//��¼�Ѿ������������֣��������ľͲ��ü�������
	//������ϣ��
	for (int num : nums) {
		map[num] = true;
	}
	
	int maxLen = 1;
	for (int i = 0; i < nums.size(); i++) {
		if (used[i]) continue;
		int tempLen = 1;
		//1. ��nums[i]�������������
		for (int j = nums[i]-1; map[j]; j--) {
			tempLen++;
			used[j] = true;
		}
		//2. ��nums[i]���ұ���������
		for (int j = nums[i]+1; map[j]; j++) {
			tempLen++;
			used[j] = true;
		}
		maxLen = max(maxLen, tempLen);
	}
	return maxLen;
}

int LongestConsecutiveSequence::longestConsecutive2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int tempLen = 0;
	int maxLen = 0;
	int last;//��һ��������ֵ
	bool isFirst = true;
	for (int i = 0; i < nums.size(); i++) {
		if (i != nums.size()-1 && nums[i] == nums[i + 1]) continue;
		if (isFirst) {
			//��Ե�һ�����ֵĺ�������ͬ��
			last = nums[i];
			tempLen = 1;
			maxLen = 1;
			isFirst = false;
			continue;
		}
		if (nums[i] == last + 1) {
			//����һ������������
			tempLen++;
		}
		else {
			//����һ�������������ģ�˵��Ҫ���¼�����
			maxLen = max(maxLen, tempLen);
			tempLen = 1;
		}
		last = nums[i];
	}
	maxLen = max(maxLen, tempLen);
	return maxLen;
}

void LongestConsecutiveSequence::test_LongestConsecutiveSequence() {
	LongestConsecutiveSequence LCS;
	vector<vector<int>> nums{ {100,4,200,1,3,2},{0,3,7,2,5,8,4,6,0,1} ,{0,-1} };
	/*for (auto& temp : nums) {
		cout << LCS.longestConsecutive2(temp) << endl;
	}*/
	cout << LCS.longestConsecutive2(nums[2]) << endl;
}
