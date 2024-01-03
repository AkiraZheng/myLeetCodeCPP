#include "ZigzagConversion.h"
string ZigzagConversion::convert(string s, int nRows) {
    string result;
    int n = s.size(), col_space = (nRows - 2) + 1;//字符个数、垂直列的间隔
    if (nRows == 1) return s;

    int j_temp, index_temp;//临时变量，用于存储当前倾斜列的列数和字符索引
    for (int i = 0; i < nRows; i++) {
        for (int j = 0, index = i; index < n; ) {
            result.append(1, s[index]);//添加垂直列的字符
            j += col_space;//更新下一轮垂直列的列数
            index = 2 * j + i;//更新下一轮垂直列的字符索引
            if (i != 0 && i != nRows - 1) {
                //首尾两行无斜列，除外的行需要添加斜列的字符
                j_temp = j - i; index_temp = 2 * j_temp + i;
                if (index_temp < n) result.append(1, s[index_temp]);//添加斜列的字符
            }
        }
    }
    return result;
}

