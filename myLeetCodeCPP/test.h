#pragma once
#include "header.h"

class testLambda {
public:
	void testLam();
};

class containerTest {
public:
	void testContainer();
};

class virtualTest {
public:
	virtual void acc1(void) = 0;//定义一个纯虚函数
};

class bad_mess : public exception {
public:
	bad_mess() {};
	const char * what() const {
		return "throw an error";
	}
};

class testError {
public:
	void catchError_abort();
	void throw_error(string &s);
};

class test
{
public:
	test(int num);
	void changeNums(test& t);
	int getNums();
private:
	int nums;
	//virtualTest vt;//不允许使用抽象类类型“virtualTest"的对象函数"virtualTest:acc1"是纯虚拟函数
};



