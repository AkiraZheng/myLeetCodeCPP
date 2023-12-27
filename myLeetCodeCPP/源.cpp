#include <iostream>
#include "StringToInteger.h"
using namespace std;

int main() {
	StringToInteger sti;
	cout << sti.myAtoi("2147483648") << endl;
	return 0;
}