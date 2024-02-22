#include "JumpGame.h"

bool JumpGame::canJump(vector<int>& nums) {
	/*��55�⣺��Ծ��Ϸ
	* ̰���㷨
	* ÿһ����Ŀ��߲���Ϊ0~nums[i]������ÿ������߶��ٲ���ʵûɶ��ϵ������ϵ����ÿ������Ը��ǵ���Զ�ķ�Χ�ǵ��ģ����ǵ����Χ��i+nums[i]��
	* ��ô֪��i����Զ�ĸ��Ƿ�Χ��i+nums[i]���õ�ʵ�����ܸ��ǵ�i+nums[i]λ�õ�ǰ����������ǰ��ĵ�����ߵ�i����Ҳ����ǰ��ĵ��ܸ��ǵ�i��
	* 1. ��˴�i=0��ʼ�����ߣ���cover��¼��ǰ��Զ���������ߵ��ľ��루��cover���ǵ�ǰ��Զ���ߵ���λ�ã�
	*	 1.1. ��������i>coverʱ��˵��ǰ��ĸ����Ѿ��߲���i���ˣ���˺����߲�ͨ�ˣ�Ҳ���ǵ�����end�ˣ�ֱ�ӷ���false
	*	 1.2. ��������i<=coverʱ��˵��i�㻹���Լ�����ǰ�ߣ���ô��ʱ��Ҫ�������¿��Ե���ĵ��ˣ�Ҳ����cover=max(i+nums[i], cover)
	*		  ����˵��һ��cover=max(i+nums[i], cover)����Ϊ��ǰiλ����Զ���ߵľ������Ҳ��ǰ��cover�ķ�Χ��
	*	 1.3. ���cover>=endʱ�ͱ�ʾcover�Ѿ��ܵ�end���ˣ���˿���ֱ�ӷ���true
	*/

	int cover = 0;
	int end = nums.size() - 1;
	for (int i = 0; i <= cover; i++) {
		//1.2 i<=coverʱ��˵��i�㻹���Լ�����ǰ��
		cover = max(i + nums[i], cover);
		//1.3.���cover >= endʱ�ͱ�ʾcover�Ѿ��ܵ�end���ˣ���˿���ֱ�ӷ���true
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
