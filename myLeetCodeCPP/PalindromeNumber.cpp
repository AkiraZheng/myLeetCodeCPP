#include "PalindromeNumber.h"
bool PalindromeNumber::isPalindrome(int x) {
	if (x < 0) return false;
	//char right_diwei = 0, left_diwei = 0;
	int right_diwei = 0, left_diwei = 0;
	int d = 1;//���ڸ��µ�ǰ�����λ
	while (x / d >= 10) d *= 10;//�ҵ����λ��ֵ����x=2013ʱ��d = 1000
	//ͨ�����ݶԳ��ԣ���10�������ҵ���ǰ��λ��ֵ0~9����d�ĳ����ҵ���ǰ���λ����ֵ0~9
	while (x > 0) {
		right_diwei = x % 10;
		left_diwei = x / d;
		if (right_diwei != left_diwei) return false;//��ʱ�ԳƵ���λ����ͬ��ֱ�ӷ��ز��ǻ�����
		x = x % d / 10;//ȥ���λȥ���λ����x
		d /= 100;
	}
	return true;
}