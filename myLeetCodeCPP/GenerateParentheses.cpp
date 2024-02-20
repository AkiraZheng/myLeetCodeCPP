#include "GenerateParentheses.h"

vector<string> GenerateParentheses::generateParenthesis(int n) {
	/*��22�⣺��������
	* ��������������⣬ѡ����ݷ���
	* �������⣺���ݲ�������ֹ����������չ��
	* 1. ���ݲ���
	*	 ���Ȼ�����ȿ϶��Ǹ��������n��صģ����n���ڸ����������������Ƚϣ���ֹ������أ�
	*	 ��α���������У���ϵ���չ������Ҫ����������l��������r�ĸ��������ڳ����Ƿ�ɷ���/�����ţ�����չ����أ�
	* 2. ��ֹ����
	*	 �����������ɹ��������ſ϶��ȷţ�����ÿһ���У������Ÿ���>=�����Ÿ������ǳ���
	*	 �����ֹ�����������Ÿ���==n���������Ϊn
	* 3. ����չ��
	*	 3.0 ��2��֪��������Ҫ��һ���ţ�����������������Ƿ���ʣ�µ�ÿһ���ж��п���ѡ���'('��')'
	*	 3.1 ��������'('����������ֹ�������Ѿ��������������Ϊ�����ˣ����ÿһ�㶼���Է��ĵصݹ鳢�Է�������
	*	 3.2 ��������')'��ÿһ���У������� �����Ÿ���<������ ʱ�������������ɹ����֪��ǰ����Գ��Է�������
	*	 3.3 ���ڷ��������ź��п��ܷ������ţ����ÿ��ݹ�����󣬶�Ҫ�Ƚ���ǰ���������pop���������ڸ���Ϊ���Է�������
	*/
	backtrack(n, 0, 0);
	return result;
}

void GenerateParentheses::backtrack(int n, int l, int r) {
	//2. ��ֹ�����������Ÿ������
	if (l == n) {
		string s_temp = s;
		result.push_back(s_temp.append(n - r, ')'));//��ǰ����n-r�������ţ�����
		return;
	}

	//3. ����չ��
	//3.1 ��������
	s.push_back('(');
	backtrack(n, l + 1, r);//�ݹ�
	s.pop_back();//���ݣ���֤�����ڵ��㿪ʼ���Է�������
	//3.2 ���Է�������
	if (l > r) {//����ǰ�������ű�������������ʱ����ʾ�����Է�������
		s.push_back(')');
		backtrack(n, l, r + 1);
		s.pop_back();
	}
}

void GenerateParentheses::test_GenerateParentheses() {
	GenerateParentheses GP;
	vector<int> test_n{ 3, 1 };
	for (int n : test_n) {
		vector<string> result = GP.generateParenthesis(n);
		for (vector<string>::iterator it = result.begin(); it != result.end(); it++) {
			cout << *it << " ";
		}
		GP.clear_arg();
		cout << endl;
	}
}
