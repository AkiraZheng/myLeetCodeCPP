#include "Median2SortedArrays.h"
//���������ҵ�AUB�����ĵ�k��ֵ������A��B�����Ѿ��������
static int find_kth(std::vector<int>::const_iterator A, int m, std::vector<int>::const_iterator B, int n, int k) {//�õ����ǵ�����
    if (m > n) {
        //�ٶ�m<=n����
        return find_kth(B, n, A, m, k);//��֤m<=n����
    }
    if (m == 0) {
        //������һ��������ȫ����ɾ�����ˣ����Է�����
        return *(B + k - 1);//��������Bʣ��ĵ�k����ֵ
    }
    if (k == 1) {
        //˵���Ѿ��������е���A'UB'����ĵ�1��ֵ�ˣ���ʱֻҪ�Ƚ�A'[0]��B'[0]�Ľ�Сֵ����
        return min(*(A), *(B));
    }

    //��������ɾ������
    int ia = min(k / 2, m); int ib = k - ia;//��֤ia + ib = k,ͬʱ��Ҫ����m�ǲ��ǿ����Ѿ�û��k/2����
    if (*(A + ia - 1) < *(B + ib - 1)) {
        //ɾ��A��ǰia��ֵ�ǰ�ȫ�ģ�ɾ���������A'UB'�ĵ�k-ia��ֵ
        return find_kth(A + ia, m - ia, B, n, k - ia);
    }
    else if (*(A + ia - 1) > *(B + ib - 1)) {
        //ɾ��B��ǰib��ֵ�ǰ�ȫ�ģ�ɾ���������A'UB'�ĵ�k-ib��ֵ
        return find_kth(A, m, B + ib, n - ib, k - ib);
    }
    else {// *(A+ia-1) == *(B+ib-1) 
        //��ʱ֤��A�ĵ�ia��ֵ��B�ĵ�ib��ֵ�����
        //��ia + ib == k�����֤��A�ĵ�ia��ֵ��B�ĵ�ib��ֵ��������k��
        //���Դ�ʱ�ҵ��˵�k��ֵ����Ҫֱ��return���صݹ��������
        return *(A + ia - 1);//ֱ�ӷ���A�ĵ�ia��ֵ��B�ĵ�ib��ֵ������˳��ݹ�
    }
}

double Median2SortedArrays::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int k = (m + n) / 2;
    if ((m + n) & 0x1) {
        //kΪ��������λ��ֻҪ�ҵ�AUB�ĵ�k+1��������
        return find_kth(nums1.begin(), m, nums2.begin(), n, k + 1);
    }
    else {
        //kΪż������λ����Ҫ�ҵ�AUB�ĵ�k�����͵�k+1��������ƽ��
        return (find_kth(nums1.begin(), m, nums2.begin(), n, k) +
            find_kth(nums1.begin(), m, nums2.begin(), n, k + 1)) / 2.0;
    }
}


