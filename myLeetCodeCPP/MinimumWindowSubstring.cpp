#include "MinimumWindowSubstring.h"

string MinimumWindowSubstring::minWindow(string s, string t) {
	/*��76�⣺��С�����Ӵ�
	* ʹ�û������ڷ���
	* 1. ������map targetMap��windowMap
	*	 1.1 targetMap���ڴ洢Ŀ���ַ����Ĳ���������keyΪchar����ʾ��Ӧ���ַ���valueΪint����ʾ���ַ���Ŀ��t�д��ڶ��ٸ�
	*	 1.2 windowMap���ڴ洢��ǰ���ڻ����Ĵ��ڵĲ���������keyΪchar��ͬ����ʾĿ���ַ�����Ӧ���ַ���valueΪint����ʾ���ַ��ڵ�ǰ�������ж��ٸ�
	*	 ps��Ҳ����˵��ʵtargetMap��windowMap��key��һ����
	* 2. ��ǰ�����Ĵ��ڵı�ʾ����
	*	 2.1 ��winStart��winEnd����ʾ���洢���������±꣬���ڴ��������һ����ģ����ѭ���в����ƶ�����winEnd
	*	 2.2 ���ڴ�winStart=0��winEnd=0�������һ��������ҵ���һ����Ŀ���ַ����еĵ�ʱ�ٵ�һ�θ�ֵ��winStart
	*		 ���ڲ�������ҿ��ķ�ʽ[winStart,winEnd����Ҳ������ÿ���жϴ����Ƿ����������Ŀ���ַ�ǰ����ִ��winEnd++  (��������)
	* 3. �����Ӵ����ж�
	*	 3.1 ��һ��count���洢��ǰ�������ҵ��ķ��ϸ��������������Ѱ���ĳ��Ŀ���ַ�c�����и���ʱ��count�ż�һ
	*		 Ҳ����targetMap[c] == winRight[c]ʱ��count++����ʾc�ַ����ڵ�ǰ������������
	*	 3.2 ��ɸ����Ӵ����жϣ���count==targetMap.size()ʱ˵������Ŀ���ַ��ѱ�ȫ�����룬���Խ��д��ڸ�����
	* 4. ���ڸ���
	*	 ������һ��minStart����¼����������С������㣬��minLen��¼����������С���ڵĳ��ȣ�[minStart, minStart+minLen)��������������С���ڣ���������return
	*	 4.1 �����ϴ��ڸ������������ winEnd - winStart < minLen ˵����ǰ���������µ�С���ڣ���Ҫ������С���ڲ�����minStart = winEnd; minLen = winEnd - winStart
	*	 4.2 ����������Ҳ����winStart���������ƣ����ڴ����а�����ĳ���ַ���windowMap[c]�����Ǳ�targetMap[c]��ģ����������������޶���������һ���ַ���ȫ��������windows����
	*	 ע�⣺��������ʱ���ù������winStart�ǲ��ǰ����˸�Ŀ����ĸ���е��ַ�����Ϊ�������������Ȼ��ǰ�����Ĵ����ڴ���ǰ�����ܻ��кܶ�������ַ�
	*		   �����������s��[winStart,s.size()-1]��Χ����Ҳû�а���tȫ���ַ����Ӽ��ˣ���ô��С�����Ӵ��Ѿ�������ǰ���minStart�б�����
	*		   ���������s��[winStart,s.size()-1]��Χ�ڻ��а���tȫ���ַ����Ӽ�����ô�����ҵ���Ҳ������ͨ������ɾ����Щ���ಢ���¸�����С���ڲ���
	*
	*/

	//1. ��������map��¼�ַ�����
	unordered_map<char, int> targetMap, windowMap;
	for (char c : t) {
		targetMap[c]++;
		windowMap[c] = 0;
	}
	int winStart = 0, winEnd = 0;//���ڴ洢��ǰ���ڱ����Ĵ��ڵķ�Χ[winStart, winEnd)
	int minStart = 0, minLen = INT_MAX;//���ڼ�¼������������С���ڵķ�Χ[minStart, minStart+minLen)
	int count = 0;//���ڼ�¼Ŀ���ж�Ӧ�ַ��ѱ�ȫ��������ĸ���
	while (winEnd < s.size()) {
		char c = s[winEnd];//��ǰ�ַ���������Ĵ���
		winEnd++;//�����һ�����֤��Χ������ҿ�
		//���µ�ǰ���ڲ���
		if (targetMap.count(c)) {
			windowMap[c]++;
			if (windowMap[c] == targetMap[c]) {
				//�ַ�c����ȫ������count
				count++;
			}
		}
		//��������󴰿�
		while (count == targetMap.size()) {
			//������С����
			if (winEnd - winStart < minLen) {
				minStart = winStart;
				minLen = winEnd - winStart;
			}
			//��ǰ���ڻ��ܰ�������t�ַ�������˻���Ҫ�������󴰿�
			char d = s[winStart];//�ַ��˳��ô���
			winStart++;
			if (targetMap.count(d)) {
				if (windowMap[d] == targetMap[d]) {
					//��ǰ�ַ�c�ڴ����������һ������������
					count--;
				}
				windowMap[d]--;
			}
		}
	}

	return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
}
void  MinimumWindowSubstring::test_MinimumWindowSubstring() {
	MinimumWindowSubstring MWS;
	vector<vector<string>> s{ {"ADOBECODEBANC", "ABC"}, {"a", "a"}, {"a", "aa"} };
	for (auto& temps : s) {
		cout << MWS.minWindow(temps[0], temps[1]) << endl;
	}
}
