#include "TwoSum_Exhaustive.h"

vector<int> TwoSum_Exhaustive::twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    // bool match_flag = false;//û���ϱ�ʶλʱ����ʱ����6.46���ڴ���66.01�����Ϻ�13.38-55.89
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                // match_flag = true;
                // break;
                return result;//ʱ��12.87-�ڴ�65.80
            }
        }
        // if(match_flag){
        //     break;
        // }
    }
    return result;
}
