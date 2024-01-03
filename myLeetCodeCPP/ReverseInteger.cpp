#include "ReverseInteger.h"

int ReverseInteger::reverse(int x) {
    //这里x_int不能使用int类型，因为负数比正数多了1个数，所以可能会溢出
    //这里y_result不能使用int类型，因为可能会溢出
    long long x_int = x;//全部在正数范围内操作，最后再加上符号
    x_int = x_int > 0 ? x_int : -x_int;
    long long y_result = 0;
    for (; x_int; x_int /= 10) {
        y_result = y_result * 10 + x_int % 10;//先将前面的结果乘10也就是进一位个位数变为0，然后再取余数作为新的个位数
    }

    y_result = x > 0 ? y_result : -y_result;//加上符号
    if (y_result > 2147483647 || y_result < -2147483648)
        //溢出返回0
        return 0;
    else
        return y_result;
}

