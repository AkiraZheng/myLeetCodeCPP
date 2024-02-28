#pragma once
#include "header.h"
class MyQue {
private:
    // 队列m_que的特点：
    // 1. 队列是单调递减队列，从top->back单调递减，则此时维护的窗口中最大值就是top()
    // 2. 进队列的顺序是：top先->back后
    deque<int> m_que;//双端队列，队列尾也可以pop
public:
    //自定义一个单调队列：关注点落在维护当前窗口的最大值在top，又能通过pop清除当前需要出滑动窗口的值
    void push(int value) {//value是要进窗口的值
        while (!m_que.empty() && value > m_que.back()) {//等于的时候不能出队列，因为不然后面pop出窗口的时候就会少一个数
            //1. 将比进窗口值还小的全部出队列，这样能保证单调递减队列从队列top到队列back都是递减的
            //1.1 这样如果队列头被pop出来，那么下一个值依然是当前队列中的最大值，这样才能保证维护窗口最大值
            //1.2 而且pop掉小的值是无所谓的，因为这些小的值肯定没办法作为当前窗口的最大值，自然也没办法作为后面的窗口的最大值
            //   （因为这些小值是先进队列的，肯定比现在的value要更早出窗口）
            m_que.pop_back();
        }
        m_que.push_back(value);//再将当前值进队列（进窗口）
    }
    void pop(int value) {//value是需要出滑动窗口对应的值
        // 1. value是当前遍历到的窗口尾的值，需要出队列
        // 2. 如果此时刚刚好m_que.top()是value，那么说明队列头就是我们要清掉的值，只有清掉了才不会影响后面窗口最大值的判断（因为队列头就是最大值的返回）
        // 3. 而如果value不是top的值，那么说明它已经作为小值被push进一个大数的时候给迭代掉
        //    解释：因为我们知道每个值在进队列的时候都会把前面的小值pop掉
        //         a. 如果当前的value在数组中在top后面（比当前top晚进），这是不可能的，因为如果这样的话，top对应的值肯定已经被删掉（出窗口）了
        //         b. 所以当前的value只可能是比top早进窗口的，那么他早就被top这个大值迭代掉了（不在队列了）
        if (value == m_que.front()) {//经过上面的分析，只有与队列顶相同才需要pop
            m_que.pop_front();
        }
    }
    int getMax() {
        return m_que.front();
    }
};
class SlidingWindowMaximum
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQue que;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);//先构建初始k个值的窗口
        }
        result.push_back(que.getMax());
        //最后再不断地从左往右一个一个出窗口和入窗口
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);//当前值出窗口
            que.push(nums[i]);//后一个值入窗口
            result.push_back(que.getMax());
        }
        return result;
    }
};

