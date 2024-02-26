#include "MajorityElement.h"

int MajorityElement::majorityElement(vector<int>& nums) {
	/*第169题：多数元素
	* 用map存储对应的key，value存key对应的count次数
	* 用countTemp存当前最大的遍历次数、result存对应countTemp的key
	*/
    unordered_map<int, int> m_map;//key:nums[i], value:count
    int result;
    int countTemp = 0;
    for (int num : nums) {
        m_map[num] += 1;//value的默认初始值是0
        if (countTemp < m_map[num]) {
            countTemp = m_map[num];//更换当前的最大count
            result = num;
        }
        if (countTemp > nums.size() / 2) return result;
    }
    return result;
}
