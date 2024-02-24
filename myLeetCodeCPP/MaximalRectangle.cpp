#include "MaximalRectangle.h"

int MaximalRectangle::maximalRectangle(vector<vector<char>>& matrix) {
	/*��85�⣺������
	* ���ö��淨����dp���������⣺��������塢���ƹ�ʽ����ʼ�����顢����˳�����
	* 1. dp���������
	*	 ����һ��rows��cols�Ķ�ά���飬dp[i][j]���ڴ洢�����õ����ڣ�ͬһ����j����ǰ�������1������
	* 2. ���ƹ�ʽ
	*	 2.1 ����dp[i][j]��ʾͬһ����j����ǰ�������1��������Ҳ����˵��� matrix[i][j]!=1����dp[i][j]=0
	*	 2.2 ���� matrix[i][j]==1 ʱ��������ǰһ����dp[i][j-1]������� ͬһ����j-1����ǰ�������1����������� dp[i][j] = dp[i][j-1]+1;
	* 3. ��ʼ������ �� ����˳��
	*	 �ɵ��ƹ�ʽ��֪��Ҫ��dp[i][j]�����ֱ��ͬһ��jǰ��һ����dp[i][j-1]ֵ����˱���˳���ǰ�һ��һ�д�������ɨ��ȥ
	*	 ��˸տ�ʼɨ��ʱ����ֱ��dp[i][0]��Ҳ���ǵ�һ�е�ֵ����Ϊ��һ��û��dp[0][0-1]����ֵ֪��
	*	 ��dp[i][0]��ʼ��Ϊ dp[i][0] = (matrix[i][0]==1) ? 1 : 0
	* 4. ���
	*	 �����й���dp���黹������ÿ������һ��dp[i][j]��ֵ����Ҫ�Ӹõ㿪ʼ��������һ��һ�и����ɸõ�����������ɵ������ε�ֵ
	*	 ���ɸõ�����������ɵľ��ξ��Ǳ���˵Ҫ�� dp[i][j]��������һ������Χ�ɵľ����������ô����Ҫ�� min(dp[i][j]��dp[i-1][j]);��Ϊ�������ܷ�Χ�ɾ����ɶ̱߾���
	*	 ��ôͬ��һ��һ������������ʱ��Ϳ��Բ��ϸ�����̱߲����� dp[i][j]��������ĳ������Χ�ɵľ������
	*	 �ɲ���maxRect�洢�������µ������������return maxRect
	*/

	int maxRect = 0;
	int rows = matrix.size(); int cols = matrix[0].size();
	vector<vector<int>> dp(rows, vector<int>(cols, 0));
	//��ʼ������
	int maxLen = 0;//���ڼ�¼��һ�е��������1�ĸ���
	for (int i = 0; i < rows; i++) {
		if (matrix[i][0] == '1') {
			dp[i][0] = 1;
			maxLen++;
		}
		else {
			dp[i][0] = 0;
			maxRect = max(maxLen, maxRect);
			maxLen = 0;
		}
	}
	maxRect = max(maxLen, maxRect);//���µ�һ�е�������

	//����������ά����
	for (int i = 0; i < rows; i++) {
		for (int j = 1; j < cols; j++) {
			dp[i][j] = (matrix[i][j] == '1') ? dp[i][j - 1] + 1 : 0;

			//��dp[i][j]���������������������
			int min_w = dp[i][j];
			for (int row = i; row >= 0; row--) {//���ϱ�������row��
				min_w = min(min_w, dp[row][j]); int h = i - row + 1;
				maxRect = max(maxRect, min_w * h);
			}
		}
	}
	//printVector(dp);
	return maxRect;
}

void MaximalRectangle::test_MaximalRectangle() {
	MaximalRectangle MR;
	vector<vector<char>> matrix1{ {'1','0','1','0','0'} ,{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
	vector<vector<char>> matrix2{ {'0'} };
	vector<vector<char>> matrix3{ {'1'} };
	cout << MR.maximalRectangle(matrix1) << endl;
	cout << MR.maximalRectangle(matrix2) << endl;
	cout << MR.maximalRectangle(matrix3) << endl;
}

void MaximalRectangle::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << endl;
	}
}
