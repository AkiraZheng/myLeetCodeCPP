#pragma once
#include "header.h"
class EvaluateDivision
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        /*��399��:������ֵ
        * ͼ��:(��a/b=2, b/c=3)
        *     ��һ������������,��a->b�������,ȨֵΪ2,��ô�� "a"-2->"b"-3->"c"
        *     �ڶ��������ǵ�����,Ҳ���Ƿ�����b/a=1/2,��ô�� "c"-1/3->"b"-1/2->"a"
        *     ��ô�������Ҫ�ҵ�a/c��ֵ,�Ϳ��Ա������a��Ӧ�������ӽڵ�,����������b���ӽڵ���c,��Ȩֵ�˻������� a/c=2*3
        * ��δ洢ͼ?
        *     ����֮ǰ�õ��Ƕ�ά����,ÿһ�ж������Ӧindex�µ������ӽڵ�,���������keyΪstring����,������index��ʾ��
        *     ʲô������string���±���?������Ȼ�뵽��ϣ��,map["b"] = ["c":3, "a":1/2],���Թ�ϣ���valueҲ��һ����ϣ��,����Ƕ�ά��ϣ��,map["a"]["c"]=3
        * ���ʵ�ֹ����������ȷ��Ȩֵ?
        *     ���Ѷ�����һ���Ƚ��ȳ���queue��ʵ�ֵ�,��ôͨ���ȼ���ͬһ��Ľ��,ͬʱͬ����ͬһ��ÿ��Ԫ�ص��Ӽ�����push������(������,���Կ϶��ǵ�ǰ���ȱ������)
        *     ��ôÿ��push����ֵ��Ҫ��Ӧ���Ŵ���㵽�õ��Ȩ���ۻ�ֵ,����ÿ���ڵ������ʱ��һ��pair�����,value����Ȩֵ,��Ҫ����������һ��ڵ��Ӧ��Ȩ���ۻ�ֵ
        *     ����ҵ������е��յ��ַ�����ʱ��Ϳ���ͣ����
        *     ������ͨ������,����߲㿪ʼ����,һ��һ����������,���Եõ��Ľ���϶��������ǳ�Ľ��(��Ҫ�����Ľڵ�������)
        * ����Ż�?
        *     ���ڶ���ͬһ���ַ���,����ǰ�漸��Ҳ���������ַ���,Ҳ����˵�����֧ǰ��Ľڵ�Ҳ������,���Կ���ͨ��һ��visited��¼��������,���ټ�����
        * �ܽ�ͼ��Ҫ��:�ö�ά�������󻯱�ʾͼ->��queue���е���չ��,���𲽽�ÿ���ڵ���һ��������ӽڵ���push������β->��visited�洢�Ѿ��������ķ�֧
        */
        unordered_map<string, unordered_map<string, double>> equal_map;
        int n = equations.size();
        //1. ���󻯴洢����ͼ
        for (int i = 0; i < n; i++){
            string startNode = equations[i][0], endNode = equations[i][1];//��equations[i][0]->equations[i][1]����(����ͷ��������)
            equal_map[startNode][endNode] = values[i];//����
            equal_map[endNode][startNode] = 1.0 / values[i];//����
            equal_map[startNode][startNode] = 1.0;
            equal_map[endNode][endNode] = 1.0;
        }
        //2. ��queueʵ�ֹ���,������pair<string, double>����,�洢����ǰstring����Ҫ����Ȩ�ػ�
        vector<double> result(queries.size(), -1.0);//�洢���,��1.0��ʼ��,Ҳ������Ĭ��ȫ���Ҳ��������յ��·��
        for(int i = 0; i < queries.size(); i++){
            queue<pair<string, double>> que;
            string startNode = queries[i][0], endNode = queries[i][1];//ȡ������Ҫ��������յ�
            // if(startNode == endNode && equal_map.find(startNode)!=equal_map.end()) {
            //     //����["a", "a"]��������
            //     result[i] = 1.0;
            //     continue;
            // }
            que.emplace(startNode, 1.0);//emplace����ֱ�ӹ���Ԫ�ز����뵽�����У���������ʽ�ش���һ����ʱ����,�˻��ۼ�����1��ʼ
            unordered_set<string> visited;//���ڴ洢�Ѿ���������ֵ,ǰ���������˺����Ͳ���Ҫ������
            visited.insert(startNode);
            while(!que.empty()){
                string node = que.front().first;//ȡ����ǰҪ����Ľڵ�
                double weight = que.front().second;
                que.pop();
                //ʵ�ֹ���
                // ���뵱ǰ��Ҫ����Ľڵ��Ӧ��ȫ���ӽڵ㵽����β,��,�ȴ�����
                for(auto it = equal_map[node].begin(); it!=equal_map[node].end(); it++){
                    pair<string, double> temp = *it;
                    string nextNode = temp.first; double nextWeight = temp.second;
                    if(nextNode == endNode){
                        result[i] = weight*nextWeight;
                        break;//�ҵ���,�˳�while
                    }else if(visited.find(nextNode)==visited.end()){
                        //����ȵĻ�˵����Ҫ����м�������
                        que.emplace(nextNode, weight*nextWeight);
                        visited.insert(nextNode);
                    }
                }
            }
        }
        return result;
    }
    static void test_EvaluateDivision() {
        EvaluateDivision ED;
        vector<vector<string>> equ{ {"a", "b"}, {"b", "c"} };
        vector<double> val{ 2.0, 3.0 };
        vector<vector<string>> que{ {"a","c"} ,{"b","a"},{"a","e"},{"a","a"},{"x","x"} };
        for (auto temp : ED.calcEquation(equ, val, que)) {
            cout << temp << endl;
        }
    }
};

