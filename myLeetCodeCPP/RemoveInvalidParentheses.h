#pragma once
#include "header.h"
class RemoveInvalidParentheses
{
private:
    vector<string> result;
public:
    vector<string> removeInvalidParentheses(string s) {
        //查找总共需要删除多少个左括号和多少个右括号
        stack<char> m_stack;
        int l_del = 0, r_del = 0;
        for (char c : s) {
            if (c == '(') {
                m_stack.push(c);
            }
            else if (c == ')') {
                if (m_stack.empty()) {
                    r_del++;//出现不匹配了，需要删除的个数加一
                    continue;
                }
                m_stack.pop();//说明还能匹配，所以进行匹配
            }
        }
        l_del = (m_stack.empty()) ? 0 : m_stack.size();//剩下未匹配的左括号就是需要删的
        backTrack(s, l_del, r_del, 0);
        if (result.size() == 0) result.push_back("");
        return result;
    }

    void backTrack(string s, int l_del, int r_del, int start) {
        /*s:    通过前面删掉一些值后的字符串
        * l_del:剩下还需要删除的左括号个数
        * r_del:剩下还需要删除的右括号个数
        * start:表示从s的那个位置（包括start）开始搜索可能可以删除的数（start前面的字符是在当前枝上已经被处理过了的，不需要动）
        */
        if (l_del == 0 && r_del == 0) {
            //数量上删够了，接下来就是判断当前的值是否为有效结果，是的话就放进result然后回溯
            if (isValid(s)) result.push_back(s);
            return;
        }

        //单层展开：当前字符串s的start位置往后都是还未搜索到的，需要展开
        for (int i = start; i < s.size(); i++) {//当前i的索引对应的字符是待删除的
            //跟后一个1字符重复的，那么其实删谁都行，但如果不判断的话，就会出现重复字符串，这里可以去重
            //这里的判断不能改为s[i] == s[i + 1]，因为这样会导致当前的i被跳过，少了一整个枝干，必须先计算完一个重复值，后面的才能放心跳过
            if (i != start && s[i] == s[i - 1])continue;

            if (s[i] == '(' && l_del != 0) {
                //左括号还需要删除，所以可以删除当前的左括号，最后递归到底的时候再判断当前删除的对不对
                backTrack(s.substr(0, i) + s.substr(i + 1), l_del - 1, r_del, i);//i不用变，因为此时的i已经被删了，所以到下一层的时候相当于这一层的i+1
            }
            else if (s[i] == ')' && r_del != 0) {
                backTrack(s.substr(0, i) + s.substr(i + 1), l_del, r_del - 1, i);
            }
        }
    }

    //判断字符串s是否为有效的括号，通过栈的判断（第20题有效的括号）
    bool isValid(string s) {
        stack<char> m_stack;
        for (char c : s) {
            if (c == '(') {
                m_stack.push(c);//左括号可以直接入栈，表示待匹配
                continue;
            }
            else if (c == ')') {
                if (m_stack.empty()) return false;//出现右括号无法匹配了，此时字符串肯定不匹配，因为右括号无法与后面的左括号匹配
                m_stack.pop();//有匹配的，通过pop进行匹配
            }
        }
        return m_stack.empty() ? true : false;
    }
};

