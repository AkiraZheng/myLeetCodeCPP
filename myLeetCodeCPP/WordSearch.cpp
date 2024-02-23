#include "WordSearch.h"

bool WordSearch::exist(vector<vector<char>>& board, string word) {
	/*第79题：单词搜索
	* 采用回溯法，一个个遍历整个二维字符数组，每一格都有可能作为起点生成与word匹配的单词组
	* 把每一格当作树中最顶点，则共有m*n棵树，而每棵树中每一层的分支都有4种可能，因为每一层的下一层必须是当前格子中的相邻格，也就是有上-下-左-右四种可能
	* 我们发现如果把所有树合起来当作一个回溯算法的话是不太合理的，因为树的第一层有m*n种可能，而剩下所有层的分支都是统一的4种可能
	* 因此把4种可能的搜索单独拎出来作为回溯算法比较靠谱，而m*n棵树的循环搜索放在主函数中（也就是回溯算法只返回以[i,j]为起点的那棵树中是否存在word匹配的值的结果）
	* 单棵树中的回溯算法：参数、返回条件、单层展开
	* 1. 参数
	*	 1.1 传参:board和word、gridRow和gridCol
	*		 根据单层展开还知道需要当前准备走的格子的index，因此传入gridRow和gridCol
	*	 1.2 public参数：wordNode字符串、existed二维数组
	*		 根据2.退出条件可知还需要一个wordNode字符串来存储当前枝干上已经走过的匹配的字符内容，用于与目标word做比较
	*		 根据2.退出条件可知还需要一个大小为m*n的existed二维数组来存储格子是否已经被走过（状态）
	* 2. 退出条件：
	*	 2.1 当当前树枝上的数组已经达到目标了，也就是wordNode与word匹配了（wordNode == word），可以返回true
	*	 2.2 当当前格子与word中对应位置的格子不匹配时，可以结束该分支了，没必要继续往下走，return false，但是注意，这里如果是在单层展开的if()语句中return的，那么实际上只是
	*		 说明此路不通而已，他这里只是结束当前层并返回一个bool值给if做判断，不是正真地结束递归，因此最后还需要2.3来真正实现递归结束的操作
	*		 举例说明：当本次树在主函数中首次进来的那个点跟word[0]匹配时，他会向下展开取搜索四个方向的结果，如果往四个方向都搜索不到，也就是四个方向里面的if(backtrack)
	*				   都不返回true，那么一层一层回退到第一层时，第一层继续往下走执行existed[gridRow][gridCol]的回溯后，已经没有代码可运行了，也就是没有返回值了（系统可能会自动分配一个返回值，在VS测试时发现系统会自动给它返回一个true来退出递归）
	*	 2.3 树的第一层在搜索完所有方向后还没找到匹配的，则回溯到第一层后return false
	* 3. 单层展开：当碰壁或者走不通就跳过该方向
	*	 针对[gridRow,gridCol]坐标下的点往下展开进行搜索时，每一层中对应的那个格子可以选择往4个方向走，也就是有4个展开的可能，自定义顺序为上-下-左-右
	*	 但是需要判断对应的格子是否能走得通当前：
	*	 2.1. 当格子位于最外圈时，要判断所选择的那个方向是否屏碰壁了，走不通
	*		  如当grid位于{0，2}时，选择向上走（垂直方向），当gridRow-1 < 0，碰壁了，此路不通，跳过这个方向
	*	 2.2. 当格子不在最外圈时，虽然理论上俩说4个方向都可以走，但是题目中说明了每个格子只能用一次，也就是在同一枝干上，一个格子只能被走过一次，因此还要判断所走的方向上的点是否已被走过
	*		  如existed[0,2]=true表示该格子在上面的分支中已经被走过了，当grid位于{0，2}选择向上走（垂直方向）时，existed[gridRow-1, 2]==true，格子被污染过了，不能走，跳过这个走法
	*/
	existed.clear();
	wordNode.clear();
	maxRow = board.size(); maxCol = board[0].size();
	for (int i = 0; i < maxRow; i++) existed.push_back(vector<bool>(maxCol, false));
	
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			wordNode.clear();//递归函数中首次时将第一个字母放进去时没有回溯，找到对应的字符串return true后也没回溯，因此需要在主函数中clear wordNode
			if (backtrack(board, word, i, j)) return true;
			//cout << endl;
		}
	}
	return false;//所有格子全部搜完后没找到匹配的
}

