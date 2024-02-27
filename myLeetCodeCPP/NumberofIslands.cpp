#include "NumberofIslands.h"

int NumberofIslands::numIslands(vector<vector<char>>& grid) {
	/*��200�⣺��������
	* ���ѣ��ݹ飩dfs
	* a. ��һ��visted�洢ĳ��[i,j]�Ƿ��Ѿ�����������
	* b. �������б���ÿ���㣬���������δ�������ĵ㣬��˵�����µ��죬result++��
	* c. dfs�ݹ麯���а�����->��->��->�ҵ�˳��ݹ飬�����������д�����µ��������ǵĵ㣬������Ӧ��visited��Ϊ1
	* 1. ����
	*	 dfs���Σ�grid�͵�ǰ����������x,y
	*	 public������result��Ϊ�µ����������visted�������Ƿ�������routes��ά�����¼��->��->��->��·����x��y������
	*	 routes��4*2��routes[][0]����x�ı仯��routes[][1]����y�ı仯��routes[i][]�ֱ��Ӧ��->��->��->����x��y������
	* 2. �˳����������ﲻ���˳���������Ϊ�ڵ���չ���л��жϱ߽磬Ծ���߽�Ķ��ᱻ����
	* 3. ����չ��
	*	 ÿ����ĵ�������������->��->��->���ĸ����򣬳����ж�x��y�Ƿ񳬹��߽��⣬��Ҫ�ж�visted[x][y]���Ѿ����������ľͲ��������ˣ�ͬʱֻ��'1'��½�أ����ֻ��'1'��
	*/
	rows = grid.size(); cols = grid[0].size();
	visted = vector<vector<bool>>(rows, vector<bool>(cols, false));
	result = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!visted[i][j] && grid[i][j] == '1') {
				//�����µ���
				result++;
				dfsIsland(grid, i, j);
			}
		}
	}
	return result;
}
void NumberofIslands::dfsIsland(vector<vector<char>>& grid, int x, int y) {
	for (int i = 0; i < 4; i++) {
		//�ĸ���������
		int nextX = x + routes[i][0];
		int nextY = y + routes[i][1];
		if (nextX<0 || nextX>rows - 1 || nextY<0 || nextY>cols - 1 || visted[nextX][nextY]) continue;//�߽����������˳�����
		if (grid[nextX][nextY] == '1') {
			//�õ���δ��visted��½��
			visted[nextX][nextY] = true;
			dfsIsland(grid, nextX, nextY);
		}
	}
}
void NumberofIslands::test_NumberofIslands() {
	NumberofIslands NI;
	vector<vector<char>> nums1{ {'1','1','1','1','0'} ,
								{'1','1','0','1','0'},
								{'1','1','0','0','0'},
								{'0','0','0','0','0'} };
	vector<vector<char>> nums2{ {'1','1','0','0','0'} ,
								{'1','1','0','0','0'},
								{'0','0','1','0','0'},
								{'0','0','0','1','1'} };
	cout << NI.numIslands(nums1) << endl;
	cout << NI.numIslands(nums2) << endl;
}
