#include "GroupAnagrams.h"

vector<vector<string>> GroupAnagrams::groupAnagrams(vector<string>& strs) {
	/*第49题：字母异位词分组
	* 最简单的方法是用C++的哈希表映射，同时将每个字符串都sort，这样具有字母异位的字符串就会被sort成一样的，自然也就可以直接通过哈希表映射到同一个位置
	* 
	* 哈希表的key存sort过的字符串，value为vector<string>，可以将sort后一样的字母异位次逐个push进value中
	*/

	unordered_map<string, vector<string>> map;//创建hash表
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
