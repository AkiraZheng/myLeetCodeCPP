#include "test.h"
#include <algorithm>

void testLambda::testLam() {
	int x = 10, y = 20;
	auto fun1 = [=]() {
		cout << "��ֵ��" << x << " " << y << endl;
	};
	auto fun2 = [&]() {
		cout << "�����ã�" << x << " " << y << endl;
	};
	x = 100;
	fun1();
	fun2();
}

void containerTest::testContainer() {
	//����vector��sort��for_eachʹ��:��Ҫ����algorithm
	vector<int> vec = { 1, 3, 2, 7, 5, 11, 10 };
	for_each(vec.begin(), vec.end(), [=](int x) {cout << x << " "; });
	sort(vec.begin(), vec.end());//����
	cout << "\n";
	for (int x : vec) {
		cout << x << " ";
	}
}

void testError::catchError_abort() {
	cout << "test dbort:" << endl;
	abort();
	cout << "After Abort" << endl;
	//cout << 1 / 0;
}

void testError::throw_error(string& s) {
	s = "Throw";
	throw bad_mess();
}

test::test(int num) {
	nums = num;
}

void test::changeNums(test& t) {
	test temp = t;
	t.nums = this->nums;
}

int test::getNums() {
	return nums;
}