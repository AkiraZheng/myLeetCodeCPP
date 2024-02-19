#include "ValidParentheses.h"

bool ValidParentheses::isValid(string s) {
	/*��20�⣺��Ч������
	* �������飬���ó���ջ�ķ�ʽ��ƥ��
	* 0. ������Ҫ����ƥ�䣬��˵�����s�϶���ƥ��
	* 1. ��ջ���������󣨴�����ʱ����ջһ���ң�������
	* 2. ��ջ���������ң�������ʱ��ƥ�䵱ǰջ���Ƿ�Ϊ�÷��ţ��������ջ����������˵������s��ƥ����ȷ�����Ÿ�ʽ
	*/

	//0. ������Ҫ����ƥ�䣬��˵�����s�϶���ƥ��
	if (s.size() % 2 != 0) return false;

	stack<char> matchStack;//����һ��ջ
	for (char temp : s) {
		//1. ��ջ���������󣨴�����ʱ����ջһ���ң�������
		if (temp == '(') matchStack.push(')');
		else if (temp == '{') matchStack.push('}');
		else if (temp == '[') matchStack.push(']');
		//2. ��ջ��ʣ�µ���������ұ߷�����
		else if (matchStack.empty() || temp != matchStack.top()) return false;//ջ�Ѿ�Ϊ�� ���� ��ջ����ƥ�䣨˳�����ң������ڿ�ջ������µ���matchStack.top()�ᱨ��
		else matchStack.pop();
	}
	return matchStack.empty();
}

void ValidParentheses::test_ValidParentheses() {
	ValidParentheses VP;
	vector<string>s = { "()" , "()[]{}" , "(]" , "{[]}", "){"};
	for (string temp:s) {
		cout << VP.isValid(temp) << endl;
	}
}
