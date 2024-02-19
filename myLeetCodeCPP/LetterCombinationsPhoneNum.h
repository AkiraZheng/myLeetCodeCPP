#pragma once
#include "header.h"
class LetterCombinationsPhoneNum
{
private:
	const string lettersMap[10] = {
		"",//0
		"",//1
		"abc",//2
		"def",//3
		"ghi",//4
		"jkl",//5
		"mno",//6
		"pqrs",//7
		"tuv",//8
		"wxyz",//9
	};
public:
	vector<string> result;
	string s;
	vector<string> letterCombinations(string digits);
	void backtracking(const string & digits, int index_layer);
	static void test_LetterCombinationsPhoneNum();
};

