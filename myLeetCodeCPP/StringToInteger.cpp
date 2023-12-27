#include "StringToInteger.h"

int StringToInteger::myAtoi(string str) {
	int result = 0;
	char temp_gewei = 0;
	int str_size = str.size();
	bool sign_flag = false;// false: positive, true: negative Ĭ��Ϊ����
	int index = 0;
	char max_gewei = INT_MAX % 10;
	while (str[index] == ' ' && index < str_size) {index++;}//�������⣬ǰ����ֻ�пո���˿ո����һ���ַ���Ϊ��Ч�ַ�
	//�ж�������:���ﲻ������Ŀ������ķ�ʽ����Ϊ�ᵼ���޷��ŵ��ַ�������"123"��ȡֵ����
	if (str[index] == '-') {
		index++;
		sign_flag = true;
	}
	else if (str[index] == '+') {
		index++;
	}
	for (; index < str_size; index++) {
		//1. ���������ַ�
		if (str[index] < '0' || str[index] > '9') {break;}//���ַ������ַ���˵�����������ֲ����Ѿ�����������ѭ��
		//2. �ж��Ƿ����
		temp_gewei = str[index] - '0';//�������char�� str[index] - '0' �����ֵ���ֵ
		if (result > (INT_MAX / 10) || (result == (INT_MAX / 10) && temp_gewei > max_gewei)) {
			//�����պ�ΪINT_MIN
			return (sign_flag) ? INT_MIN : INT_MAX;
		}
		//3. ���±��ֽ��
		result = result * 10 + temp_gewei;
	}
	return (sign_flag) ? (-1) * result : result;
}