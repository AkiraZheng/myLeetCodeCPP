#include "LongestPalindromicSubstring_Manach.h"
string LongestPalindromicSubstring_Manach::changeS2T(const string& s) {
	/*
	将字符串如"abba"转换为"#a#b#b#a#"
	*/
	string T = "";
	for (int i = 0; i < s.size(); i++)
	{
		T += "#";
		T += s[i];
	}
	return T + "#";
}

string LongestPalindromicSubstring_Manach::longestPalindrome(string s)
{
	/*
	马拉车算法计算s的最长回文字符串
	*/
	string T = changeS2T(s);
	const int n = T.size();

	//vs无法初始化，因为n是变量，不是常量，因此用vector代替
	//int p[n];                          // 记录T中每个index i为中心点的回文长度
	vector<int> p(n, 0);             // 记录T中每个index i为中心点的回文长度
	int cid = 0, mR = 0, i_mirror = 0; // cid为当前最长回文串的中心点，mR为当前最长回文串的右边界
	int max_len = 0, center_index = 0;
	for (int i = 0; i < n; i++)
	{
		i_mirror = 2 * cid - i;                         // i关于cid的对称点:cid-(i-cid)
		p[i] = (mR > i) ? min(mR - i, p[i_mirror]) : 0; // p[i]的初始值为0或者p[i_mirror]与mR-i的最小值
		while ((i + p[i] + 1 < n) && (i - p[i] - 1 >= 0) && (T[i + p[i] + 1] == T[i - p[i] - 1]))
			p[i]++; // 以i为中心向两边扩展，直到不满足回文条件
		// 更新cid和mR
		if ((i + p[i]) > mR)
		{
			// 新的为以i为cid的边界mR
			cid = i;
			mR = i + p[i];
		}
		// 更新最长回文串
		if (p[i] > max_len)
		{
			max_len = p[i];
			center_index = i;
		}
	}
	return s.substr((center_index - max_len) / 2, max_len);
}
