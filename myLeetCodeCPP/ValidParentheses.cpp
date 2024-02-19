#include "ValidParentheses.h"

bool ValidParentheses::isValid(string s) {
	/*第20题：有效的括号
	* 根据提议，采用出入栈的方式来匹配
	* 0. 由于需要左右匹配，因此单数的s肯定不匹配
	* 1. 入栈：当遇到左（大）括号时，入栈一个右（大）括号
	* 2. 出栈：当遇到右（大）括号时，匹配当前栈顶是否为该符号，若是则出栈，若不是则说明整个s不匹配正确的括号格式
	*/

	//0. 由于需要左右匹配，因此单数的s肯定不匹配
	if (s.size() % 2 != 0) return false;

	stack<char> matchStack;//创建一个栈
	for (char temp : s) {
		//1. 入栈：当遇到左（大）括号时，入栈一个右（大）括号
		if (temp == '(') matchStack.push(')');
		else if (temp == '{') matchStack.push('}');
		else if (temp == '[') matchStack.push(']');
		//2. 出栈：剩下的情况都是右边符号了
		else if (matchStack.empty() || temp != matchStack.top()) return false;//栈已经为空 或者 与栈顶不匹配（顺序不能乱，否则在空栈的情况下调用matchStack.top()会报错）
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
