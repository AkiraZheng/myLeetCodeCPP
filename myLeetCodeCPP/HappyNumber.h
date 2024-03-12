#pragma once
#include "header.h"
class HappyNumber
{
public:
    bool isHappy(int n) {
        /*第202题：快乐数
        * 根据循环的提示可知，当一个数通过提取各位后进行平方和的值曾经出现过，就说明进入了循环模式，return false
        * 接下来就是设计一个spiltNums函数将n不断提取出来又更新就行
        */

        unordered_set<int> used;//存储出现过的数字，用于退出死循环
        used.insert(n);
        while (n != 1) {
            vector<int> nums = spiltNums(n);//取出各个位

            n = 0;//重新计算n
            for (int i : nums) {
                n += i * i;//计算平方和
            }

            if (used.find(n) != used.end()) return false;//出现了相同的，会进入死循环

            used.insert(n);//更新新值
        }
        return true;
    }

    vector<int> spiltNums(int n) {
        //将数字n的的各位提取出来
        vector<int> nums;
        while (n != 0) {
            //余数取位
            nums.push_back(n % 10);
            //除数删除个位
            n /= 10;
        }
        return nums;
    }
};

