#pragma once
#include "header.h"
class FindAllAnagramsinaString
{
public:
    vector<int> findAnagrams(string s, string p) {
        /*��438��:�ҵ��ַ�����������ĸ��λ��
        * ��������,���ڴ�С����p.size()
        * ��unordered_mapά��Ŀ��p����Ҫ�������ĸkey,�Լ���ĸ��Ӧ��Ҫ�ĸ���value
        *                ά�������д��ڵ���Ŀ��p��ͬ��ĸkey,�Լ�key�ڴ����ж�Ӧ������value
        * ������ĳ����ĸ��key���ܻ��Ŀ���������,���Ի�Ҫһ��int valid������ά����������ȫ����Ŀ����ĸ����ĸ���(map_p.size())
        */

        vector<int> result;//���ƥ�䴰�ڵ���ָ��
        if (s.size() < p.size()) return result;

        unordered_map<char, int> map_p, map_window;
        //1. ����Ŀ��p�Ĺ�ϣ��
        for (char c : p) {
            map_p[c]++;
        }
        int valid = 0, valid_target = map_p.size();
        //2. �������ڼ���ƥ���λ��
        int left = 0, right = 0;
        while (right < s.size()) {
            //a.�Ҵ���
            //����ǰ���ڵ���ֵ�봰��
            char right_c = s[right];
            if (map_p.find(right_c) != map_p.end()) {
                //���ַ���Ŀ���ַ���
                map_window[right_c]++;
                if (map_window[right_c] == map_p[right_c]) valid++;
            }
            //�Ҵ�����
            right++;

            //���󴰿�
            while (right - left + 1 > p.size()) {//�����ڱ�Ŀ�괰�ڴ�ʱ,��Ҫ���󴰿�,��������ҿ�[left,right)
                char left_c = s[left];
                //������ǰ���жϵ�ǰ�����Ƿ�����Ҫ����
                if (valid == valid_target) result.push_back(left);//��ӽ��
                //��������:����left�ַ�,�����Ŀ��p�Ļ�,��Ҫ�����ж�Ӧ��ֵ��1;����Ŀ��ֵ�Ļ�,��ô˵������ʵҲ���ڴ���ֵ��,����ֱ�Ӻ���
                if (map_p.find(left_c) != map_p.end()) {
                    //��֮ǰ��Ҫ�ȿ��ǵ�ǰ�ַ��ǲ������Ѿ�valid��ֵ��
                    if (map_window[left_c] == map_p[left_c]) valid--;//��valid��ֵ��
                    map_window[left_c]--;
                }
                left++;//�������Ϳ��Գ�������
            }
        }
        return result;
    }
};

