#pragma once
#include "header.h"
class QueueReconstructionbyHeight
{
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        //�Զ�������sort��ʽ:�Ȱ���߽�����,��ͬ��ߵ�ǰ��վ�ĸ��ߵ������ٵķ���ǰ��
        if (a[0] == b[0]) return a[1] < b[1];//�����ŵڶ�������
        return a[0] > b[0];//�����ŵ�һ������(���)
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        /*��406��:��������ؽ�����
        * ����ȷ����������������˳��,��Ϊ�ؼ�����ĳ����ǰ������ߵ��˵�����,�����������ȿ��Ը�����ߴӸ���������������
        * ������ͬ��ߵ���ô����?�϶��Ǿ��и��ٵı���������߸߻���ͬ���Ǹ���վ��ǰ��,����ͬ�������,վ�ں�����Ǹ��������ͬ��ߵ�����ǰ��,�����Ƿ����߼���
        * Ҳ�����Ȱ������ų�[[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]
        * Ȼ������һ��list����,ͨ�����ϵؽ���Ӧ���˲嵽��Ӧ��λ��(һ����ȡ��ǰ����źõ�˳��������ϸ��)
        ����[7,0]��[[7,0]]
        ����[7,1]��[[7,0],[7,1]]        ˵��:��ʱ[7,0]��[7,1]��������������,��������а����˲����,Ҳ����Ӱ��(�Ѿ�����ǰ��ֻ��0��/1�������ߵ���)
        ����[6,1]��[[7,0],[6,1],[7,1]]
        ����[5,0]��[[5,0],[7,0],[6,1],[7,1]]
        ����[5,2]��[[5,0],[7,0],[5,2],[6,1],[7,1]]
        ����[4,4]��[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
        */
        sort(people.begin(), people.end(), compare);//������
        list<vector<int>> sortedList;
        for (auto temp : people) {
            int count = temp[1];
            list<vector<int>>::iterator it = sortedList.begin();
            while (count > 0) {
                it++;
                count--;
            }
            sortedList.insert(it, temp);//����
        }
        vector<vector<int>> result(sortedList.begin(), sortedList.end());
        return result;
    }
};

