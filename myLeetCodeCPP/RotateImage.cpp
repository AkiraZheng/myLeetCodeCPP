#include "RotateImage.h"

void RotateImage::rotate(vector<vector<int>>& matrix) {
	/*第48题：旋转图像
	* (n+1)*(n+1)数组：以3*3数组为例，旋转完后很直观可以看出第i行的数据被直接转成了第n-i列
	*				   但是由于必须在原数组上转，不能借助另一个数组来提取对应位置的数值
	* 				   因此我们可以观察到，二维数组有四条边，其实每旋转一个点，对应另外4条边上的点也跟着旋转，最后在转回该点，因此可以以4个点的旋转为一个轮回
	* 0. 根据：第i行->第n-i列的规律，也就是旋转后的行数直接变为j，而列数变为n-i；我们可以总结除A[i,j]旋转后将在A[j, n-i]处，因此一个4点的轮回可以表示为：
	*	 0.1 A[i,j]->A[j, n-i]
	*	 0.2 A[j, n-i]->A[n-i, n-j]
	*	 0.3 A[n-i, n-j]->A[n-j, i]
	*	 0.4 A[n-j, i]->A[i, j]
	* 1. 按从外面一圈到最里面一圈的规律来旋转
	* 2. 对于i的循环范围为[0,n/2），代表循环n/2圈
	*	 2.1 对于j的循环循环范围为[i, n-i-1]	右范围要除去四个角，代表每圈需要旋转的次数为n-i-1
	*/

	int n = matrix.size() - 1;//这里的n不代表行数或列数，而代表最低行/列的index
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
	cout << "--------原始数据---------" << endl;
	RI.printVector(matrix);
	cout << "--------旋转数据---------" << endl;
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
