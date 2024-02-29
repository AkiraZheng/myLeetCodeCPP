#pragma once
#include "header.h"
class RemoveInvalidParentheses
{
private:
    vector<string> result;
public:
    vector<string> removeInvalidParentheses(string s) {
        //�����ܹ���Ҫɾ�����ٸ������źͶ��ٸ�������
        stack<char> m_stack;
        int l_del = 0, r_del = 0;
        for (char c : s) {
            if (c == '(') {
                m_stack.push(c);
            }
            else if (c == ')') {
                if (m_stack.empty()) {
                    r_del++;//���ֲ�ƥ���ˣ���Ҫɾ���ĸ�����һ
                    continue;
                }
                m_stack.pop();//˵������ƥ�䣬���Խ���ƥ��
            }
        }
        l_del = (m_stack.empty()) ? 0 : m_stack.size();//ʣ��δƥ��������ž�����Ҫɾ��
        backTrack(s, l_del, r_del, 0);
        if (result.size() == 0) result.push_back("");
        return result;
    }

    void backTrack(string s, int l_del, int r_del, int start) {
        /*s:    ͨ��ǰ��ɾ��һЩֵ����ַ���
        * l_del:ʣ�»���Ҫɾ���������Ÿ���
        * r_del:ʣ�»���Ҫɾ���������Ÿ���
        * start:��ʾ��s���Ǹ�λ�ã�����start����ʼ�������ܿ���ɾ��������startǰ����ַ����ڵ�ǰ֦���Ѿ���������˵ģ�����Ҫ����
        */
        if (l_del == 0 && r_del == 0) {
            //������ɾ���ˣ������������жϵ�ǰ��ֵ�Ƿ�Ϊ��Ч������ǵĻ��ͷŽ�resultȻ�����
            if (isValid(s)) result.push_back(s);
            return;
        }

        //����չ������ǰ�ַ���s��startλ�������ǻ�δ�������ģ���Ҫչ��
        for (int i = start; i < s.size(); i++) {//��ǰi��������Ӧ���ַ��Ǵ�ɾ����
            //����һ��1�ַ��ظ��ģ���ô��ʵɾ˭���У���������жϵĻ����ͻ�����ظ��ַ������������ȥ��
            //������жϲ��ܸ�Ϊs[i] == s[i + 1]����Ϊ�����ᵼ�µ�ǰ��i������������һ����֦�ɣ������ȼ�����һ���ظ�ֵ������Ĳ��ܷ�������
            if (i != start && s[i] == s[i - 1])continue;

            if (s[i] == '(' && l_del != 0) {
                //�����Ż���Ҫɾ�������Կ���ɾ����ǰ�������ţ����ݹ鵽�׵�ʱ�����жϵ�ǰɾ���ĶԲ���
                backTrack(s.substr(0, i) + s.substr(i + 1), l_del - 1, r_del, i);//i���ñ䣬��Ϊ��ʱ��i�Ѿ���ɾ�ˣ����Ե���һ���ʱ���൱����һ���i+1
            }
            else if (s[i] == ')' && r_del != 0) {
                backTrack(s.substr(0, i) + s.substr(i + 1), l_del, r_del - 1, i);
            }
        }
    }

    //�ж��ַ���s�Ƿ�Ϊ��Ч�����ţ�ͨ��ջ���жϣ���20����Ч�����ţ�
    bool isValid(string s) {
        stack<char> m_stack;
        for (char c : s) {
            if (c == '(') {
                m_stack.push(c);//�����ſ���ֱ����ջ����ʾ��ƥ��
                continue;
            }
            else if (c == ')') {
                if (m_stack.empty()) return false;//�����������޷�ƥ���ˣ���ʱ�ַ����϶���ƥ�䣬��Ϊ�������޷�������������ƥ��
                m_stack.pop();//��ƥ��ģ�ͨ��pop����ƥ��
            }
        }
        return m_stack.empty() ? true : false;
    }
};

