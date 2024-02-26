#include "LRUCache.h"
int LRUCache::get(int key) {
	int result = -1;
	//取出某个key对应的value（key不存在的话则返回-1）
	if (cacheMap.find(key) != cacheMap.end()) {
		//找到了
		pair<int, int> kv = *cacheMap[key];//拿到链表中对应的键值对
		result = kv.second;//拿到结果，也就是key对应的value
		//将当前的键值对移到list的front
		cache.erase(cacheMap[key]);
		cache.push_front(kv);
		//更新map中key对应的list中的指针
		cacheMap[key] = cache.begin();

		return result;
	}
	//没找到对应的，直接return -1
	return result;
}
void LRUCache::put(int key, int value) {
	//1.检查key在map中是否存在
	if (cacheMap.find(key) == cacheMap.end()) {
		//不存在：插入新键值对
		if (usedCap == capacity) {
			//cache满了，删掉尾元素
			pair<int, int> lastPair = cache.back();
			cache.pop_back();//在cache中删除
			cacheMap.erase(lastPair.first);//在map中删除
			usedCap--;
		}
		cache.push_front(pair<int, int>(key, value));//在cache中加入新的键值对
		cacheMap[key] = cache.begin();//在map中添加新元素
	}
	else {
		//存在，则修改键值对
		pair<int, int> kv = *cacheMap[key];
		cache.erase(cacheMap[key]);//删掉原有的缓存
		kv.second = value;//更新值
		cache.push_front(kv);//放在cache的front
		cacheMap[key] = cache.begin();//更新map
	}

	usedCap++;
}
void LRUCache::test_LRUCache() {

}
