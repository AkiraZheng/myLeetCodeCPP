#include "BinaryTreeMaximumPathSum.h"

int BinaryTreeMaximumPathSum::maxPathSum(TreeNode* root) {
    /*��124�⣺�������е����·����
    * �ݹ�Ķ�̬�滮����
    * 1. �����Ŀ��
    *	 ���˸��ڵ��⣬ʣ����ӽڵ�������ϣ�ÿ���ӽڵ�ֻ��ѡ������ҵ�һ��·�ߣ����Ǹ��ӽڵ����������Ϊ�µĸ��ڵ�
    *	 ֻҪ��֤ÿ���ӽڵ㶼ֻ�������һ��·�ߣ���ô���ܻ��һ�����ߵ��׵�·�ߣ�����ֻѡһ���ߣ����൱������������һ���ߣ�
    * 2. ���ú��������ķ���
    *	 �������ϱ�������ÿ���ӽڵ���������·�ߺͣ�����һ������result���ϸ������·����
    *	 �������ӽڵ��·�������ֿ��ܣ�a.����������Ϊ���ڵ㣬��ô��ʱӦ�ü�������������ߣ�b.��Ϊ��ͨ�ڵ㷵�ظ���һ���ڵ㣬��ô��ʱҪѡ��max(���ߣ�����)
    */
    if (root == nullptr)return 0;
    maxResult = INT_MIN;
    dfs(root);
    return maxResult;
}

int BinaryTreeMaximumPathSum::dfs(TreeNode* root) {
    if (root == nullptr) return 0;

    //������������������ĳһ�ߵ����·�����Ǹ�������ô��һ���ǿ���ֱ����������(����Ҳ����ֱ�Ӱ���������֦��ȫ�����������)
    int leftMax = max(0, dfs(root->left));//��
    int rightMax = max(0, dfs(root->right));//��

    //1. �Ե�ǰ���Ľڵ�root����������Ϊ�µĸ��ڵ��������·��
    maxResult = max(maxResult, leftMax + rightMax + root->val);
    //2. ��ǰ��Ϊ��ͨ�ӽڵ㣬ѡ�����·���͵�һ����Ϊ������ظ�����Ľڵ㣨�����Ǵ������ϻ��ݵģ�
    return max(leftMax, rightMax) + root->val;
}
