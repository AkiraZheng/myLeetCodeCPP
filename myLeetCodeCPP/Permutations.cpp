#include "Permutations.h"

vector<vector<int>> Permutations::permute(vector<int>& nums){
	/*��46�⣺ȫ����
	* �����������������뵽���ݵݹ飺���Ρ��˳�����������չ��
	* 1. ���Σ�
	*	 nums
	*	 �����Ƴ���������Ҫ���鳤�Ⱥ���ȡ����ֵ�������бȽϣ���ȡ��nums.size()�˾�return����˻���Ҫ����һ����ȡ����
	*	 ps:�Ѵ��������������ȡ��indexһ���ӽ�ȥ����ô�ڵ���չ��ʱ����Ҫһ�����ж��Ƿ���ȡ����ʱ����˿������һ����nums sizeһ����vector����true-false��ʾ�Ƿ���ȡ
	* 2. �˳�������
	*	 �Ƴ�����Ҳ������ȣ�ÿ�����е����鳤��Ϊnums.size()�������Ⱦ���nums.size()
	* 3. ����չ��
	*	 ����չ���漰ѭ������������ǰ����ȡ����ֵ��ͬһ֦�ɺ���㲻���ظ��������Ҫһ��vector�洢�Ѿ�ȡ����ֵ��ֻ�в���vector����ֵ����Ҫ�ڴ˲�����ݹ�
	*/
	result.clear();
	permutationNode.clear();
	vector<bool> isChoose(nums.size(), false);
	backtrack(nums, isChoose);
	return result;
}

void Permutations::backtrack(vector<int>& nums, vector<bool>& isChoose) {
	//2. �˳�����
	if (nums.size() == permutationNode.size()) {
		result.push_back(permutationNode);
		return;
	}

	//3. ����չ��
	for (int i = 0; i < nums.size(); i++) {
		if (isChoose[i]) continue;//��ȡ�Ĳ�����
		isChoose[i] = true;
		permutationNode.push_back(nums[i]);
		backtrack(nums, isChoose);
		isChoose[i] = false;//����
		permutationNode.pop_back();//����
	}
}

void Permutations::test_Permutations() {
	Permutations P;
	vector<vector<int>> nums;
	nums.push_back({ 1,2,3 });
	nums.push_back({ 0,1 });
	nums.push_back({1});
	for (int i = 0; i < nums.size(); i++) {
		vector<vector<int>> result = P.permute(nums[i]);
		P.printVector(result);
		cout << endl;
	}
}

void Permutations::printVector(vector<vector<int>>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int temp : nums[i]) {
			cout << temp << " ";
		}
		cout << ",";
	}
}
