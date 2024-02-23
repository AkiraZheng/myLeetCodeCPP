#include "WordSearch.h"

bool WordSearch::exist(vector<vector<char>>& board, string word) {
	/*��79�⣺��������
	* ���û��ݷ���һ��������������ά�ַ����飬ÿһ���п�����Ϊ���������wordƥ��ĵ�����
	* ��ÿһ����������㣬����m*n��������ÿ������ÿһ��ķ�֧����4�ֿ��ܣ���Ϊÿһ�����һ������ǵ�ǰ�����е����ڸ�Ҳ��������-��-��-�����ֿ���
	* ���Ƿ������������������������һ�������㷨�Ļ��ǲ�̫����ģ���Ϊ���ĵ�һ����m*n�ֿ��ܣ���ʣ�����в�ķ�֧����ͳһ��4�ֿ���
	* ��˰�4�ֿ��ܵ����������������Ϊ�����㷨�ȽϿ��ף���m*n������ѭ�����������������У�Ҳ���ǻ����㷨ֻ������[i,j]Ϊ�����ǿ������Ƿ����wordƥ���ֵ�Ľ����
	* �������еĻ����㷨����������������������չ��
	* 1. ����
	*	 1.1 ����:board��word��gridRow��gridCol
	*		 ���ݵ���չ����֪����Ҫ��ǰ׼���ߵĸ��ӵ�index����˴���gridRow��gridCol
	*	 1.2 public������wordNode�ַ�����existed��ά����
	*		 ����2.�˳�������֪����Ҫһ��wordNode�ַ������洢��ǰ֦�����Ѿ��߹���ƥ����ַ����ݣ�������Ŀ��word���Ƚ�
	*		 ����2.�˳�������֪����Ҫһ����СΪm*n��existed��ά�������洢�����Ƿ��Ѿ����߹���״̬��
	* 2. �˳�������
	*	 2.1 ����ǰ��֦�ϵ������Ѿ��ﵽĿ���ˣ�Ҳ����wordNode��wordƥ���ˣ�wordNode == word�������Է���true
	*	 2.2 ����ǰ������word�ж�Ӧλ�õĸ��Ӳ�ƥ��ʱ�����Խ����÷�֧�ˣ�û��Ҫ���������ߣ�return false������ע�⣬����������ڵ���չ����if()�����return�ģ���ôʵ����ֻ��
	*		 ˵����·��ͨ���ѣ�������ֻ�ǽ�����ǰ�㲢����һ��boolֵ��if���жϣ���������ؽ����ݹ飬��������Ҫ2.3������ʵ�ֵݹ�����Ĳ���
	*		 ����˵�����������������������״ν������Ǹ����word[0]ƥ��ʱ����������չ��ȡ�����ĸ�����Ľ����������ĸ���������������Ҳ�����ĸ����������if(backtrack)
	*				   ��������true����ôһ��һ����˵���һ��ʱ����һ�����������ִ��existed[gridRow][gridCol]�Ļ��ݺ��Ѿ�û�д���������ˣ�Ҳ����û�з���ֵ�ˣ�ϵͳ���ܻ��Զ�����һ������ֵ����VS����ʱ����ϵͳ���Զ���������һ��true���˳��ݹ飩
	*	 2.3 ���ĵ�һ�������������з����û�ҵ�ƥ��ģ�����ݵ���һ���return false
	* 3. ����չ���������ڻ����߲�ͨ�������÷���
	*	 ���[gridRow,gridCol]�����µĵ�����չ����������ʱ��ÿһ���ж�Ӧ���Ǹ����ӿ���ѡ����4�������ߣ�Ҳ������4��չ���Ŀ��ܣ��Զ���˳��Ϊ��-��-��-��
	*	 ������Ҫ�ж϶�Ӧ�ĸ����Ƿ����ߵ�ͨ��ǰ��
	*	 2.1. ������λ������Ȧʱ��Ҫ�ж���ѡ����Ǹ������Ƿ��������ˣ��߲�ͨ
	*		  �統gridλ��{0��2}ʱ��ѡ�������ߣ���ֱ���򣩣���gridRow-1 < 0�������ˣ���·��ͨ�������������
	*	 2.2. �����Ӳ�������Ȧʱ����Ȼ��������˵4�����򶼿����ߣ�������Ŀ��˵����ÿ������ֻ����һ�Σ�Ҳ������ͬһ֦���ϣ�һ������ֻ�ܱ��߹�һ�Σ���˻�Ҫ�ж����ߵķ����ϵĵ��Ƿ��ѱ��߹�
	*		  ��existed[0,2]=true��ʾ�ø���������ķ�֧���Ѿ����߹��ˣ���gridλ��{0��2}ѡ�������ߣ���ֱ����ʱ��existed[gridRow-1, 2]==true�����ӱ���Ⱦ���ˣ������ߣ���������߷�
	*/
	existed.clear();
	wordNode.clear();
	maxRow = board.size(); maxCol = board[0].size();
	for (int i = 0; i < maxRow; i++) existed.push_back(vector<bool>(maxCol, false));
	
	for (int i = 0; i < maxRow; i++) {
		for (int j = 0; j < maxCol; j++) {
			wordNode.clear();//�ݹ麯�����״�ʱ����һ����ĸ�Ž�ȥʱû�л��ݣ��ҵ���Ӧ���ַ���return true��Ҳû���ݣ������Ҫ����������clear wordNode
			if (backtrack(board, word, i, j)) return true;
			//cout << endl;
		}
	}
	return false;//���и���ȫ�������û�ҵ�ƥ���
}

