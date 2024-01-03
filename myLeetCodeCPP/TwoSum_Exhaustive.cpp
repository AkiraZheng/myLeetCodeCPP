#include "TwoSum_Exhaustive.h"

vector<int> TwoSum_Exhaustive::twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    // bool match_flag = false;//没加上标识位时运行时间打败6.46、内存打败66.01，加上后13.38-55.89
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                // match_flag = true;
                // break;
                return result;//时间12.87-内存65.80
            }
        }
        // if(match_flag){
        //     break;
        // }
    }
    return result;
}
