#include "TwoSum_HashMap.h"
vector<int> TwoSum_HashMap::twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mapping;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        mapping[nums[i]] = i;//key:nums[i]; value:i
    }
    for (int i = 0; i < nums.size(); i++) {
        int gap = target - nums[i];//找到map中有没有对应gap的key
        if (mapping.find(gap) != mapping.end() && mapping[gap] != i) {
            result.push_back(i);
            result.push_back(mapping[gap]);
            break;
        }
    }
    return result;
}