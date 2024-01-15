#include "ValidPerfectSquare.h"

bool ValidPerfectSquare::isPerfectSquare(int num) {
	if (num == 1)return true;
	int left = 1;
	int right = num / 2;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) >> 1;
		//num > mid^2，说明得更新left向右靠拢
		if (num / mid > mid) {
			left = mid + 1;
		}
		else if (num / mid < mid) {
			right = mid - 1;
		}
		else {
			//相等的情况下还要判断是否余数为0
			return (num % mid == 0) ? true : false;
		}
	}
	return false;
}
