#include "BinaryTreeLevelOrderTraversal.h"

vector<vector<int>> BinaryTreeLevelOrderTraversal::levelOrder(TreeNode* root) {
	/*��102�⣺�������Ĳ������
	* 1. �ݹ鷽��
	*	 ������ǿ����õݹ鷽���ģ�����һ����ά����result��result.size()�����������ͬ
	*	 ���԰������ַ����е�һ�ֽ��еݹ飨ֻҪ��֤������Ҿ��У���ÿ�ݹ鵽��ʱ�Ͱ������push��result[layer]�У�����ÿһ�㶼��������Ĳ�ͬlayer���У���
	*	 ����ڵݹ������Ƿ������Ƚ�������ȫ�����������ٽ��Ұ�����������ģ������Ⲣû�й�ϵ����Ϊ��Ȼ��֤��������ÿ��layer���У����Ǵ���������ģ�����������һ��û��ϵ
	* 2. ��������
	*	 ��һ����������depth���ʱÿһ�������node��Ȼ������һ��ѭ���У�һ����pop����ͬʱ������һ��������Ҷ�Ӧ��node
	*	 ���ڶ������Ƚ��ȳ����ص㣬���pop��ǰ���һ��nodeͬʱpush����һ���node����Ӱ�쵱ǰ���pop˳��ģ���Ϊ��ǰ��������һ��ѭ���ͽ����еģ���������
	*/

	vector<vector<int>> result;
	queue<TreeNode*> que;//���д洢ÿ��������ҵ�node
	if (root == nullptr) return result;

	//�����һ��
	que.push(root);//�Ƚ���һ��Ž����У���Ϊѭ��i����ɵ�������pop��һ���ֵ����result�� �� push����һ���ֵ

	while (!que.empty()) {//���һ��pop�����ݺ󲻻�������һ������ݱ�push�����ˣ�������һ�������que�ǿն���
		int layerSize = que.size();
		vector<int> layerResult;
		for (int i = 0; i < layerSize; i++) {
			//1. ȡ����һ��ĵ�i���ڵ㲢������
			TreeNode* nodeTemp = que.front();
			layerResult.push_back(nodeTemp->val);
			que.pop();

			//2. ���ýڵ���һ���ֵ�����������������
			if (nodeTemp->left != nullptr) que.push(nodeTemp->left);//�ýڵ���һ�����߽ڵ������
			if (nodeTemp->right != nullptr) que.push(nodeTemp->right);//�ýڵ���һ����ұ߽ڵ������
		}
		result.push_back(layerResult);
	}
	return result;
}
