#pragma once
#include "header.h"
class EvaluateDivision
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        /*第399题:除法求值
        * 图论:(如a/b=2, b/c=3)
        *     第一个方向正序方向,用a->b来代表除,权值为2,那么有 "a"-2->"b"-3->"c"
        *     第二个方向是倒序方向,也就是反过来b/a=1/2,那么有 "c"-1/3->"b"-1/2->"a"
        *     那么如果我们要找到a/c的值,就可以遍历起点a对应的所有子节点,逐层遍历发现b的子节点有c,将权值乘积起来得 a/c=2*3
        * 如何存储图?
        *     我们之前用的是二维数组,每一行都代表对应index下的所有子节点,但是这里的key为string类型,不能用index表示了
        *     什么可以用string当下标呢?可以自然想到哈希表,map["b"] = ["c":3, "a":1/2],所以哈希表的value也是一个哈希表,因此是二维哈希表,map["a"]["c"]=3
        * 如何实现广搜来获得正确的权值?
        *     广搜都是用一个先进先出的queue来实现的,那么通过先计算同一层的结果,同时同步将同一层每个元素的子集不断push进队列(后进后出,所以肯定是当前层先遍历完的)
        *     那么每个push进的值就要对应带着从起点到该点的权重累积值,所以每个节点如队列时用一个pair入队列,value代表权值,需要乘上它的上一层节点对应的权重累积值
        *     最后当找到问题中的终点字符串的时候就可以停下了
        *     由于是通过广搜,从最高层开始计算,一层一层算下来的,所以得到的结果肯定是深度最浅的结果(需要经过的节点数最少)
        * 如何优化?
        *     由于对于同一个字符串,可能前面几层也包含过该字符串,也就是说这个分支前面的节点也会搜索,所以可以通过一个visited记录搜索过的,减少计算量
        * 总结图论要素:用二维容器抽象化表示图->用queue队列单层展开,并逐步将每个节点下一层的所有子节点逐步push进队列尾->用visited存储已经搜索过的分支
        */
        unordered_map<string, unordered_map<string, double>> equal_map;
        int n = equations.size();
        //1. 抽象化存储有向图
        for (int i = 0; i < n; i++){
            string startNode = equations[i][0], endNode = equations[i][1];//将equations[i][0]->equations[i][1]存入(正向和方向均存入)
            equal_map[startNode][endNode] = values[i];//正向
            equal_map[endNode][startNode] = 1.0 / values[i];//反向
            equal_map[startNode][startNode] = 1.0;
            equal_map[endNode][endNode] = 1.0;
        }
        //2. 用queue实现广搜,队列是pair<string, double>类型,存储到当前string所需要的总权重积
        vector<double> result(queries.size(), -1.0);//存储结果,用1.0初始化,也就是先默认全都找不到到达终点的路线
        for(int i = 0; i < queries.size(); i++){
            queue<pair<string, double>> que;
            string startNode = queries[i][0], endNode = queries[i][1];//取出问题要求的起点和终点
            // if(startNode == endNode && equal_map.find(startNode)!=equal_map.end()) {
            //     //处理["a", "a"]这类问题
            //     result[i] = 1.0;
            //     continue;
            // }
            que.emplace(startNode, 1.0);//emplace可以直接构造元素并插入到队列中，而无需显式地创建一个临时对象,乘积累计器从1开始
            unordered_set<string> visited;//用于存储已经遍历过的值,前面层遍历过了后面层就不需要遍历了
            visited.insert(startNode);
            while(!que.empty()){
                string node = que.front().first;//取出当前要处理的节点
                double weight = que.front().second;
                que.pop();
                //实现广搜
                // 存入当前将要处理的节点对应的全部子节点到队列尾,的,等待处理
                for(auto it = equal_map[node].begin(); it!=equal_map[node].end(); it++){
                    pair<string, double> temp = *it;
                    string nextNode = temp.first; double nextWeight = temp.second;
                    if(nextNode == endNode){
                        result[i] = weight*nextWeight;
                        break;//找到了,退出while
                    }else if(visited.find(nextNode)==visited.end()){
                        //不相等的话说明还要入队列继续搜索
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

