#include "ClimbingStairs.h"

int ClimbingStairs::climbStairs(int n) {
	/*��70�⣺��¥��
	* ���ö�̬�滮������ͨ��dp��һά�������洢�ߵ�i�����ܷ�������ע������������index=-1�ף���û�ϵ�һ�ף�
	* 1. ���麬��
	*	 dp[i]��ʾ�ߵ�i�����ܷ�����
	* 2. �Ƶ�����
	*	 ����ֻ����1-2������˵�i��¥��ֻ���ܴӵ�i-1���i-2��¥��������������ߵ���i�׹���dp[i-1]+dp[i-2]�ַ���
	*	 dp[i] = dp[i-1] + dp[i-2]
	* 3. �����ʼ����ע������������index=-1�ף���û�ϵ�һ�ף�
	*	 dp[0]��һ��̨��ֻ��һ�ֿ��ܣ�Ϊ1
	*	 dp[1]�ڶ���̨����2�ֿ��ܣ�һ���Ǵӵ�һ��һ��������һ���Ǵ�-1��ֱ����������
	* 4. ����˳��
	*	 ������һά���飬����˳��ܼ򵥣���i=2��ʼ��������
	*/

	if (n == 1) return 1;
	vector<int> dp(n, 0);
	dp[0] = 1; dp[1] = 2;
	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n - 1];
}
void ClimbingStairs::test_ClimbingStairs() {
	ClimbingStairs CS;
	vector<int> n{ 1, 2, 3, 4, 5, 6 };
	for (int temp : n) {
		cout << CS.climbStairs(temp) << endl;
	}
}
