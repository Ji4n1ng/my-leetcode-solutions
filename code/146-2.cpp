#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

// 我考虑过用链表实现，但是删除节点太麻烦了，所以也考虑过双向链表，但是不太熟就没用。

// 答案用的双向链表。而且用哈希表来保存每个节点的地址，可以保证在 O(1) 时间内查找节点。这个厉害。
// 双向链表插入和删除效率高，单向链表插入和删除时，还要查找节点的前驱节点。
// 越靠近链表头部，表示节点上次访问距离现在时间最短。
// get，节点交换到链表头部，同时更新hash表中的该节点的地址。

// 学会这个 list 的 splice 用法，他没有自己定义双向链表。
class LRUCache {
private:
struct CacheNode {
	int key;
	int value;
	CacheNode(int k, int v) :key(k), value(v){}
};
public:
	LRUCache(int capacity) {
		this->capacity = capacity;
	}
	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end()) return -1;
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;
	}
	void put(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end()) {
			if (cacheList.size() == capacity) {
				cacheMap.erase(cacheList.back().key);
				cacheList.pop_back();
			}
			cacheList.push_front(CacheNode(key, value));
			cacheMap[key] = cacheList.begin();
		} else {
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}
private:
	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap;
	int capacity;
};
