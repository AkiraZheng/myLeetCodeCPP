#include "MinimumWindowSubstring.h"

string MinimumWindowSubstring::minWindow(string s, string t) {
	/*第76题：最小覆盖子串
	* 使用滑动窗口方法
	* 1. 用两个map targetMap和windowMap
	*	 1.1 targetMap用于存储目标字符串的参数，其中key为char，表示对应的字符；value为int，表示该字符在目标t中存在多少个
	*	 1.2 windowMap用于存储当前正在滑动的窗口的参数，其中key为char，同样表示目标字符串对应的字符；value为int，表示该字符在当前窗口中有多少个
	*	 ps：也就是说其实targetMap和windowMap的key是一样的
	* 2. 当前滑动的窗口的表示方法
	*	 2.1 用winStart和winEnd来表示，存储窗口左右下标，由于窗口是向右滑动的，因此循环中不断移动的是winEnd
	*	 2.2 窗口从winStart=0和winEnd=0出发向右滑动，当找到第一个在目标字符串中的点时再第一次赋值给winStart
	*		 窗口采用左闭右开的方式[winStart,winEnd），也就是在每次判断窗口是否包含了所有目标字符前就先执行winEnd++  (窗口右扩)
	* 3. 覆盖子串的判断
	*	 3.1 用一个count来存储当前窗口已找到的符合个数，当窗口中已包含某个目标字符c的所有个数时，count才加一
	*		 也就是targetMap[c] == winRight[c]时，count++，表示c字符已在当前窗口中找齐了
	*	 3.2 完成覆盖子串的判断：当count==targetMap.size()时说明所有目标字符已被全部找齐，可以进行窗口更新了
	* 4. 窗口更新
	*	 首先用一个minStart来记录已搜索的最小窗口起点，用minLen记录已搜索的最小窗口的长度，[minStart, minStart+minLen)就是已搜索的最小窗口，用于最后的return
	*	 4.1 当符合窗口更新条件后，如果 winEnd - winStart < minLen 说明当前窗口是最新的小窗口，需要更新最小窗口参数：minStart = winEnd; minLen = winEnd - winStart
	*	 4.2 窗口左缩：也就是winStart不断往右移，由于窗口中包含的某个字符数windowMap[c]可能是比targetMap[c]大的，因此左边缩的做大限度是缩到有一个字符完全不存在与windows中了
	*	 注意：在缩窗口时不用管缩完后winStart是不是包含了该目标字母串中的字符，因为如果不包含，虽然当前滑动的窗口在窗口前方可能会有很多冗余的字符
	*		   但是如果后面s中[winStart,s.size()-1]范围内再也没有包含t全部字符的子集了，那么最小覆盖子串已经在我们前面的minStart中保存了
	*		   而如果后面s中[winStart,s.size()-1]范围内还有包含t全部字符的子集，那么我们找到后也会重新通过左缩删除这些冗余并重新更新最小窗口参数
	*
	*/

	//1. 建立两个map记录字符个数
	unordered_map<char, int> targetMap, windowMap;
	for (char c : t) {
		targetMap[c]++;
		windowMap[c] = 0;
	}
	int winStart = 0, winEnd = 0;//用于存储当前正在遍历的窗口的范围[winStart, winEnd)
	int minStart = 0, minLen = INT_MAX;//用于记录已搜索过的最小窗口的范围[minStart, minStart+minLen)
	int count = 0;//用于记录目标中对应字符已被全部搜索完的个数
	while (winEnd < s.size()) {
		char c = s[winEnd];//当前字符加入遍历的窗口
		winEnd++;//窗口右滑，保证范围是左闭右开
		//更新当前窗口参数
		if (targetMap.count(c)) {
			windowMap[c]++;
			if (windowMap[c] == targetMap[c]) {
				//字符c已找全，更新count
				count++;
			}
		}
		//找齐后：缩左窗口
		while (count == targetMap.size()) {
			//更新最小窗口
			if (winEnd - winStart < minLen) {
				minStart = winStart;
				minLen = winEnd - winStart;
			}
			//当前窗口还能包含所有t字符串，因此还需要继续缩左窗口
			char d = s[winStart];//字符退出该窗口
			winStart++;
			if (targetMap.count(d)) {
				if (windowMap[d] == targetMap[d]) {
					//当前字符c在窗口中是最后一个符合条件的
					count--;
				}
				windowMap[d]--;
			}
		}
	}

	return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
}
void  MinimumWindowSubstring::test_MinimumWindowSubstring() {
	MinimumWindowSubstring MWS;
	vector<vector<string>> s{ {"ADOBECODEBANC", "ABC"}, {"a", "a"}, {"a", "aa"} };
	for (auto& temps : s) {
		cout << MWS.minWindow(temps[0], temps[1]) << endl;
	}
}
