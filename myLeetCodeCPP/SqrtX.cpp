#include "SqrtX.h"
int SqrtX::mySqrt(int x) {
	if (x < 2) return x;
	int left = 1; int right = x / 2; int mid = 0;
	int result = 0;
	while (left <= right) {
		mid = (right + left) >> 1;
		if (x / mid < mid) {
			right = mid - 1;
		}
		else if (x / mid > mid) {
			left = mid + 1;
			result = mid;
		}
		else {
			//找到相等的，直接return
			return mid;
		}
	}
	return result;
}