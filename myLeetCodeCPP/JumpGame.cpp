#include "JumpGame.h"

bool JumpGame::canJump(vector<int>& nums) {
	/*第55题：跳跃游戏
	* 贪心算法
	* 每一个点的可走步数为0~nums[i]，但是每个点该走多少步其实没啥关系，最大关系的是每个点可以覆盖的最远的范围是到哪（覆盖的最大范围是i+nums[i]）
	* 那么知道i点最远的覆盖范围是i+nums[i]，该点实际上能覆盖到i+nums[i]位置的前提条件还是前面的点可以走到i处（也就是前面的点能覆盖到i）
	* 1. 因此从i=0开始往右走，用cover记录当前最远可以完整走到的距离（点cover处是当前最远可走到的位置）
	*	 1.1. 当遍历到i>cover时，说明前面的格子已经走不到i点了，因此后面走不通了，也就是到不了end了，直接返回false
	*	 1.2. 当遍历到i<=cover时，说明i点还可以继续往前走，那么此时就要更新最新可以到达的点了，也就是cover=max(i+nums[i], cover)
	*		  这里说明一下cover=max(i+nums[i], cover)，因为当前i位置最远可走的距离可能也在前面cover的范围内
	*	 1.3. 最后当cover>=end时就表示cover已经能到end点了，因此可以直接返回true
	*/

	int cover = 0;
	int end = nums.size() - 1;
	for (int i = 0; i <= cover; i++) {
		//1.2 i<=cover时，说明i点还可以继续往前走
		cover = max(i + nums[i], cover);
		//1.3.最后当cover >= end时就表示cover已经能到end点了，因此可以直接返回true
		if (cover >= end) return true;
	}
	return false;
}
void JumpGame::test_JumpGame() {
	JumpGame JG;
	vector<vector<int>> nums{ {2,3,1,1,4}, {3,2,1,0,4}, {0} };
	for (int i = 0; i < nums.size(); i++) {
		cout << JG.canJump(nums[i]) << endl;
	}
}
