#pragma once
#include "header.h"
class HappyNumber
{
public:
    bool isHappy(int n) {
        /*��202�⣺������
        * ����ѭ������ʾ��֪����һ����ͨ����ȡ��λ�����ƽ���͵�ֵ�������ֹ�����˵��������ѭ��ģʽ��return false
        * �������������һ��spiltNums������n������ȡ�����ָ��¾���
        */

        unordered_set<int> used;//�洢���ֹ������֣������˳���ѭ��
        used.insert(n);
        while (n != 1) {
            vector<int> nums = spiltNums(n);//ȡ������λ

            n = 0;//���¼���n
            for (int i : nums) {
                n += i * i;//����ƽ����
            }

            if (used.find(n) != used.end()) return false;//��������ͬ�ģ��������ѭ��

            used.insert(n);//������ֵ
        }
        return true;
    }

    vector<int> spiltNums(int n) {
        //������n�ĵĸ�λ��ȡ����
        vector<int> nums;
        while (n != 0) {
            //����ȡλ
            nums.push_back(n % 10);
            //����ɾ����λ
            n /= 10;
        }
        return nums;
    }
};

