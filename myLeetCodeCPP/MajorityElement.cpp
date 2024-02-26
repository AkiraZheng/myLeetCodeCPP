#include "MajorityElement.h"

int MajorityElement::majorityElement(vector<int>& nums) {
	/*第169题：多数元素
	* 用map存储对应的key，value存key对应的count次数
	* 用countTemp存当前最大的遍历次数、result存对应countTemp的key
	*/
    unordered_map<int, int> m_map;//key:nums[i], value:count
    for (int num : nums) {
        m_map[num] += 1;//value的默认初始值是0
        if (m_map[num] > nums.size() / 2) return num;
    }
    return 0;
}
