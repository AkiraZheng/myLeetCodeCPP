#pragma once
#include <string>
using namespace std;

//找规律，每一行按 一个垂直字符+一个倾斜字符 的循环，根据index=2j+i append逐行的字符
//执行时间比pdf答案少，pdf的时间--内存分别为8ms--8.2MB
//0ms--8.30MB，100%--74.45%

class ZigzagConversion
{
public:
	string convert(string s, int nRows);
};

