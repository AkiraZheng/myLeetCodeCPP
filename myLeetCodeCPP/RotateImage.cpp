#include "RotateImage.h"

void RotateImage::rotate(vector<vector<int>>& matrix) {
	/*��48�⣺��תͼ��
	* (n+1)*(n+1)���飺��3*3����Ϊ������ת����ֱ�ۿ��Կ�����i�е����ݱ�ֱ��ת���˵�n-i��
	*				   �������ڱ�����ԭ������ת�����ܽ�����һ����������ȡ��Ӧλ�õ���ֵ
	* 				   ������ǿ��Թ۲쵽����ά�����������ߣ���ʵÿ��תһ���㣬��Ӧ����4�����ϵĵ�Ҳ������ת�������ת�ظõ㣬��˿�����4�������תΪһ���ֻ�
	* 0. ���ݣ���i��->��n-i�еĹ��ɣ�Ҳ������ת�������ֱ�ӱ�Ϊj����������Ϊn-i�����ǿ����ܽ��A[i,j]��ת����A[j, n-i]�������һ��4����ֻؿ��Ա�ʾΪ��
	*	 0.1 A[i,j]->A[j, n-i]
	*	 0.2 A[j, n-i]->A[n-i, n-j]
	*	 0.3 A[n-i, n-j]->A[n-j, i]
	*	 0.4 A[n-j, i]->A[i, j]
	* 1. ��������һȦ��������һȦ�Ĺ�������ת
	* 2. ����i��ѭ����ΧΪ[0,n/2��������ѭ��n/2Ȧ
	*	 2.1 ����j��ѭ��ѭ����ΧΪ[i, n-i-1]	�ҷ�ΧҪ��ȥ�ĸ��ǣ�����ÿȦ��Ҫ��ת�Ĵ���Ϊn-i-1
	*/

	int n = matrix.size() - 1;//�����n�����������������������������/�е�index
	for (int i = 0; i < matrix.size() / 2; i++) {
		for (int j = i; j <= n - i - 1; j++) {
			int temp = matrix[j][n - i];
			matrix[j][n - i] = matrix[i][j];
			int temp2 = matrix[n - i][n - j];
			matrix[n - i][n - j] = temp;
			temp = matrix[n - j][i];
			matrix[n - j][i] = temp2;
			matrix[i][j] = temp;
		}
	}
}
void RotateImage::test_RotateImage() {
	RotateImage RI;
	vector<vector<int>> matrix{ {5,1,9,11},{2, 4, 8, 10},{13, 3, 6, 7},{15, 14, 12, 16} };
	cout << "--------ԭʼ����---------" << endl;
	RI.printVector(matrix);
	cout << "--------��ת����---------" << endl;
	RI.rotate(matrix);
	RI.printVector(matrix);

}

void RotateImage::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << endl;
	}
}
