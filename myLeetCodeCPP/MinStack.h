#pragma once
#include "header.h"
class MinStack
{
private:
	stack<int> m_stack;
	stack<int> m_minStack;//��ÿ��ջԪ�ض�Ӧ�ĵ�ǰ��Сֵ
	int minNum;
public:
	MinStack() {
		m_minStack.push(INT_MAX);
		minNum = INT_MAX;
	}

	void push(int val) {
		m_stack.push(val);
		if (val < m_minStack.top()) {
			//�µ���Сֵ
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

