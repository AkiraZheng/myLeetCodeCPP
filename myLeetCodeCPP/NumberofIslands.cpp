#include "NumberofIslands.h"

int NumberofIslands::numIslands(vector<vector<char>>& grid) {
	/*第200题：岛屿数量
	* 深搜（递归）dfs
	* a. 用一个visted存储某点[i,j]是否已经被搜索到；
	* b. 主函数中遍历每个点，如果遇到还未搜索到的点，则说明是新岛屿，result++；
	* c. dfs递归函数中按照上->下->左->右的顺序递归，搜索主函数中传入的新岛屿所覆盖的点，并将对应的visited置为1
	* 1. 参数
	*	 dfs传参：grid和当前搜索的坐标x,y
	*	 public参数：result作为新岛屿计数器、visted数组标记是否被搜索、routes二维数组记录上->下->左->右路线下x和y的增减
	*	 routes：4*2，routes[][0]是行x的变化，routes[][1]是列y的变化；routes[i][]分别对应上->下->左->右中x和y的增减
	* 2. 退出条件：这里不用退出条件，因为在单层展开中会判断边界，跃出边界的都会被跳过
	* 3. 单层展开
	*	 每个点的单层搜索都有上->下->左->右四个方向，除了判断x和y是否超过边界外，还要判断visted[x][y]，已经被搜索过的就不再搜索了（同时只有'1'是陆地，因此只搜'1'）
	*/
	rows = grid.size(); cols = grid[0].size();
	visted = vector<vector<bool>>(rows, vector<bool>(cols, false));
	result = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (!visted[i][j] && grid[i][j] == '1') {
				//发现新岛屿
				result++;
				dfsIsland(grid, i, j);
			}
		}
	}
	return result;
}
void NumberofIslands::dfsIsland(vector<vector<char>>& grid, int x, int y) {
	for (int i = 0; i < 4; i++) {
		//四个方向搜索
		int nextX = x + routes[i][0];
		int nextY = y + routes[i][1];
		if (nextX<0 || nextX>rows - 1 || nextY<0 || nextY>cols - 1 || visted[nextX][nextY]) continue;//边界条件就是退出条件
		if (grid[nextX][nextY] == '1') {
			//该点是未被visted的陆地
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
