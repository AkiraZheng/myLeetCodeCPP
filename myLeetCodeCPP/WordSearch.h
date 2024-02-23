#pragma once
#include "header.h"
class WordSearch
{
public:
	vector<vector<bool>> existed;//m*n大小，用于存储是否已被使用了
	string wordNode;//存储该树枝上已经匹配了的word串
	int maxRow, maxCol;
	bool backtrack(vector<vector<char>>& board, string word, int gridRow, int gridCol);//gridRow gridCol：当前层格子的位置gridRow代表垂直方向运动时值会变，gridCol代表水平方向时值会变
	bool exist(vector<vector<char>>& board, string word);
	static void test_WordSearch();
};

