#include "GenerateParentheses.h"

vector<string> GenerateParentheses::generateParenthesis(int n) {
	/*第22题：括号生成
	* 考虑排列组合问题，选择回溯方法
	* 回溯问题：回溯参数、终止条件、单层展开
	* 1. 回溯参数
	*	 首先回溯深度肯定是跟传入参数n相关的，深度n用于跟左括号最大个数作比较（终止条件相关）
	*	 其次本题的条件中，结合单层展开，需要传入左括号l和右括号r的个数，用于尝试是否可放左/右括号（单层展开相关）
	* 2. 终止条件
	*	 根据括号生成规则，左括号肯定先放，且在每一层中，左括号个数>=右括号个数总是成立
	*	 因此终止条件是左括号个数==n，树的深度为n
	* 3. 单层展开
	*	 3.0 由2可知，左括号要第一个放，解决了这个问题后，我们发现剩下的每一层中都有可能选择放'('或')'
	*	 3.1 放左括号'('：由于在终止条件中已经把左括号溢出作为条件了，因此每一层都可以放心地递归尝试放左括号
	*	 3.2 放右括号')'：每一层中，当满足 右括号个数<左括号 时，根据括号生成规则可知当前层可以尝试放右括号
	*	 3.3 由于放完左括号后还有可能放右括号，因此每层递归回来后，都要先将当前层的左括号pop出来，用于更改为尝试放右括号
	*/
	backtrack(n, 0, 0);
	return result;
}

void GenerateParentheses::backtrack(int n, int l, int r) {
	//2. 终止条件：左括号个数溢出
	if (l == n) {
		string s_temp = s;
		result.push_back(s_temp.append(n - r, ')'));//当前还差n-r个右括号，补齐
		return;
	}

	//3. 单层展开
	//3.1 放左括号
	s.push_back('(');
	backtrack(n, l + 1, r);//递归
	s.pop_back();//回溯，保证下面在单层开始尝试放右括号
	//3.2 尝试放右括号
	if (l > r) {//当当前层左括号比右括号数量多时，表示还可以放右括号
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
