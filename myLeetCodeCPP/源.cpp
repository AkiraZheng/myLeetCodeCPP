#include <iostream>
//#include "StringToInteger.h"
//#include "PalindromeNumber.h"
//#include "RegularExpressionMatching_recursive.h"
//#include "RegularExpressionMatching_DP.h"
#include "BinarySearch.h"

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

	/*string s = "ab";
	string p = ".*";
	RegularExpressionMatching_DP rem_DP;
	cout << rem_DP.isMatch(s, p);*/

	BinarySearch BS;
	//vector<int> nums = {-1, 0, 3, 5, 9, 12};
	vector<int> nums = { -1 };
	cout << BS.search(nums, 2) << endl;


	return 0;
}