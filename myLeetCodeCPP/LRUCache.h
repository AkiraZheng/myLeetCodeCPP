#pragma once
#include "header.h"
class LRUCache
{
private:
    int capacity;//cache�����洢����
    int usedCap = 0;
    list<pair<int, int>> cache;//˫������ɾ�������õĵ�͸������·��ʵĵ�
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
public:
    LRUCache(int capacity) :capacity(capacity) {};//���캯������ʼ��cache��С
    int get(int key);
    void put(int key, int value);
	static void test_LRUCache();
};

