#include "SortColors.h"

void SortColors::sortColors(vector<int>& nums) {
	/*��75�⣺��ɫ����
	* �죺0 �ף�1 ����2
	* ʹ��˫ָ�뷽������red���洢��0���������꣬��blue���洢��2�����������ŵ��������꣬i��ʾ��ǰ��Ҫ��������������
	* ��ǰ�洢�����궼�ǻ�δ�����Ӧ��ɫ�ģ��ȴ��������
	* 1. ��nums[i]==0
	*	 ��ʾ��Ҫ���º�0��swap(nums[i], nums[red])����ôred��ָ��Ҫָ����һ��λ���ˣ�ִ��red++
	*	 ���ﲻ��Ҫi--����Ϊred<=i�ǳ����ģ���i��ǰ�����ֶ���������ˣ���˽�����redλ�õ�i������Ҫ��������
	* 2. ��nums[i]==1
	*	 ��ʾ��Ҫ���°�1�����ڴ�ʱiǰ������ֶ��Ǳ���������ˣ���˵�������1ʱֱ��ԭ�ز�������
	* 3. ��nums[i]==2��
	*	 ��ʾ��Ҫ������2��swap(nums[i], nums[blue])����ôblue��ָ��Ҫָ����һ����ߵ�λ���ˣ�ָ��blue--
	*	 ��ô�������ʱ��nums[i]����δ������ˣ���˻���Ҫָ��i--������һ��ѭ���м����жϵ�ǰ�ִ��е�i
	*/
	int red = 0; int blue = nums.size() - 1;
	for (int i = 0; i <= blue; i++) {//������Ҫ������left����Ϊ�����left�п����ǻ�û������ģ�Ҳ�������������и���û����ɫ
		//��nums[i]==1����ԭ�ز������Ͳ�д��
		if (nums[i] == 0) {
			//�ź�ɫ
			swap(nums[i], nums[red++]);
		}
		else if (nums[i] == 2) {
			swap(nums[i--], nums[blue--]);
		}
	}
}
void SortColors::test_SortColors() {
	SortColors SC;
	vector< vector<int>> nums{ {2,0,2,1,1,0}, {2,0,1} };
	vector< vector<int>> result;
	for (auto &num : nums) {
		SC.sortColors(num);
		result.push_back(num);
	}
	SC.printVector(result);
}

void SortColors::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << endl;
	}
}
