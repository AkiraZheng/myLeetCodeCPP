#include "ValidPerfectSquare.h"

bool ValidPerfectSquare::isPerfectSquare(int num) {
	if (num == 1)return true;
	int left = 1;
	int right = num / 2;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) >> 1;
		//num > mid^2��˵���ø���left���ҿ�£
		if (num / mid > mid) {
			left = mid + 1;
		}
		else if (num / mid < mid) {
			right = mid - 1;
		}
		else {
			//��ȵ�����»�Ҫ�ж��Ƿ�����Ϊ0
			return (num % mid == 0) ? true : false;
		}
	}
	return false;
}
