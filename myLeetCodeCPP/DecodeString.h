#pragma once
#include "header.h"
class DecodeString
{
public:
    string decodeString(string s) {
        /*第394题:字符串解码
        * 通过维护两个栈(先进后出)
        *     一个栈维护nums,也就是每一个左括号前面的次数
        *     一个栈维护左括号往后知道遇到下一个数字前所构成的字符串
        */
        stack<int> nums;
        stack<string> strs;
        int cur_num = 0;
        string cur_str = "";
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                cur_num = cur_num * 10 + (c - '0');
            }
            else if (c == '[') {
                //遇到左括号,要先把前面的num入栈,然后再处理左括号;还需要把上一个从左括号开始到当前范围内的字符串入栈
                strs.push(cur_str); cur_str = "";
                nums.push(cur_num); cur_num = 0;
            }
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                cur_str += c;
            }
            else if (c == ']') {
                // 遇到右括号就是收获的时候:取出最近的一个次数值(nums.top())进行循环更新
                int times = nums.top(); nums.pop();
                //消掉当前的一对左右括号,将复制后的字符串添加到下一个待消字符串中
                while (times > 0) {
                    strs.top() += cur_str;//加times次当前括号内的字符串
                    times--;
                }
                cur_str = strs.top();//新的待消区间内的字符串
                strs.pop();
            }
        }
        return cur_str;
    }
};

