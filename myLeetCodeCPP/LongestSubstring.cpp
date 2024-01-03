#include "LongestSubstring.h"
int LongestSubstring::lengthOfLongestSubstring(string s) {
    int last[255];//其中255为最大的ASCII数，索引用于代表单个字符
    fill(last, last + 255, -1);//初始化last数组
    int max_len = 0;
    int start_index = 0;//标记重新round搜索的初始索引
    for (int i = 0; i < s.size(); i++) {
        if (last[s[i]] >= start_index) {//说明在该轮中出现过这个符号，出现了重复
            max_len = max(max_len, i - start_index);//注意最后一轮时如果最后一个字母没出现过，则无法更新最后一轮的len结果，因此在return时需要补充增加一次取值
            start_index = last[s[i]] + 1;//更新下一轮round搜索的起始index
        }
        last[s[i]] = i;//更新s[i]字符对应的最新索引到last中
    }
    return max(max_len, (int)s.size() - start_index);//最后一轮长度与前面最大长度的比较
}
