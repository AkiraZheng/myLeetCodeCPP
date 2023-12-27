#include "StringToInteger.h"

int StringToInteger::myAtoi(string str) {
	int result = 0;
	char temp_gewei = 0;
	int str_size = str.size();
	bool sign_flag = false;// false: positive, true: negative 默认为正数
	int index = 0;
	char max_gewei = INT_MAX % 10;
	while (str[index] == ' ' && index < str_size) {index++;}//根据题意，前导码只有空格，因此空格外第一个字符即为有效字符
	//判断正负号:这里不能用三目运算符的方式，因为会导致无符号的字符串（如"123"）取值出错
	if (str[index] == '-') {
		index++;
		sign_flag = true;
	}
	else if (str[index] == '+') {
		index++;
	}
	for (; index < str_size; index++) {
		//1. 过滤无用字符
		if (str[index] < '0' || str[index] > '9') {break;}//出现非数字字符后说明连续的数字部分已经结束，跳出循环
		//2. 判断是否溢出
		temp_gewei = str[index] - '0';//巧妙地用char型 str[index] - '0' 代表本轮的数值
		if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && temp_gewei > max_gewei)) {
			//溢出或刚好为INT_MIN
			return (sign_flag) ? INT_MIN : INT_MAX;
		}
		//3. 更新本轮结果
		result = result * 10 + temp_gewei;
	}
	return (sign_flag) ? (-1) * result : result;
}