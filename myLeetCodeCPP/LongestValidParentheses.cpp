#include "LongestValidParentheses.h"

int LongestValidParentheses::longestValidParentheses(string s) {
	/*��32�⣺���Ч����
	* �ο���20�⡰��Ч�����š�˼·��ͨ��ջ���жϸô��Ƿ�Ϊ��Ч����
	* 1. ��������ջ����ջ����Ϊ')' ������ʵ��ջ������ɶ���У�����Ϊ����20��ͳһ������ѡ����������
	* 2. ������
	*	 2.1 ���ջΪ�գ����ʾû��ƥ����ַ�����Ҫѭ���ҵ���һ�������ŵ�λ�ã���������������ŵ�index
	*	 2.2 �����ų�ջ��stack��Ϊ����popһ��ջ������ջ����ջ���ˣ�˵���������Ч�ַ���Ҳ�����ˣ���Ҫ���¸�����Ч����
	*		 2.2.1 ��ջ��ջ�գ�������Ч������Ҫע�⣬��Ȼ��ǰջ���ˣ����������ֽ����ˣ���Ϊ������Ȼ���ܻ��ǺϷ�������
	*		 ����������Ҫһ��last_pos����¼���һ�γ�����Ч')'��λ��
	*		 2.2.2 ��ջ��ջ�ǿգ����ܺ��滹�Ƿ�Ϸ����ȸ���ջ����ֵ���µ�ǰ��ʱ����Ч�������ֵ����ֹ���
	*/

	stack<int> matchStack;//��¼ջ�����һ�������ŵ�λ��
	int max_len = 0, last_pos = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			//1. ��������ջ
			matchStack.push(i);
		}
		else {
			//2. �����ų�ջ
			//2.1 ���ջΪ�գ����ʾû��ƥ����ַ�����˿��Ը��������ŵ�λ���ˣ�ֱ���ҵ�������Ϊֹ
			if (matchStack.empty()) {
				while (i != s.size()-1 && s[i + 1] != '(') i++;
				last_pos = i;
			}
			//2.2 ջ��Ϊ�գ���ջ����ջ����ջ���ˣ�
			else {
				matchStack.pop();
				if (matchStack.empty()) {
					//2.2.1 ջ�գ���Ҫ���µ�ǰ��Ч���ȣ�����ע�⣬��ʱ������ܻ�����������Ч�ַ�������˻����ܸ���last_pos
					max_len = max(max_len, i-last_pos);
				}
				else {
					//2.2.2 ��ջ��ջ��Ϊ�գ�ҲҪ���µ�ǰ��ʱ�����Ч����
					max_len = max(max_len, i - matchStack.top());
				}
			}
		}
	}

	return max_len;
}

void LongestValidParentheses::test_LongestValidParentheses() {
	LongestValidParentheses LVP;
	vector<string> test_s{ "(()", ")()())" , "" , "()" };
	for (string s : test_s) {
		cout << LVP.longestValidParentheses(s) << endl;
	}
}
