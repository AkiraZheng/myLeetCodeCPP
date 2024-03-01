#pragma once
#include "header.h"
class DecodeString
{
public:
    string decodeString(string s) {
        /*��394��:�ַ�������
        * ͨ��ά������ջ(�Ƚ����)
        *     һ��ջά��nums,Ҳ����ÿһ��������ǰ��Ĵ���
        *     һ��ջά������������֪��������һ������ǰ�����ɵ��ַ���
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
                //����������,Ҫ�Ȱ�ǰ���num��ջ,Ȼ���ٴ���������;����Ҫ����һ���������ſ�ʼ����ǰ��Χ�ڵ��ַ�����ջ
                strs.push(cur_str); cur_str = "";
                nums.push(cur_num); cur_num = 0;
            }
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                cur_str += c;
            }
            else if (c == ']') {
                // ���������ž����ջ��ʱ��:ȡ�������һ������ֵ(nums.top())����ѭ������
                int times = nums.top(); nums.pop();
                //������ǰ��һ����������,�����ƺ���ַ�����ӵ���һ�������ַ�����
                while (times > 0) {
                    strs.top() += cur_str;//��times�ε�ǰ�����ڵ��ַ���
                    times--;
                }
                cur_str = strs.top();//�µĴ��������ڵ��ַ���
                strs.pop();
            }
        }
        return cur_str;
    }
};

