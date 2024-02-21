#pragma once
#include "header.h"
class TrappingRainWater
{
public:
	//1.采用优化的双指针方法
	int trap_doublePtr(vector<int>& height);
	static void test_TrappingRainWater_doublePtr();
	//2.采用单调栈方法
	int trap(vector<int>& height);
	static void test_TrappingRainWater();
};

