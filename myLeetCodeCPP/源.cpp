#include <iostream>
//#include "StringToInteger.h"
//#include "PalindromeNumber.h"
//#include "RegularExpressionMatching_recursive.h"
//#include "RegularExpressionMatching_DP.h"
//#include "BinarySearch.h"
//#include "FindFirstLastPosition.h"
//#include "SqrtX.h"
//#include "ValidPerfectSquare.h"
//#include "RemoveElement.h"
//#include "ContainerWithMostWater.h"
//#include "three3Sum.h"
//#include "LetterCombinationsPhoneNum.h"
//#include "ValidParentheses.h"
//#include "GenerateParentheses.h"
//#include "NextPermutation.h"
//#include "LongestValidParentheses.h"
//#include "SearchinRotatedSortedArray.h"
//#include "CombinationSum.h"
//#include "TrappingRainWater.h"
//#include "Permutations.h"
//#include "RotateImage.h"
//#include "GroupAnagrams.h"
//#include "MaximumSubarray.h"
//#include "JumpGame.h"
//#include "MergeIntervals.h"
//#include "UniquePaths.h"
//#include "MinimumPathSum.h"
//#include "ClimbingStairs.h"
//#include "EditDistance.h"
//#include "SortColors.h"
//#include "MinimumWindowSubstring.h"
//#include "Subsets.h"
#include "WordSearch.h"

#include "test.h"

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

	//BinarySearch BS;
	////vector<int> nums = {-1, 0, 3, 5, 9, 12};
	//vector<int> nums = { -1 };
	//cout << BS.search(nums, 2) << endl;

	/*FindFirstLastPosition FFLP;
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> result = FFLP.searchRange(nums, 8);
	cout << result.at(0) << result.at(1);*/

	/*SqrtX sx;
	cout << sx.mySqrt(1);*/

	/*ValidPerfectSquare vps;
	cout << vps.isPerfectSquare(14);*/

	/*RemoveElement re;
	vector<int> nums = { 0,1,2,2,3,0,4,2 };
	int result = re.removeElement(nums, 2);
	cout << result;*/

	/*盛最多水的容器*/
	//ContainerWithMostWater::test_maxArea();

	/*三数之和*/
	//three3Sum::test_threeSum();

	/*电话号码的字母组合*/
	//LetterCombinationsPhoneNum::test_LetterCombinationsPhoneNum();

	/*有效的括号*/
	//ValidParentheses::test_ValidParentheses();

	/*括号生成*/
	//GenerateParentheses::test_GenerateParentheses();

	/*下一个排列*/
	//NextPermutation::test_NextPermutation();

	/*最长有效括号*/
	//LongestValidParentheses::test_LongestValidParentheses();

	/*搜索旋转排序数组*/
	//SearchinRotatedSortedArray::test_SearchinRotatedSortedArray();

	/*组合总和*/
	//CombinationSum::test_CombinationSum();

	/*接雨水*/
	//TrappingRainWater::test_TrappingRainWater_doublePtr();
	//TrappingRainWater::test_TrappingRainWater();

	/*全排排列*/
	//Permutations::test_Permutations();

	/*旋转图像*/
	//RotateImage::test_RotateImage();

	/*字母异位词分组*/
	//GroupAnagrams::test_GroupAnagrams();

	/*最大子数组和*/
	//MaximumSubarray::test_MaximumSubarray();

	/*跳跃游戏*/
	//JumpGame::test_JumpGame();

	/*合并区间*/
	//MergeIntervals::test_MergeIntervals();

	/*不同路径*/
	//UniquePaths::test_UniquePaths();

	/*最小路径和*/
	//MinimumPathSum::test_MinimumPathSum();

	/*爬楼梯*/
	//ClimbingStairs::test_ClimbingStairs();

	/*编辑距离*/
	//EditDistance::test_EditDistance();

	/*颜色分类*/
	//SortColors::test_SortColors();

	/*最小覆盖子串*/
	//MinimumWindowSubstring::test_MinimumWindowSubstring();

	/*子集*/
	//Subsets::test_Subsets();

	/*单词搜索*/
	WordSearch::test_WordSearch();

	return 0;
}