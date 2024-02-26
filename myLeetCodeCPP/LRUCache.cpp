#include "LRUCache.h"
int LRUCache::get(int key) {
	int result = -1;
	//ȡ��ĳ��key��Ӧ��value��key�����ڵĻ��򷵻�-1��
	if (cacheMap.find(key) != cacheMap.end()) {
		//�ҵ���
		pair<int, int> kv = *cacheMap[key];//�õ������ж�Ӧ�ļ�ֵ��
		result = kv.second;//�õ������Ҳ����key��Ӧ��value
		//����ǰ�ļ�ֵ���Ƶ�list��front
		cache.erase(cacheMap[key]);
		cache.push_front(kv);
		//����map��key��Ӧ��list�е�ָ��
		cacheMap[key] = cache.begin();

		return result;
	}
	//û�ҵ���Ӧ�ģ�ֱ��return -1
	return result;
}
void LRUCache::put(int key, int value) {
	//1.���key��map���Ƿ����
	if (cacheMap.find(key) == cacheMap.end()) {
		//�����ڣ������¼�ֵ��
		if (usedCap == capacity) {
			//cache���ˣ�ɾ��βԪ��
			pair<int, int> lastPair = cache.back();
			cache.pop_back();//��cache��ɾ��
			cacheMap.erase(lastPair.first);//��map��ɾ��
			usedCap--;
		}
		cache.push_front(pair<int, int>(key, value));//��cache�м����µļ�ֵ��
		cacheMap[key] = cache.begin();//��map�������Ԫ��
	}
	else {
		//���ڣ����޸ļ�ֵ��
		pair<int, int> kv = *cacheMap[key];
		cache.erase(cacheMap[key]);//ɾ��ԭ�еĻ���
		kv.second = value;//����ֵ
		cache.push_front(kv);//����cache��front
		cacheMap[key] = cache.begin();//����map
	}

	usedCap++;
}
void LRUCache::test_LRUCache() {

}
