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
	virtual void acc1(void) = 0;//����һ�����麯��
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
	//virtualTest vt;//������ʹ�ó��������͡�virtualTest"�Ķ�����"virtualTest:acc1"�Ǵ����⺯��
};



