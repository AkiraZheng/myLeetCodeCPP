#include "ContainerWithMostWater.h"

int ContainerWithMostWater::maxArea(vector<int>& height) {
	/*
	* ʹ��˫ָ�뷽����������������˲������м俿
	* �������ݻ������˵ľ����йأ���˴���Զ�����˿�ʼ������֤���
	* �������ݻ�������̰��йأ���˵����˳��ֽ�Ϊ�̵İ�ʱ�����ð壬��һ����ʱ����
	*/
	int left = 0, right = height.size() - 1;
	int max_v = 0, temp_v = 0;
	while (left < right) {
		temp_v = min(height[left], height[right]) * (right - left);//����˴�����Χ�ɵ��ݻ�
		max_v = max(max_v, temp_v);//ȡ�ݻ����ֵ
		if (height[left] <= height[right]) {//�������м��������̰�
			left++;
		}
		else {
			right--;
		}
	}
	return max_v;
}

void ContainerWithMostWater::test_maxArea() {
	ContainerWithMostWater CWMW;
	vector<int> test_num1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << CWMW.maxArea(test_num1) << endl;
}