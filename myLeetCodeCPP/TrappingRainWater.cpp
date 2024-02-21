#include "TrappingRainWater.h"

//1.�����Ż���˫ָ�뷽��
int TrappingRainWater::trap_doublePtr(vector<int>& height) {
	/*��42�⣺����ˮ
	* ������Ҫȷ�ϵĲ��ð���ɨ�軹�ǰ���ɨ��
	* ����ʹ��˫ָ�뷽�������ð���ɨ�裬����ÿһ�еļ��㣬�ֱ�ѭ��ȡ����ߵ���ߵ���ұߵ���ߵ�λ��
	* ���еĻ����еĿ���ǹ̶��ģ�Ϊ1����ô����i�Ŀɽ���ˮ������� 1 * (min(h[left],h[right])-height[i])
	* �������ֱ����ⷨ�ᳬʱ��ÿһ�ж�Ҫ�ظ�ɨ��һ���������飬����ʵ�ܶ�������ֵ�ǹ��õģ�����һ���󰼲��ڵ�index���ԣ��⼸�������������ֵ��һ����
	* ��˿����Ż�˫ָ���㷨��������vector�ֱ�洢��ǰλ�ü������ң���Χ�ڵ����ֵ����ôֻ��Ҫ����һ�δ��������о���
	*/

	int h_size = height.size();
	//0. ����û����߽��ˣ�����û���ұ߽��ˣ��������������޷�����ˮ��������Ȼ�����С������2Ҳ�޷���
	if (h_size <= 2) return 0;

	vector<int> maxLeft(h_size, 0);
	vector<int> maxRight(h_size, 0);
	//1. �����洢��i����ߵ����ֵ��maxLeft[i]�У��������ұ���
	maxLeft[0] = height[0]; 
	for (int i = 1; i < h_size; i++) {
		maxLeft[i] = (height[i] > maxLeft[i - 1]) ? height[i] : maxLeft[i - 1];
	}
	maxRight[h_size - 1] = height[h_size - 1];
	//2. �����洢��i���ұߵ����ֵ��maxRight[i]�У������������
	for (int i = h_size - 1 - 1; i >= 0; i--) {
		maxRight[i] = (height[i] > maxRight[i + 1]) ? height[i] : maxRight[i + 1];
	}

	int sum = 0;
	//3. ���м������ˮ�����˫ָ�뷽������������Ҳ�����ˮ
	for (int i = 1; i < h_size - 1; i++) {
		int min_h = min(maxLeft[i], maxRight[i]);
		sum += (min_h > height[i]) ? (min_h- height[i]) : 0;//���ְ���
	}
	return sum;
}
void TrappingRainWater::test_TrappingRainWater_doublePtr() {
	TrappingRainWater TRW;
	vector<vector<int>> nums;
	nums.push_back({ 0,1,0,2,1,0,1,3,2,1,2,1 });
	nums.push_back({ 4,2,0,3,2,5 });
	for (int i=0; i < nums.size(); i++) {
		cout << TRW.trap_doublePtr(nums[i]) << endl;
	}
}
//2.���õ���ջ����
int TrappingRainWater::trap(vector<int>& height) {
	/*��42�⣺����ˮ
	* ���õ���ջ�ķ�����ʹ�����������еķ����������ˮ��ջ�洢�����index
	* ����˼·��������i��ֵ����ջ����Ӧ��ֵʱ��˵�����ְ����ˣ�Ҫ����popջ�е�ֵ���������ǰһ��λ�õľ��루�п�ȣ������������ͬʱ����pop��Ҳ�ܸ������µ���ߵ�λ��
	* 0. ����û����߽��ˣ�����û���ұ߽��ˣ��������������޷�����ˮ��������Ȼ�����С������2Ҳ�޷���
	* 1. ��ѭ��ĳ����ʱ���õ㴦��ֵ��ջ����ֵ���������ֹ�ϵ��(ע��ѭ������Ȼ��һ��������һ�����ǲ���ˮ�ģ������п��������ֵ���ұ�ֵ)
	*	 1.1 height[i] < height[stack.top]��˵���ǰ��ۿ����γɵ�λ�ã��� i pusuh��ջ
	*	 1.2 height[i] == height[stack.top]����������һ���ߵ�����ֻȡ���ҵ�����i����stack popջ��->��i push��ջ
	*	 1.3 height[i] > height[stack.top]��˵�������ұ߽�������ˣ�������Ҫ��ʼִ��������㣬�������µ�ջ�ұ߽�
	*		 1.3.1 ����while����ջ���ҵ������Ӷ�Ӧ����߽磨Ҳ�����ҵ��еĿ�ȣ�
	*			   ���ȴ�ʱ��height[i]��Ϊ�ұ߽磬���������Χ�İ��۵�Ϊstack.top�����bottom=stack.top
	*			   ��һ����stack.top pop��ջ�����������ѯ�ð�����i���Ӧ����߽磨���۵ײ���������߽磩
	*		 1.3.4 whileѭ�������������i����Ϊ�µ���߽�pop��ջ
	*/

	//0. ����û����߽��ˣ�����û���ұ߽��ˣ��������������޷�����ˮ��������Ȼ�����С������2Ҳ�޷���
	int h_size = height.size();
	if (h_size <= 2) return 0;
	stack<int> leftStack;
	int sum = 0;
	//1. ѭ������
	leftStack.push(0);
	for (int i = 1; i < h_size; i++) {
		if (height[i] < height[leftStack.top()]) {
			//1.1 ˵���ǰ��ۿ����γɵ�λ�ã��� i pusuh��ջ
			leftStack.push(i);
		}
		else if (height[i] == height[leftStack.top()]) {
			//1.2 ��������һ���ߵ�����ֻȡ���ҵ�����i����stack popջ��->��i push��ջ
			leftStack.pop();
			leftStack.push(i);
		}
		else {
			//1.3 height[i] > height[stack.top]��˵�������ұ߽�������ˣ�������Ҫ��ʼִ��������㣬�������µ�ջ�ұ߽�
			while (!leftStack.empty() && height[i] > height[leftStack.top()]) {
				int bottom = leftStack.top();
				leftStack.pop();

				if (!leftStack.empty()) {
					int h = min(height[i], height[leftStack.top()]) - height[bottom];
					int w = i - leftStack.top() - 1;
					sum += h * w;
				}
			}
			if (!leftStack.empty() && height[i] == height[leftStack.top()]) {//��������һ���ߵ�����ֻȡ���ҵ�����i����stack popջ��->��i push��ջ
				leftStack.pop();
			}
			leftStack.push(i);
		}
	}
	return sum;
}
void TrappingRainWater::test_TrappingRainWater() {
	TrappingRainWater TRW;
	vector<vector<int>> nums;
	nums.push_back({ 0,1,0,2,1,0,1,3,2,1,2,1 });
	nums.push_back({ 4,2,0,3,2,5 });
	for (int i = 0; i < nums.size(); i++) {
		cout << TRW.trap(nums[i]) << endl;
	}
}