bool WordSearch::backtrack(vector<vector<char>>& board, string word, int gridRow, int gridCol) {

	//�״�ʱ����һ����ĸ�Ž�ȥ������û�л��ݣ������Ҫ����������clear wordNode
	if (wordNode.size() == 0) {
		wordNode.push_back(board[gridRow][gridCol]);
	}

	//�˳�����
	//2.1 ����ǰ��֦�ϵ������Ѿ��ﵽĿ���ˣ�Ҳ����wordNode��wordƥ���ˣ�wordNode == word�������Է���true
	//cout << wordNode << "��";
	if (wordNode == word) return true;
	
	//2.2 ����ǰ������word�ж�Ӧλ�õĸ��Ӳ�ƥ��ʱ�����Խ����÷�֧�ˣ�û��Ҫ���������ߣ�return false
	//ע�⣺������˵�һ��Ͳ�ƥ�����������˳��ݹ��⣬�����㶼ֻ�Ƿ��ؽ������һ�����
	if (board[gridRow][gridCol] != word[wordNode.size()-1]) return false;

	//3. ����չ������ǰ����ƥ���ˣ����Թ̶�������׼��ѡ����������
	existed[gridRow][gridCol] = true;
	//a. ������
	if (gridRow-1 >= 0 && !existed[gridRow - 1][gridCol]) {
		//�ݹ������֧
		gridRow--;
		wordNode.push_back(board[gridRow][gridCol]);//���ߺ��Ǹ����ӵ��ַ��Ž���ǰ֦�Ĵ���
		if(backtrack(board, word, gridRow, gridCol)) return true;//�ݹ��ҵ��˾�һ����˳�������ͼ�����������
		gridRow++;//����
		wordNode.pop_back();//����
	}
	//b. ������
	if (gridRow + 1 <= maxRow-1 && !existed[gridRow + 1][gridCol]) {
		//�ݹ������֧
		gridRow++;
		wordNode.push_back(board[gridRow][gridCol]);//���ߺ��Ǹ����ӵ��ַ��Ž���ǰ֦�Ĵ���
		if (backtrack(board, word, gridRow, gridCol)) return true;//�ݹ��ҵ��˾�һ����˳�������ͼ�����������
		gridRow--;//����
		wordNode.pop_back();//����
	}
	//c. ������
	if (gridCol - 1 >= 0 && !existed[gridRow][gridCol-1]) {
		//�ݹ������֧
		gridCol--;
		wordNode.push_back(board[gridRow][gridCol]);//���ߺ��Ǹ����ӵ��ַ��Ž���ǰ֦�Ĵ���
		if (backtrack(board, word, gridRow, gridCol)) return true;//�ݹ��ҵ��˾�һ����˳�������ͼ�����������
		gridCol++;//����
		wordNode.pop_back();//����
	}
	//d. ������
	if (gridCol + 1 <= maxCol-1 && !existed[gridRow][gridCol + 1]) {
		//�ݹ������֧
		gridCol++;
		wordNode.push_back(board[gridRow][gridCol]);//���ߺ��Ǹ����ӵ��ַ��Ž���ǰ֦�Ĵ���
		if (backtrack(board, word, gridRow, gridCol)) return true;//�ݹ��ҵ��˾�һ����˳�������ͼ�����������
		gridCol--;//����
		wordNode.pop_back();//����
	}
	existed[gridRow][gridCol] = false;//����
	//cout << "[" << wordNode << "]";
	
	//2.3 ���ĵ�һ�������������з����û�ҵ�ƥ��ģ�����ݵ���һ���return false
	// ������ﲻд�Ļ��������ĵ�һ���������ĸ�������Ҳ���ƥ��ģ����ݵ������û�д�������ߣ���ôϵͳ��ǿ���˳��ݹ飬���Զ�������һ��true����������
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
