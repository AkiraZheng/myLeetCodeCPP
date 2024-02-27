#include "CourseSchedule.h"

bool CourseSchedule::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	/*��207�⣺�γ̱�
	* ͼ���⣬���Կ���������dfs���߹���bfs������������bfs+���������
	* prerequisites[i][0]����Ҫ�޿γ̣�prerequisites[i][1]�����Ӧ��ֱ�����޿γ̣�Ҫ����ͨ��prerequisites�����˰��ţ��ܱ�֤numCourses�ſ�ȫ���ܱ�����
	* ˵��������ġ�ֱ�ӡ���ʾ��������prerequisites������ͬһ�������е�
	* 1. ���˽ṹ
	*	 ����һ��numCourses�е���������ʾ��Ӧ������ͼ����Ϊ�γ̱�ſ϶���Ҫ�޵��ܿγ�ҪС�����Կ��Է��Ĵ��������С��
	*	 graph[i][]��ʾ��iΪֱ�����޿γ̵�����ֱ�Ӻ��޿γ̣���graph[i][j]����Ǻ��޿γ̵Ŀγ̺ţ�����ÿһ�е������ǲ�ͳһ��
	* 2. ��ȱ���ȱ�
	*	 һ���γ̵��������������Ҫ��ֱ�����޿γ̵����������ģ�һ����ȱ��deep[i]���ǿγ�i��Ҫ�����޿γ�����
	* 3. ����
	*	 ���зŵ���û���κ����޿γ̵Ŀγ̣�Ҳ����i�γ���deep[i]��ȱ��ֵ�Ѿ�����0�ˣ�����еĿγ̿��Ա���Ϊ�����޿γ̣�
	* 4. ��ȱ�Ͷ��еĵ���
	*	 ���зŵ���û���κ����޿γ̵Ŀγ�x����˿γ�x��Ӧ��ֱ�Ӻ��޿γ̵���ȶ�Ӧ�ü�1����graph[x]�п��Ա����γ�x�µ�����ֱ�Ӻ��޿γ̣��õ����޿γ̱�ź�Ѷ�Ӧ��deep��1���У�
	*	 ���γ̶�Ӧ��deep����Ϊ0ʱ��˵����Ҳ������Ϊ�����޿γ̼��뵽��������
	* 5. ���
	*	 ��countLearnedCourses��¼�Ѿ����޹������пγ�������Ҳ��������������еĿγ�������
	*	 ���countLearnedCourses!=numCourses˵���ڸ����˰����£����������㽫���пγ������Ҫ��
	*/

	vector<vector<int>> graph(numCourses);//����һ��numCourses�е���������ʾ��Ӧ������ͼ����Ϊ0 <= ai, bi < numCourses�����޺�Ҫ�޿γ̶�����numCourses�����Կ��Է��Ĵ��������С��
	vector<int> deep(numCourses,0);//�������Ҫ�޿γ�i��Ҫ���޶��ٸ�ֱ�����޿γ�
	queue<int> noPreCources;//���ڴ�������������޿γ̶�������ĿΣ�û���κ���������ĿΣ�Ҳ���Ǹ�Ҫ�޿γ̵ļ���ֵ�Ѿ�����0��

	//1.�������˽ṹ���������ʾ�����������ݴ������޿γ̣����Ϸ����Ը���Ϊֱ�����޿γ̵Ķ�ӦҪ�޿γ̣�graph[i][j]��ʾ�γ�graph[i][j]��ֱ�����޿γ���i��
	for (auto& pre : prerequisites) {
		graph[pre[1]].push_back(pre[0]);//�ҵ��Ե�i�У����Ϊi�Ŀγ̣���Ϊ���޿γ̵Ķ�ӦҪ�޿γ�
		deep[pre[0]]++;//��ʾҪ��pre[0]��Ҫ���޵Ŀγ�����1
	}

	//2.ͨ�����дӲ���Ҫ���޿γ̵���Щ�γ̿�ʼ����������У�����Ϊ��ǰ���޿γ�
	//������graph���ҵ��Ըÿγ���Ϊ���޿γ̵�����ֱ�Ӻ��ޣ�Ҫ�ޣ��γ̣���������ǵ�����������1����Ϊ��ʱ�����е�����γ��Ѿ�������Ϊ���޿γ��ˣ�
	//��ѭ����ĳ���γ̵����޼���ֵ��Ϊ0ʱ��˵���ÿγ̿�����Ϊ���޿γ��������
	for (int course = 0; course < numCourses; course++) {
		//�����������޿γ̵ĵ㶼�����
		if (deep[course] == 0) {
			noPreCources.push(course);
		}
	}
	//�ж�����ܲ��ܰ�numCourses���γ�ȫ������
	int countLearnedCourses = 0;
	while (!noPreCources.empty()) {
		countLearnedCourses++;
		//��ʼһ��������noPreCourse��Ϊ���޿γ̵Ŀζ�Ӧ��deep��1����Ϊ��ʱ��noPreCourese�еĿ������޵ģ�
		int learnedCourse = noPreCources.front();
		noPreCources.pop();
		for (auto lastCourse_of_learnedCourse : graph[learnedCourse]) {
			//��learnedCourse��ֱ�Ӻ��޿γ̶�ȡ����
			deep[lastCourse_of_learnedCourse]--;
			if (deep[lastCourse_of_learnedCourse] == 0) noPreCources.push(lastCourse_of_learnedCourse);//�µ������޿γ̳���
		}
	}
	return countLearnedCourses == numCourses;
}
void CourseSchedule::test_CourseSchedule() {
	CourseSchedule CS;
	vector<int> numCourses{ 2, 2 };
	vector<vector<int>> prerequisites0{ {1,0} };
	vector<vector<int>> prerequisites1{ {1,0} ,{0,1} };
	cout << CS.canFinish(numCourses[0], prerequisites0) << endl;
	cout << CS.canFinish(numCourses[1], prerequisites1) << endl;
}
