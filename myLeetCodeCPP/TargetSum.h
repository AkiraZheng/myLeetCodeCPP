#pragma once
#include "header.h"
class TargetSum
{
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*第494题:目标和
        * 使用递归法列举所有可能性会超时,这里采用01背包,重点是需要找出背包是什么
        * 1. 推导背包:所有物品的总和为sum=sum(nums)
        *            假设在nums中所有最后是正数的总和为x,那么所有的负数总和的绝对值就是sum-x
        *            由于目标和是target,因此将正数总和和负数总和累加起来有 x-(sum-x)=target,化简得x=(sum+target)/2
        *            到这就很明显了,我们的背包就是被定位正数的总和x,由于物品组成背包x后,剩下的物品我们会默认是负数,所以在代码中其实就可以直接不考虑负数情况了
        * 2. 几个提前返回的条件
        *     a.如果物品正数总和sum都比target小的话,那么物品肯定没办法组成target,直接return 0
        *     b.如果背包x=(sum+target)/2是小数,那么我们根本没办法组成目标x背包,因为物品都是整数,所以当(sum+target)%2 != 0时也返回0
        * 3. dp数组含义:dp[j]表示构成背包j共有dp[j]种方法
        * 4. 递推公式推导
        *    0-1背包先物品后背包,物品不重复,所以背包采用倒序迭代
        *    假设物品nums[i]是作为正数当背包的其中一员,那么组成背包j的可能性共有dp[j] += dp[j-nums[i]]
        * 5. 举例:以nums[1,1,1,1,1],target=3为例,x=4 dp数组[1,0,0,0,0] (组成背包0的可能性是1)
        *         假设第0个物品是构成背包的其中一员,那么     [1,1,0,0,0] 这里dp[1]的1种情况就是包含物品0的情况,而后面的数都是0,也就是不包含物品0的情况,所以其实两种情况都考虑了
        */
        int sum = 0;
        target = abs(target);//组成正数跟组成负数实际上是一样的,但是组成的是负数的话我们不好组成数组下标
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum < target || (sum + target) % 2 != 0) return 0;
        int x = (sum + target) / 2;//背包:组成正数跟组成负数实际上是一样的,但是组成的是负数的话我们不好组成数组下标
        vector<int> dp(x + 1, 0);
        dp[0] = 1;//组成背包0的可能性是1,这是为了方便当j-nums[i]=0时,说明当前物品直接可以塞满背包了,直接代表1种可能
        //先物品后背包,背包倒序
        for (int i = 0; i < nums.size(); i++) {
            for (int j = x; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[x];
    }
    static void test_TargetSum() {
        TargetSum TS;
        vector<int> num{ 100 };
        TS.findTargetSumWays(num, -200);
    }
};

