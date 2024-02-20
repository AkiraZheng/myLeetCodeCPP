#pragma once
#include "header.h"
class GenerateParentheses
{
private:
	string s;
	vector<string> result;
	void backtrack(int n, int l, int r);
public:
	vector<string> generateParenthesis(int n);
	static void test_GenerateParentheses();
	void clear_arg() {
		s.clear(); result.clear();
	}
};

