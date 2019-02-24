#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

// 我是用 unordered_map 来记录 key，value 的对应关系，
// vector 来记录顺序，头上的元素是最不常用的元素。每次查询，或者修改，将该元素从vector删除，添加到最后。
// cap 代表最大容量，current 代表当前的容量
class LRUCache {
  int cap;
  int current;
  unordered_map<int, int> map;
  vector<int> order;

public:
  LRUCache(int capacity) {
    cap = capacity;
    current = 0;
  }
  
  int get(int key) {
  	if (cap <= 0)
  		return -1;
  	if (map.find(key) == map.end())
  		return -1;
  	reorder(key);
  	return map[key];
  }
  
  void put(int key, int value) {
		if (cap <= 0)
			return;
		if (map.find(key) == map.end()) {
			if (current == cap) {
				vector<int>::iterator it = order.begin();
				map.erase(*it);
				order.erase(it);
				current--;
			}
			order.push_back(key);
			map[key] = value;
			current++;
		} else {
			map[key] = value;
			reorder(key);
		}
  }

private:
	void reorder(int key) {
		vector<int>::iterator it;
		for (it = order.begin(); it != order.end(); it++) {
			if (*it == key)
				break;
		}
		order.erase(it);
		order.push_back(key);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main() {
  LRUCache *cache = new LRUCache(2);
  cache->put(1, 1);
  cache->put(2, 2);
  cout << cache->get(1) << endl;       // returns 1
  cache->put(3, 3);    // evicts key 2
	cout << cache->get(2) << endl;       // returns -1 (not found)
  cache->put(4, 4);    // evicts key 1
	cout << cache->get(1) << endl;       // returns -1 (not found)
	cout << cache->get(3) << endl;       // returns 3
	cout << cache->get(4) << endl;       // returns 4
}