#include "PalindromeNumber.h"
bool PalindromeNumber::isPalindrome(int x) {
	if (x < 0) return false;
	//char right_diwei = 0, left_diwei = 0;
	int right_diwei = 0, left_diwei = 0;
	int d = 1;//用于更新当前的最高位
	while (x / d >= 10) d *= 10;//找到最大位的值，如x=2013时，d = 1000
	//通过数据对称性，求10的余数找到当前低位数值0~9，求d的除数找到当前最高位的数值0~9
	while (x > 0) {
		right_diwei = x % 10;
		left_diwei = x / d;
		if (right_diwei != left_diwei) return false;//此时对称的两位不相同，直接返回不是回文数
		x = x % d / 10;//去最高位去最低位更新x
		d /= 100;
	}
	return true;
}