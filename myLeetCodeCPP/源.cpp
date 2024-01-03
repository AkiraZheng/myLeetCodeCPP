#include <iostream>
//#include "StringToInteger.h"
//#include "PalindromeNumber.h"
//#include "RegularExpressionMatching_recursive.h"
#include "RegularExpressionMatching_DP.h"

using namespace std;
int main() {
	/*StringToInteger sti;
	cout << sti.myAtoi("2147483648") << endl;*/

	/*PalindromeNumber pn;
	cout << pn.isPalindrome(1001);*/

	/*RegularExpressionMatching_recursive rem;
	string s = "aac";
	string p = "a*aac";
	cout << rem.isMatch(s, p);*/

	string s = "ab";
	string p = ".*";
	RegularExpressionMatching_DP rem_DP;
	cout << rem_DP.isMatch(s, p);

	return 0;
}