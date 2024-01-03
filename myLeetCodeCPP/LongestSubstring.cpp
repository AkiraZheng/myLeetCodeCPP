#include "LongestSubstring.h"
int LongestSubstring::lengthOfLongestSubstring(string s) {
    int last[255];//����255Ϊ����ASCII�����������ڴ������ַ�
    fill(last, last + 255, -1);//��ʼ��last����
    int max_len = 0;
    int start_index = 0;//�������round�����ĳ�ʼ����
    for (int i = 0; i < s.size(); i++) {
        if (last[s[i]] >= start_index) {//˵���ڸ����г��ֹ�������ţ��������ظ�
            max_len = max(max_len, i - start_index);//ע�����һ��ʱ������һ����ĸû���ֹ������޷��������һ�ֵ�len����������returnʱ��Ҫ��������һ��ȡֵ
            start_index = last[s[i]] + 1;//������һ��round��������ʼindex
        }
        last[s[i]] = i;//����s[i]�ַ���Ӧ������������last��
    }
    return max(max_len, (int)s.size() - start_index);//���һ�ֳ�����ǰ����󳤶ȵıȽ�
}
