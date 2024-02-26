#include "MajorityElement.h"

int MajorityElement::majorityElement(vector<int>& nums) {
	/*��169�⣺����Ԫ��
	* ��map�洢��Ӧ��key��value��key��Ӧ��count����
	* ��countTemp�浱ǰ���ı���������result���ӦcountTemp��key
	*/
    unordered_map<int, int> m_map;//key:nums[i], value:count
    int result;
    int countTemp = 0;
    for (int num : nums) {
        m_map[num] += 1;//value��Ĭ�ϳ�ʼֵ��0
        if (countTemp < m_map[num]) {
            countTemp = m_map[num];//������ǰ�����count
            result = num;
        }
        if (countTemp > nums.size() / 2) return result;
    }
    return result;
}
