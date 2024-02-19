#include "LetterCombinationsPhoneNum.h"

vector<string> LetterCombinationsPhoneNum::letterCombinations(string digits) {
	/*17题：电话号码的字母组合
	* 在对于排列组合的问题中可以考虑采用回溯法（递归）
	* 该问题可以用树状图表示，其中最后一层的节点是每个字符串
	* 回溯问题需要解决：递归参数、终止条件、每层的递归
	* 0. 首先先用一个字符串数组来代表按键上每个letter对应的字符串，以数组下标来表示按键的2~9数字
	* 1. 对于递归参数，与树状层数有关，当到达最后一层时，采取措施并逐层return
	*	 1.1 这里的递归函数参数首先是主函数传入的digits，也就是按键数字组合
	*	 1.2 第二个参数是递归层数（深度）index，用于最后一层的判断返回，层数也就是digits的个数
	* 2. 对于终止条件，很明显这里是到达最后一层则返回该层当前的某个组合字符串
	*	 在每一个叶节点返回时，将该树干上存储的s放到result中
	* 3. 最难的是每层的递归
	*	 这里我们递归要得到的结果是该层的展开，因此对于每一条树干，需要有一个s字符串来存储每一层对应取出的字符：这里s设为全局变量
	*	 其次对于每一层index我们从digits[index]可以得到对应按键的可能取值字符，每一层都需要循环所有可能的取值字符，并在每一层将取到的字符push到s中
	*/

	if (digits == "") {//处理特殊情况
		return result;
	}

	backtracking(digits, 0);//从最顶层开始展开树
	return result;
}

void LetterCombinationsPhoneNum::backtracking(const string& digits, int index_layer) {
	//递归回溯函数

	//1. 给出最后一层的终止条件
	if (index_layer == digits.size()) {
		result.push_back(s);//将最后一层的子叶点存入
		return;
	}

	//2. 给出每层的递归展开
	int digit = digits[index_layer] - '0';//该层的对应按键，如"23"中，index_layer=0时，对应按键为'2',通过'2'-'0'得到int值
	string letters = lettersMap[digit];//按键对应含有的所有字符组成的字符串
	for (int i = 0; i < letters.size(); i++) {
		//对该层的所有字符串分别进行展开
		s.push_back(letters[i]);//取出该层的某个字符
		backtracking(digits, index_layer + 1);//展开对应的下一层
		s.pop_back();//回溯，每回溯一次都去除s，这样能保证s的复用性
	}
}

void LetterCombinationsPhoneNum::test_LetterCombinationsPhoneNum() {
	string digits = "23";
	string digits2 = "2";
	LetterCombinationsPhoneNum LCPN;
	vector<string> temp = LCPN.letterCombinations(digits2);
	for (vector<string>::iterator it = temp.begin(); it != temp.end(); it++) {
		cout << *it << " ";
	}
}
