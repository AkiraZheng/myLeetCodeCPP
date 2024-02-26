#include "MajorityElement.h"

int MajorityElement::majorityElement(vector<int>& nums) {
	/*��169�⣺����Ԫ��
	* ��map�洢��Ӧ��key��value��key��Ӧ��count����
	* ��countTemp�浱ǰ���ı���������result���ӦcountTemp��key
	*/
    unordered_map<int, int> m_map;//key:nums[i], value:count
    for (int num : nums) {
        m_map[num] += 1;//value��Ĭ�ϳ�ʼֵ��0
        if (m_map[num] > nums.size() / 2) return num;
    }
    return 0;
}
