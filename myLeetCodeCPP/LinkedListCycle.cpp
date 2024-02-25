#include "LinkedListCycle.h"

bool LinkedListCycle::hasCycle(ListNode* head) {
	/*第141题：环形链表
	* 1. 如何判断是否有环？
	*	 采用快慢指针方法，令fast指针一次走2步，slow指针一次走1步
	*	 如果没有环的话，那么走到最后遇到nullptr就可以返回false了，而如果有环的话，那么两个指针最终一定会在环里相遇，所以只要判断是否有fast==slow的情况就可以知道是否有环了
	* 2. 如何确定环的入口节点呢？（这道题其实不需要判断，但是可以了解一下）
	*	 如果有环的话，那么fast先进入环内，等slow进入环后，fast开始追赶slow，二者的相对速度是fast比slow快1
	*	 如果slow在环内绕了一圈，那么fast已经可以绕2圈了，所以fast一定会在slow入环后的一圈内追到slow(也就是当二者相遇时，slow肯定还没走够一圈)
	*	 那么假设head离环的入口距离是x，入口距离fast和slow相遇的点顺时针距离为y(也就是slow在环内走了y)，相遇的点里入口顺时针还有z（也就是slow还差z才走完一圈）
	*	 2.1 计算入口节点的位置
	*		 在fast和slow相遇前，fast可能已经在环内走n圈了，也就是已经走了n(y+z)则：
	*		 a. slow总共走的距离 len_slow = x+y
	*		 b. fast总共走的距离 len_fast = x + n(y+z) + y
	*		 由于fast速度是slow的两倍，因此有len_fast = 2*len_slow,简化后有x+y=n(y+z)
	*		 由于我们最后要求的是x，因此我们先把其他数全部放在等式右边：x=n(y+z)-y
	*		 c.提出一个环出来有 x=(n-1)(y+z)+z ,从这个式子我们就可以看出来了，假设我们在起点放一个index1准备往前走，在fast和slow相遇的点放一个index2在环里绕圈，都以step1往前走
	*		   index1走等式左边的x：		   那么当index1走过了左式x步到达入口点后(index1走了x步)
	*		   index2走等式右边的(n-1)(y+z)+z：此时我们的index2出发点离入口还剩z的距离，当走完z后到达环入口点后，再绕n-1圈肯定能恰好在index1入圈的时候跟他在入口相遇，此时相遇的点就是入口点(index2走了(n-1)(y+z)+z步)
	*/
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != nullptr && fast->next != nullptr) {
		//快指针走两步
		fast = fast->next->next;
		//慢指针走一步
		slow = slow->next;
		if (fast == slow) {
			//有环相遇了，可以直接return
			return true;
		}
	}
	return false;
}
