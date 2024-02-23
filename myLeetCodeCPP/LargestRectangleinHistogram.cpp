#include "LargestRectangleinHistogram.h"

int LargestRectangleinHistogram::largestRectangleArea(vector<int>& heights) {
	/*第84题：柱状图中最大的矩形
	* 0. 单调栈：找左右两边的最值，采用单调栈方法
	*	 每次进入单调栈计算时需要有一个left、一个right和一个middle值：
	*	 - middle：往往是当前栈的栈顶（即将被pop）、left：当前栈顶端的第二个数、right是当前正在遍历的值
	* 1. 以示例1 heights = [2,1,5,6,2,3]为例来讲解思路
	*	 1.0 由于我们需要一个最左和最右值，且不像接雨水一样，最左边和最右边的柱子不能接雨水，这道题中最左边和最右边的柱子是能被水平且地包含在面积计算中的
	*		 因此需要在heights的前和后各补一个0 heights = [0,2,1,5,6,2,3,0]，不然当我们把栈底更新为1时，它没有left了，我们无法计算它的最终宽度w
	*		 而如果加了0，那么栈底永远有兜底（栈从栈底到栈顶是升序的，所以0可以兜底）
	*	 1.1 找某一列水平切过去的最大面积的原理：
	*	 虽然栈中存的是index，但是我们在讲解时说到的高低顺序指的是该index对应的heights值
	*	 某一列柱子所能计算的最大面积需要相邻的左柱或右柱的heights值比它高，这样它才能延申地水平切过去形成新的矩形
	*	 那么要计算该列柱子在整个数组中能围起来的最大面积，就是要往左（和右）分别找到第一个比它小的数，当遇到这个小的数时他就无法水平延申切过去了，左柱and右柱围起来的宽度就是该列柱子所围的最大宽了（该柱子的高是固定的）
	*	 那么放到0.中讲到的单调栈来说，我们就是要往左边找第一个（left）和往右找第一个（right）的比栈顶（middle）小的数
	*	 1.2 为什么栈顶的第二个数就是left，当前正在遍历的值就是right？
	*		 1.2.1 栈顶的第二个数就是left
	*			   栈中的数值都是我们已经遍历过的了，也就是说在栈中的数值都是还没有进行面积计算的，在等待找到比它还小的右边第一个柱子来终止向右水平延申形成面积
	*			   所以触发栈计算的条件就是遍历到   st.top() > heights[i], 说明栈顶找到了一个可以使它停止切割的点i了（其实这也变相说明了为什么right就是当前正在遍历的i）
	*			   那么说明了此时的栈顶是挤掉了所有比它还大的值才当上了栈顶的，但是他没挤掉当前栈中的第二个数，所以说明栈顶第二个数肯定是比栈顶大的
	*			   这也就说明了 当前栈顶第二个数 是 当前栈顶 往左找到的第一个比它（栈顶）还小的数，也就是栈顶可以终止水平向左延申的点
	*			   PS: 所以，我们要找到某列柱子（栈顶）往左/右第一个比它小的值，那么栈从栈底到栈顶的heights值就是升序的
	*		 1.2.2 正在遍历的值就是right
	*			   说回正题，要理解正在遍历的值就是right，还要理解栈中每个元素呆在栈中的意义
	*			   在示例1中，当我们遍历到栈成为	栈底->[0,1,5,6	时，由于触发heights为5的数弹出栈的条件是遍历到出现一个比5还小的，否则他就一直呆在栈里不出来
	*			   那么可以看到，当我们遍历到下一个数，也就是2时，这个数会循环弹出6，再弹出5，所以此时我们就可以说当前的这个2的位置是5对应的可以水平右切过去的最远距离了
	*/

	stack<int> st;
	int result = 0;
	heights.insert(heights.begin(), 0); heights.push_back(0); //1.0左右各添加一个0用于兜底
	st.push(0);//放入兜底值作为栈底，因为不会有比1还小的heights
	for (int i = 1; i < heights.size(); i++) {
		//这里不需要判断st.empty()，因为有栈底0兜底
		while (heights[i] < heights[st.top()]) {//触发栈计算
			int middle = st.top();
			st.pop();
			int left = st.top();
			int h = heights[middle]; int w = i - left - 1;
			result = max(result, h * w);
		}
		st.push(i);
	}
	return result;
}

void LargestRectangleinHistogram::test_LargestRectangleinHistogram() {
	LargestRectangleinHistogram LRH;
	vector<vector<int>> nums;
	nums.push_back({ 2,1,5,6,2,3 });
	nums.push_back({ 2,4 });
	for (int i = 0; i < nums.size(); i++) {
		cout << LRH.largestRectangleArea(nums[i]) << endl;
	}
}