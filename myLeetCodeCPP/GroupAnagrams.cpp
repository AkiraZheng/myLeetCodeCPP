#include "GroupAnagrams.h"

vector<vector<string>> GroupAnagrams::groupAnagrams(vector<string>& strs) {
	/*��49�⣺��ĸ��λ�ʷ���
	* ��򵥵ķ�������C++�Ĺ�ϣ��ӳ�䣬ͬʱ��ÿ���ַ�����sort������������ĸ��λ���ַ����ͻᱻsort��һ���ģ���ȻҲ�Ϳ���ֱ��ͨ����ϣ��ӳ�䵽ͬһ��λ��
	* 
	* ��ϣ���key��sort�����ַ�����valueΪvector<string>�����Խ�sort��һ������ĸ��λ�����push��value��
	*/

	unordered_map<string, vector<string>> map;//����hash��
	string temp;
	for (string strs_i : strs) {
		temp = strs_i;
		sort(temp.begin(), temp.end());
		map[temp].push_back(strs_i);
	}
	vector<vector<string>> result;
	for (unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); it++) {
		result.push_back(it->second);
	}
	return result;

}
void GroupAnagrams::test_GroupAnagrams() {
	GroupAnagrams GA;
	vector<vector<string>> strs{ {"eat", "tea", "tan", "ate", "nat", "bat"}, {""}, {"a"} };
	for (int i = 0; i < strs.size(); i++) {
		vector<vector<string>> temp = GA.groupAnagrams(strs[i]);
		GA.printVector(temp);
		cout << endl;
	}
}

void GroupAnagrams::printVector(vector<vector<string>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (string temp : nums[i]) {
			cout << temp << " ";
		}
		cout << ",";
	}
}
