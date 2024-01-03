#include "Median2SortedArrays.h"
//函数用于找到AUB排序后的第k个值，其中A跟B各自已经排序过了
static int find_kth(std::vector<int>::const_iterator A, int m, std::vector<int>::const_iterator B, int n, int k) {//得到的是迭代器
    if (m > n) {
        //假定m<=n成立
        return find_kth(B, n, A, m, k);//保证m<=n成立
    }
    if (m == 0) {
        //其中有一个数组已全被“删”完了，可以返回了
        return *(B + k - 1);//返回数组B剩余的第k个数值
    }
    if (k == 1) {
        //说明已经迭代进行到找A'UB'数组的第1个值了，此时只要比较A'[0]跟B'[0]的较小值就行
        return min(*(A), *(B));
    }

    //进入数据删除环节
    int ia = min(k / 2, m); int ib = k - ia;//保证ia + ib = k,同时需要考虑m是不是可能已经没有k/2个了
    if (*(A + ia - 1) < *(B + ib - 1)) {
        //删除A的前ia个值是安全的，删掉后继续找A'UB'的第k-ia个值
        return find_kth(A + ia, m - ia, B, n, k - ia);
    }
    else if (*(A + ia - 1) > *(B + ib - 1)) {
        //删除B的前ib个值是安全的，删掉后继续找A'UB'的第k-ib个值
        return find_kth(A, m, B + ib, n - ib, k - ib);
    }
    else {// *(A+ia-1) == *(B+ib-1) 
        //此时证明A的第ia个值跟B的第ib个值相等了
        //而ia + ib == k，因此证明A的第ia个值跟B的第ib个值都是属于k个
        //所以此时找到了第k个值，需要直接return返回递归的行列了
        return *(A + ia - 1);//直接返回A的第ia个值或B的第ib个值，逐层退出递归
    }
}

double Median2SortedArrays::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int k = (m + n) / 2;
    if ((m + n) & 0x1) {
        //k为单数，中位数只要找到AUB的第k+1个数就行
        return find_kth(nums1.begin(), m, nums2.begin(), n, k + 1);
    }
    else {
        //k为偶数，中位数需要找到AUB的第k个数和第k+1个数，求平均
        return (find_kth(nums1.begin(), m, nums2.begin(), n, k) +
            find_kth(nums1.begin(), m, nums2.begin(), n, k + 1)) / 2.0;
    }
}


