#include "ReverseInteger.h"

int ReverseInteger::reverse(int x) {
    //����x_int����ʹ��int���ͣ���Ϊ��������������1���������Կ��ܻ����
    //����y_result����ʹ��int���ͣ���Ϊ���ܻ����
    long long x_int = x;//ȫ����������Χ�ڲ���������ټ��Ϸ���
    x_int = x_int > 0 ? x_int : -x_int;
    long long y_result = 0;
    for (; x_int; x_int /= 10) {
        y_result = y_result * 10 + x_int % 10;//�Ƚ�ǰ��Ľ����10Ҳ���ǽ�һλ��λ����Ϊ0��Ȼ����ȡ������Ϊ�µĸ�λ��
    }

    y_result = x > 0 ? y_result : -y_result;//���Ϸ���
    if (y_result > 2147483647 || y_result < -2147483648)
        //�������0
        return 0;
    else
        return y_result;
}

