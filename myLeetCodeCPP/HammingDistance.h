#pragma once
#include "header.h"
class HammingDistance
{
public:
    int hammingDistance(int x, int y) {
        /*第461题:汉明距离
        * 1. 异或:
        *        找x和y二进制的不同位置,我们可以很自然地想到将x和y进行异或
        *        异或将相同的位全部置0,不同的位置1,所以我们只要计算z=x^y后,z含1的个数就行
        * 2. z中含1的个数:
        *        前面有道题就是解决这个问题的,所以我们可以照搬,通过动态规划来解决
        *        dp[i]表示数值i二进制所含的1个数
        *        dp[i]=dp[i/2]+(i&1);
        * 3. 但是这个方法会内存溢出
        */

        // //1. 异或
        // size_t z = x^y;
        // //2. 计算z中含1的个数
        // vector<size_t> dp(z+1, 0);
        // //dp[0]=0
        // for(size_t i = 1; i <= z; i++){
        //     dp[i] = dp[i/2] + (i&1);
        // }
        // return dp[z];

        /*第2种方法:也是先异或,但是这次改变计算1个数的方式
        * 通过不断将s右移,每次右移前先得到将被右移的最低位是否为1,是的话,1的计数值+1
        */
        int z = x ^ y;
        int sum_1 = 0;
        //计算z中1的个数
        while (z > 0) {
            sum_1 += (z & 1);
            z = (z >> 1);
        }
        return sum_1;
    }
};

