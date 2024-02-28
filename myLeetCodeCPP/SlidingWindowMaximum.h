#pragma once
#include "header.h"
class MyQue {
private:
    // ����m_que���ص㣺
    // 1. �����ǵ����ݼ����У���top->back�����ݼ������ʱά���Ĵ��������ֵ����top()
    // 2. �����е�˳���ǣ�top��->back��
    deque<int> m_que;//˫�˶��У�����βҲ����pop
public:
    //�Զ���һ���������У���ע������ά����ǰ���ڵ����ֵ��top������ͨ��pop�����ǰ��Ҫ���������ڵ�ֵ
    void push(int value) {//value��Ҫ�����ڵ�ֵ
        while (!m_que.empty() && value > m_que.back()) {//���ڵ�ʱ���ܳ����У���Ϊ��Ȼ����pop�����ڵ�ʱ��ͻ���һ����
            //1. ���Ƚ�����ֵ��С��ȫ�������У������ܱ�֤�����ݼ����дӶ���top������back���ǵݼ���
            //1.1 �����������ͷ��pop��������ô��һ��ֵ��Ȼ�ǵ�ǰ�����е����ֵ���������ܱ�֤ά���������ֵ
            //1.2 ����pop��С��ֵ������ν�ģ���Ϊ��ЩС��ֵ�϶�û�취��Ϊ��ǰ���ڵ����ֵ����ȻҲû�취��Ϊ����Ĵ��ڵ����ֵ
            //   ����Ϊ��ЩСֵ���Ƚ����еģ��϶������ڵ�valueҪ��������ڣ�
            m_que.pop_back();
        }
        m_que.push_back(value);//�ٽ���ǰֵ�����У������ڣ�
    }
    void pop(int value) {//value����Ҫ���������ڶ�Ӧ��ֵ
        // 1. value�ǵ�ǰ�������Ĵ���β��ֵ����Ҫ������
        // 2. �����ʱ�ոպ�m_que.top()��value����ô˵������ͷ��������Ҫ�����ֵ��ֻ������˲Ų���Ӱ����洰�����ֵ���жϣ���Ϊ����ͷ�������ֵ�ķ��أ�
        // 3. �����value����top��ֵ����ô˵�����Ѿ���ΪСֵ��push��һ��������ʱ���������
        //    ���ͣ���Ϊ����֪��ÿ��ֵ�ڽ����е�ʱ�򶼻��ǰ���Сֵpop��
        //         a. �����ǰ��value����������top���棨�ȵ�ǰtop����������ǲ����ܵģ���Ϊ��������Ļ���top��Ӧ��ֵ�϶��Ѿ���ɾ���������ڣ���
        //         b. ���Ե�ǰ��valueֻ�����Ǳ�top������ڵģ���ô����ͱ�top�����ֵ�������ˣ����ڶ����ˣ�
        if (value == m_que.front()) {//��������ķ�����ֻ������ж���ͬ����Ҫpop
            m_que.pop_front();
        }
    }
    int getMax() {
        return m_que.front();
    }
};
class SlidingWindowMaximum
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQue que;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);//�ȹ�����ʼk��ֵ�Ĵ���
        }
        result.push_back(que.getMax());
        //����ٲ��ϵش�������һ��һ�������ں��봰��
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);//��ǰֵ������
            que.push(nums[i]);//��һ��ֵ�봰��
            result.push_back(que.getMax());
        }
        return result;
    }
};