bool WordSearch::backtrack(vector<vector<char>>& board, string word, int gridRow, int gridCol) {

	//首次时将第一个字母放进去，这里没有回溯，因此需要在主函数中clear wordNode
	if (wordNode.size() == 0) {
		wordNode.push_back(board[gridRow][gridCol]);
	}

	//退出条件
	//2.1 当当前树枝上的数组已经达到目标了，也就是wordNode与word匹配了（wordNode == word），可以返回true
	//cout << wordNode << "，";
	if (wordNode == word) return true;
	
	//2.2 当当前格子与word中对应位置的格子不匹配时，可以结束该分支了，没必要继续往下走，return false
	//注意：这里除了第一层就不匹配是真正的退出递归外，其他层都只是返回结果到上一层而已
	if (board[gridRow][gridCol] != word[wordNode.size()-1]) return false;

	//3. 单层展开：当前格子匹配了，可以固定下来后准备选择往哪走了
	existed[gridRow][gridCol] = true;
	//a. 向上走
	if (gridRow-1 >= 0 && !existed[gridRow - 1][gridCol]) {
		//递归这个分支
		gridRow--;
		wordNode.push_back(board[gridRow][gridCol]);//将走后那个格子的字符放进当前枝的串中
		if(backtrack(board, word, gridRow, gridCol)) return true;//递归找到了就一层层退出，否则就继续往下搜索
		gridRow++;//回溯
		wordNode.pop_back();//回溯
	}
	//b. 向下走
	if (gridRow + 1 <= maxRow-1 && !existed[gridRow + 1][gridCol]) {
		//递归这个分支
		gridRow++;
		wordNode.push_back(board[gridRow][gridCol]);//将走后那个格子的字符放进当前枝的串中
		if (backtrack(board, word, gridRow, gridCol)) return true;//递归找到了就一层层退出，否则就继续往下搜索
		gridRow--;//回溯
		wordNode.pop_back();//回溯
	}
	//c. 向左走
	if (gridCol - 1 >= 0 && !existed[gridRow][gridCol-1]) {
		//递归这个分支
		gridCol--;
		wordNode.push_back(board[gridRow][gridCol]);//将走后那个格子的字符放进当前枝的串中
		if (backtrack(board, word, gridRow, gridCol)) return true;//递归找到了就一层层退出，否则就继续往下搜索
		gridCol++;//回溯
		wordNode.pop_back();//回溯
	}
	//d. 向右走
	if (gridCol + 1 <= maxCol-1 && !existed[gridRow][gridCol + 1]) {
		//递归这个分支
		gridCol++;
		wordNode.push_back(board[gridRow][gridCol]);//将走后那个格子的字符放进当前枝的串中
		if (backtrack(board, word, gridRow, gridCol)) return true;//递归找到了就一层层退出，否则就继续往下搜索
		gridCol--;//回溯
		wordNode.pop_back();//回溯
	}
	existed[gridRow][gridCol] = false;//回溯
	//cout << "[" << wordNode << "]";
	
	//2.3 树的第一层在搜索完所有方向后还没找到匹配的，则回溯到第一层后return false
	// 如果这里不写的话，当树的第一层搜索完四个方向后都找不到匹配的，回溯到这里后将没有代码可以走，那么系统会强行退出递归，并自动给返回一个true到主函数中
	return false;
}

void WordSearch::test_WordSearch() {
	WordSearch WS;
	vector<vector<char>> board1{ {'A','B','C','E'} ,{'S','F','C','S'},{'A','D','E','E'} };
	string word1 = "ABCCED";
	vector<vector<char>> board2{ {'A','B','C','E'} ,{'S','F','C','S'},{'A','D','E','E'} };
	string word2 = "SEE";
	vector<vector<char>> board3{ {'A','B','C','E'} ,{'S','F','C','S'},{'A','D','E','E'} };
	string word3 = "ABCB";
	cout << WS.exist(board1, word1) << endl;
	cout << WS.exist(board2, word2) << endl;
	cout << WS.exist(board3, word3) << endl;
}
