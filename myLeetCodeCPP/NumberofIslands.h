#pragma once
#include "header.h"
class NumberofIslands
{
private:
	vector<vector<bool>> visted;
	int result;
	int routes[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
	int rows, cols;
public:
	int numIslands(vector<vector<char>>& grid);
	void dfsIsland(vector<vector<char>>& grid, int x, int y);
	static void test_NumberofIslands();
};

