#include "CombinationSum.h"

vector<vector<int>> CombinationSum::combinationSum(vector<int>& candidates, int target) {
	/*��39�⣺����ܺ�
	* ��ϲ��õݹ���ݷ�����������Ρ���������������չ��
	* 1. ����
	*	 �����ǽ�����candidates��target����
	*	 ��Σ����ǽ���������sum�йأ����ҲҪ����sum;(���������л�Ҫ����ǰ������ȡ�����ݣ����ҲҪ��һ�������洢��ȡ�����ݣ�������result���������Σ����Ƿ���ȫ�ֲ�����)
	*	 ���ǵ���չ�����еݹ�ʱ����Ҫ����ȡ������chooseNum = nums[index]
	* 2. ��������
	*	 ��Ϊ�����е����ֿ��Ա�����ȡ��������ֻҪsum>=target�Ϳ����˳��ˣ���Ŀ��˵��������0����˲��õ�������ȡֵ��ɵݹ���ѭ����
	*	 2.1 sum>target��˵��û�м����ݹ�ȡֵ�ı�Ҫ�ˣ����֦�ɲ�����������ֱ��return
	*	 2.2 sum==target��push��result��
	* 3. ����չ��
	*	 ������Ȼ����ÿһ���ͬ��Ԫ����˵��������ȡ�������Ƕ���ͬһ֦���ϵ�һ�������������˵��ÿ����ֻ�ܱ�ȡһ��
	*	 �����Ҫһ��startIndex��������ʾ������Դ��ĸ�����ʼѭ��ȡ��ÿһ�㶼������nums.size()-startIndex-1��չ�����ݹ飩
	*/
	result.clear();
	layer_nums.clear();
	backtrack(candidates, target, 0, 0);
	return result;
}

void CombinationSum::backtrack(vector<int>& candidates, int target, int sum, int startIndex) {
	//2. ��������
	if (sum > target) {
		//2.1 sum > target��˵��û�м����ݹ�ȡֵ�ı�Ҫ�ˣ����֦�ɲ�����������ֱ��return
		return;
	}
	else if (sum == target) {
		//2.2 sum == target��push��result��
		result.push_back(layer_nums);
		return;
	}

	//3. ����չ��
	for (int i = startIndex; i < candidates.size(); i++) {//�������֦�Ļ����������о���Ҫ�ȶ�candidates��������&& (sum + candidates[i]) > target
		sum += candidates[i];
		layer_nums.push_back(candidates[i]);
		backtrack(candidates, target, sum, i);
		sum -= candidates[i];//����
		layer_nums.pop_back();//����
	}
}

void CombinationSum::test_CombinationSum() {
	CombinationSum CS;
	vector< vector<int> > nums;
	nums.push_back({ 2,3,6,7 });
	nums.push_back({ 2,3,5 });
	nums.push_back({ 2 });
	vector<int> targets{ 7,8,1 };
	for (int i = 0; i < nums.size() - 1; i++) {
		vector<vector<int> > result_temp = CS.combinationSum(nums[i], targets[i]);
		for (int i = 0; i < result_temp.size(); i++) {
			for (int temp : result_temp[i]) {
				cout << " " << temp;
			}
		}
		cout << endl;
	}
}