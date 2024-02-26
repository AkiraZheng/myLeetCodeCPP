#pragma once
#include "header.h"
class LRUCache
{
private:
    int capacity;//cache的最大存储容量
    int usedCap = 0;
    list<pair<int, int>> cache;//双链表方便删除最闲置的点和更改最新访问的点
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
public:
    LRUCache(int capacity) :capacity(capacity) {};//构造函数，初始化cache大小
    int get(int key);
    void put(int key, int value);
	static void test_LRUCache();
};

