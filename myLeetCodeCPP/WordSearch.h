#pragma once
#include "header.h"
class WordSearch
{
public:
	vector<vector<bool>> existed;//m*n��С�����ڴ洢�Ƿ��ѱ�ʹ����
	string wordNode;//�洢����֦���Ѿ�ƥ���˵�word��
	int maxRow, maxCol;
	bool backtrack(vector<vector<char>>& board, string word, int gridRow, int gridCol);//gridRow gridCol����ǰ����ӵ�λ��gridRow����ֱ�����˶�ʱֵ��䣬gridCol����ˮƽ����ʱֵ���
	bool exist(vector<vector<char>>& board, string word);
	static void test_WordSearch();
};

