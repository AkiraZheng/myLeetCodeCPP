#include "LongestPalindromicSubstring_Manach.h"
string LongestPalindromicSubstring_Manach::changeS2T(const string& s) {
	/*
	���ַ�����"abba"ת��Ϊ"#a#b#b#a#"
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
	�������㷨����s��������ַ���
	*/
	string T = changeS2T(s);
	const int n = T.size();

	//vs�޷���ʼ������Ϊn�Ǳ��������ǳ����������vector����
	//int p[n];                          // ��¼T��ÿ��index iΪ���ĵ�Ļ��ĳ���
	vector<int> p(n, 0);             // ��¼T��ÿ��index iΪ���ĵ�Ļ��ĳ���
	int cid = 0, mR = 0, i_mirror = 0; // cidΪ��ǰ����Ĵ������ĵ㣬mRΪ��ǰ����Ĵ����ұ߽�
	int max_len = 0, center_index = 0;
	for (int i = 0; i < n; i++)
	{
		i_mirror = 2 * cid - i;                         // i����cid�ĶԳƵ�:cid-(i-cid)
		p[i] = (mR > i) ? min(mR - i, p[i_mirror]) : 0; // p[i]�ĳ�ʼֵΪ0����p[i_mirror]��mR-i����Сֵ
		while ((i + p[i] + 1 < n) && (i - p[i] - 1 >= 0) && (T[i + p[i] + 1] == T[i - p[i] - 1]))
			p[i]++; // ��iΪ������������չ��ֱ���������������
		// ����cid��mR
		if ((i + p[i]) > mR)
		{
			// �µ�Ϊ��iΪcid�ı߽�mR
			cid = i;
			mR = i + p[i];
		}
		// ��������Ĵ�
		if (p[i] > max_len)
		{
			max_len = p[i];
			center_index = i;
		}
	}
	return s.substr((center_index - max_len) / 2, max_len);
}
