#pragma once
#include "header.h"
class MinStack
{
private:
	stack<int> m_stack;
	stack<int> m_minStack;//与每个栈元素对应的当前最小值
	int minNum;
public:
	MinStack() {
		m_minStack.push(INT_MAX);
		minNum = INT_MAX;
	}

	void push(int val) {
		m_stack.push(val);
		if (val < m_minStack.top()) {
			//新的最小值
			m_minStack.push(val);
			minNum = val;
		}
		else {
			m_minStack.push(m_minStack.top());
		}
	}

	void pop() {
		if (m_stack.size() != 0) {
			m_stack.pop();
			m_minStack.pop();
			minNum = m_minStack.top();
		}
	}

	int top() {
		return m_stack.top();
	}

	int getMin() {
		return minNum;
	}
};

