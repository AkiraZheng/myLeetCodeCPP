#include "LongestValidParentheses.h"

int LongestValidParentheses::longestValidParentheses(string s) {
	/*第32题：最长有效括号
	* 参考第20题“有效的括号”思路，通过栈来判断该串是否为有效括号
	* 1. 左括号入栈：入栈符号为')' 这里其实入栈符号是啥都行，但是为了与20题统一，还是选择入右括号
	* 2. 右括号
	*	 2.1 如果栈为空，则表示没有匹配的字符，需要循环找到下一个左括号的位置，并更新最后右括号的index
	*	 2.2 右括号出栈：stack不为空则pop一个栈顶，出栈后若栈空了，说明该轮最长有效字符串也结束了，需要重新更新有效长度
	*		 2.2.1 出栈后栈空：更新有效长度需要注意，虽然当前栈空了，但不代表本轮结束了，因为后面依然可能还是合法的括号
	*		 所以我们需要一个last_pos来记录最后一次出现有效')'的位置
	*		 2.2.2 出栈后栈非空：不管后面还是否合法，先根据栈顶的值更新当前暂时的有效括号最大值，防止错过
	*/

	stack<int> matchStack;//记录栈中最后一个左括号的位置
	int max_len = 0, last_pos = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			//1. 左括号入栈
			matchStack.push(i);
		}
		else {
			//2. 右括号出栈
			//2.1 如果栈为空，则表示没有匹配的字符，因此可以更新右括号的位置了，直到找到左括号为止
			if (matchStack.empty()) {
				while (i != s.size()-1 && s[i + 1] != '(') i++;
				last_pos = i;
			}
			//2.2 栈不为空，出栈，出栈后若栈空了，
			else {
				matchStack.pop();
				if (matchStack.empty()) {
					//2.2.1 栈空，需要更新当前有效长度，但是注意，此时后面可能还有连续的有效字符串，因此还不能更新last_pos
					max_len = max(max_len, i-last_pos);
				}
				else {
					//2.2.2 出栈后栈不为空，也要更新当前暂时的最长有效长度
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
