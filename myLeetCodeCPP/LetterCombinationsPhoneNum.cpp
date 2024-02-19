#include "LetterCombinationsPhoneNum.h"

vector<string> LetterCombinationsPhoneNum::letterCombinations(string digits) {
	/*17�⣺�绰�������ĸ���
	* �ڶ���������ϵ������п��Կ��ǲ��û��ݷ����ݹ飩
	* �������������״ͼ��ʾ���������һ��Ľڵ���ÿ���ַ���
	* ����������Ҫ������ݹ��������ֹ������ÿ��ĵݹ�
	* 0. ��������һ���ַ�����������������ÿ��letter��Ӧ���ַ������������±�����ʾ������2~9����
	* 1. ���ڵݹ����������״�����йأ����������һ��ʱ����ȡ��ʩ�����return
	*	 1.1 ����ĵݹ麯�����������������������digits��Ҳ���ǰ����������
	*	 1.2 �ڶ��������ǵݹ��������ȣ�index���������һ����жϷ��أ�����Ҳ����digits�ĸ���
	* 2. ������ֹ�����������������ǵ������һ���򷵻ظò㵱ǰ��ĳ������ַ���
	*	 ��ÿһ��Ҷ�ڵ㷵��ʱ�����������ϴ洢��s�ŵ�result��
	* 3. ���ѵ���ÿ��ĵݹ�
	*	 �������ǵݹ�Ҫ�õ��Ľ���Ǹò��չ������˶���ÿһ�����ɣ���Ҫ��һ��s�ַ������洢ÿһ���Ӧȡ�����ַ�������s��Ϊȫ�ֱ���
	*	 ��ζ���ÿһ��index���Ǵ�digits[index]���Եõ���Ӧ�����Ŀ���ȡֵ�ַ���ÿһ�㶼��Ҫѭ�����п��ܵ�ȡֵ�ַ�������ÿһ�㽫ȡ�����ַ�push��s��
	*/

	if (digits == "") {//�����������
		return result;
	}

	backtracking(digits, 0);//����㿪ʼչ����
	return result;
}

void LetterCombinationsPhoneNum::backtracking(const string& digits, int index_layer) {
	//�ݹ���ݺ���

	//1. �������һ�����ֹ����
	if (index_layer == digits.size()) {
		result.push_back(s);//�����һ�����Ҷ�����
		return;
	}

	//2. ����ÿ��ĵݹ�չ��
	int digit = digits[index_layer] - '0';//�ò�Ķ�Ӧ��������"23"�У�index_layer=0ʱ����Ӧ����Ϊ'2',ͨ��'2'-'0'�õ�intֵ
	string letters = lettersMap[digit];//������Ӧ���е������ַ���ɵ��ַ���
	for (int i = 0; i < letters.size(); i++) {
		//�Ըò�������ַ����ֱ����չ��
		s.push_back(letters[i]);//ȡ���ò��ĳ���ַ�
		backtracking(digits, index_layer + 1);//չ����Ӧ����һ��
		s.pop_back();//���ݣ�ÿ����һ�ζ�ȥ��s�������ܱ�֤s�ĸ�����
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
