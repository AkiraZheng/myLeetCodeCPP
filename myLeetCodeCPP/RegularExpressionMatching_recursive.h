#pragma once
#include <string>
using namespace std;
class RegularExpressionMatching_recursive
{
public:
	bool isMatch(const string &s, const string &p) {
		return isMatch(s.c_str(), p.c_str());//�ݹ鷵�ؽ��
	}
private:
	bool isMatch(const char* s, const char* p);//ע�������iaMatch���������������� (*s��������char) �� (*p��������char) ��ƥ�䣬�����ǵ����ַ�s��pƥ��
};

