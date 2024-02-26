#include "BinaryTreeMaximumPathSum.h"

int BinaryTreeMaximumPathSum::maxPathSum(TreeNode* root) {
    /*第124题：二叉树中的最大路径和
    * 递归的动态规划方法
    * 1. 理解题目：
    *	 除了根节点外，剩余的子节点从下往上，每个子节点只能选择左或右的一条路线，除非该子节点独立起来作为新的根节点
    *	 只要保证每个子节点都只有左或右一个路线，那么就能获得一条道走到底的路线（左右只选一条线，就相当于抛弃了另外一条线）
    * 2. 采用后续遍历的方法
    *	 从下往上遍历经过每个子节点的左右最大路线和，并用一个公有result不断更新最大路径和
    *	 经过该子节点的路线有两种可能：a.独立出来作为根节点，那么此时应该加上左和右两条线；b.作为普通节点返回给上一个节点，那么此时要选出max(左线，右线)
    */
    if (root == nullptr)return 0;
    maxResult = INT_MIN;
    dfs(root);
    return maxResult;
}

int BinaryTreeMaximumPathSum::dfs(TreeNode* root) {
    if (root == nullptr) return 0;

    //后序遍历：左右中如果某一边的最大路径和是负数，那么这一边是可以直接舍弃掉的(所以也存在直接把左右两个枝干全部砍掉的情况)
    int leftMax = max(0, dfs(root->left));//左
    int rightMax = max(0, dfs(root->right));//右

    //1. 以当前中心节点root独立出来作为新的根节点来更新最长路径
    maxResult = max(maxResult, leftMax + rightMax + root->val);
    //2. 当前作为普通子节点，选择最大路径和的一边作为结果返回给上面的节点（回溯是从下往上回溯的）
    return max(leftMax, rightMax) + root->val;
}
