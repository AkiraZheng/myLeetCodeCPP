#include "SingleNumber.h"

int SingleNumber::singleNumber(vector<int>& nums) {
	/*��136�⣺ֻ����һ�ε�����
	* ����ĳ������������ֻ����һ���⣬�����������������
	* ��ô���ǿ����뵽������������Ĺ���
	* ���������г���������5����ô���ǵĶ�����Ϊ 101 ��� 101��������ʱ��λ��Ϊ1���Ϊ0�ͻᱻ���¼���Ϊ0�������Ϊ1������ͨ�������Խ�ż������ͬ��������������Ϊ0
	* ���������ڵ��Ǹ�����ȫ0�������󽫻ᱻ��������
	*/
	int result = 0;
	for (int i : nums) {
		result ^= i;
	}
	return result;
}
void SingleNumber::test_SingleNumber() {
	SingleNumber SN;
	vector<vector<int>> nums{ {2,2,1},{4,1,2,1,2},{1} };
	for (auto& temp : nums) {
		cout << SN.singleNumber(temp) << endl;
	}
}
