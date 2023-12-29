#pragma once
#include <string>
using namespace std;
class RegularExpressionMatching_recursive
{
public:
	bool isMatch(const string &s, const string &p) {
		return isMatch(s.c_str(), p.c_str());//递归返回结果
	}
private:
	bool isMatch(const char* s, const char* p);//注：这里的iaMatch函数代表的是输入的 (*s及其后面的char) 与 (*p及其后面的char) 相匹配，而不是单个字符s和p匹配
};

