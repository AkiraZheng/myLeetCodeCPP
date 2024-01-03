#pragma once

//全部转成正数进行反转，要注意负数转正数的溢出以及最终反转结果溢出的情况；反转时采用按位求余数的方法即可。
//0ms--6.25MB，100%--27.14%

class ReverseInteger
{
public:
	int reverse(int x);
};

