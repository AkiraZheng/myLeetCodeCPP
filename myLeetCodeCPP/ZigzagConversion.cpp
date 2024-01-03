#include "ZigzagConversion.h"
string ZigzagConversion::convert(string s, int nRows) {
    string result;
    int n = s.size(), col_space = (nRows - 2) + 1;//�ַ���������ֱ�еļ��
    if (nRows == 1) return s;

    int j_temp, index_temp;//��ʱ���������ڴ洢��ǰ��б�е��������ַ�����
    for (int i = 0; i < nRows; i++) {
        for (int j = 0, index = i; index < n; ) {
            result.append(1, s[index]);//��Ӵ�ֱ�е��ַ�
            j += col_space;//������һ�ִ�ֱ�е�����
            index = 2 * j + i;//������һ�ִ�ֱ�е��ַ�����
            if (i != 0 && i != nRows - 1) {
                //��β������б�У����������Ҫ���б�е��ַ�
                j_temp = j - i; index_temp = 2 * j_temp + i;
                if (index_temp < n) result.append(1, s[index_temp]);//���б�е��ַ�
            }
        }
    }
    return result;
}

