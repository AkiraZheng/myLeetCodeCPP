#include "CourseSchedule.h"

bool CourseSchedule::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	/*第207题：课程表
	* 图论题，可以考虑用深搜dfs或者广搜bfs解决，这里采用bfs+队列来解决
	* prerequisites[i][0]代表要修课程，prerequisites[i][1]代表对应的直接先修课程，要求是通过prerequisites的拓扑安排，能保证numCourses门课全部能被修完
	* 说明：下面的“直接”表示两个数在prerequisites中是在同一行数组中的
	* 1. 拓扑结构
	*	 创建一个numCourses行的数组来表示对应的拓扑图（因为课程编号肯定比要修的总课程要小，所以可以放心创建这个大小）
	*	 graph[i][]表示以i为直接先修课程的所有直接后修课程，而graph[i][j]存的是后修课程的课程号，所以每一行的列数是不统一的
	* 2. 入度表（深度表）
	*	 一个课程的深度是由它所需要的直接先修课程的总数决定的，一次入度表存deep[i]的是课程i需要的先修课程总数
	* 3. 队列
	*	 队列放的是没有任何先修课程的课程，也就是i课程其deep[i]入度表的值已经被清0了（入队列的课程可以被认为是已修课程）
	* 4. 入度表和队列的迭代
	*	 队列放的是没有任何先修课程的课程x，因此课程x对应的直接后修课程的深度都应该减1（从graph[x]中可以遍历课程x下的所有直接后修课程，拿到后修课程编号后把对应的deep减1就行）
	*	 当课程对应的deep被减为0时，说明它也可以作为无先修课程加入到队列中了
	* 5. 结果
	*	 用countLearnedCourses记录已经被修过的所有课程总数（也就是所有能入队列的课程总数）
	*	 如果countLearnedCourses!=numCourses说明在该拓扑安排下，并不能满足将所有课程修完的要求
	*/

	vector<vector<int>> graph(numCourses);//创建一个numCourses行的数组来表示对应的拓扑图（因为0 <= ai, bi < numCourses，先修和要修课程都不比numCourses大，所以可以放心创建这个大小）
	vector<int> deep(numCourses,0);//用与计数要修课程i需要先修多少个直接先修课程
	queue<int> noPreCources;//用于存遍历后所有先修课程都被修完的课（没有任何先修需求的课，也就是该要修课程的计数值已经被清0）

	//1.补齐拓扑结构：用数组表示，其中行数据代表先修课程，不断放入以改行为直接先修课程的对应要修课程（graph[i][j]表示课程graph[i][j]的直接先修课程是i）
	for (auto& pre : prerequisites) {
		graph[pre[1]].push_back(pre[0]);//找到以第i行（编号为i的课程）作为先修课程的对应要修课程
		deep[pre[0]]++;//表示要修pre[0]需要先修的课程数增1
	}

	//2.通过队列从不需要先修课程的那些课程开始遍历（入队列），作为当前已修课程
	//从拓扑graph中找到以该课程作为先修课程的所有直接后修（要修）课程，逐个将他们的先修数量减1（因为此时队列中的这个课程已经可以作为已修课程了）
	//当循环到某个课程的先修计数值变为0时，说明该课程可以作为已修课程如队列了
	for (int course = 0; course < numCourses; course++) {
		//将所有无先修课程的点都入队列
		if (deep[course] == 0) {
			noPreCources.push(course);
		}
	}
	//判断最后能不能把numCourses个课程全部修完
	int countLearnedCourses = 0;
	while (!noPreCources.empty()) {
		countLearnedCourses++;
		//开始一个个将以noPreCourse作为先修课程的课对应的deep减1（因为此时的noPreCourese中的课是已修的）
		int learnedCourse = noPreCources.front();
		noPreCources.pop();
		for (auto lastCourse_of_learnedCourse : graph[learnedCourse]) {
			//将learnedCourse的直接后修课程都取出来
			deep[lastCourse_of_learnedCourse]--;
			if (deep[lastCourse_of_learnedCourse] == 0) noPreCources.push(lastCourse_of_learnedCourse);//新的无已修课程出现
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
