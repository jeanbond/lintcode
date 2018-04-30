
using namespace std;

#include<iostream>
#include<map>
#include<string>
#include<time.h>

/* 数据结构可以使用struct和class */
typedef struct tag_01 {
	unsigned int usedCnt;
	long recentUsedTime;
	int data;

	/*使用map的自定义k-v必须修改比较函数，因为map使用的是红黑树，每次变动元素的时候都要进行比较 */
	bool operator < (struct tag_01 &k1) {
		return (this->data < k1.data) ? true : false;
	}
}Node;


class LFUCache {
private:
	map<int, Node> cache;
	unsigned int capacity;
	unsigned int used;

public:
	long getCurrentNanotime() {
		clock_t now = clock();
		return now;
	}
	/*
	* @param capacity: An integer
	*/LFUCache(int capacity) {
	this->capacity = capacity;
	this->used = 0;
}

	  /*
	  * @param key: An integer
	  * @param value: An integer
	  * @return: nothing
	  */
	  void set(int key, int value) {
		  if (this->capacity < 1) { return; }

		  map<int, Node>::iterator fi = this->cache.find(key);
		  if (fi != this->cache.end())
		  {
			  fi->second.data = value;
			  fi->second.recentUsedTime = this->getCurrentNanotime();
			  fi->second.usedCnt++;
			  return;
		  }else{ 
			  Node ns;
			  ns.data = value;
			  ns.recentUsedTime = this->getCurrentNanotime();
			  ns.usedCnt = 0;
			  if (this->used < this->capacity) {
				  this->used++;
				  this->cache.insert(std::pair<int, Node>(key, ns));
				  return;
			  }
			  else {
				  this->RemoveOne();
				  this->cache.insert(std::pair<int, Node>(key, ns));
				  return;
			  }
		  }
	  }
	  int RemoveOne() {
		  int minUsedCnt = 0xffffffff;
		  long minTime = getCurrentNanotime();
		  int removeKey;
		  map<int, Node>::iterator it = cache.begin();
		  while (it != cache.end()) {
			  if ((it->second.usedCnt < (unsigned int)minUsedCnt) ||
				  (it->second.usedCnt == (unsigned int)minUsedCnt && it->second.recentUsedTime < minTime)) {
				  removeKey = it->first;
				  minUsedCnt = it->second.usedCnt;
				  minTime = it->second.recentUsedTime;
			  }
			  it++;
		  }
		  this->cache.erase(removeKey);
		  return 0;
	  }
	  /*
	  * @param key: An integer
	  * @return: An integer
	  */
	  int get(int key) {
		  map<int,Node>::iterator ds = cache.find(key);
		  if (ds == cache.end()) { cout << "-1  "; return -1; }

		  ds->second.usedCnt++;
		  ds->second.recentUsedTime = this->getCurrentNanotime();
		  cout<< ds->second.data<< "  ";
		  return ds->second.data;
	  }
};


int main() {
	LFUCache lfu = LFUCache(10);
	lfu.set(7, 28);
	lfu.set(7, 1);
	lfu.set(8, 15);
	lfu.get(6);
	lfu.set(10, 27);
	lfu.set(8, 10);
	lfu.get(8);
	lfu.set(6, 29);
	lfu.set(1, 9);
	lfu.get(6);
	lfu.set(10, 7);
	lfu.get(1);
	lfu.get(2);
	lfu.get(13);
	lfu.set(8, 30);
	lfu.set(1, 5);
	lfu.get(1);
	lfu.set(13, 2);
	lfu.get(12);
	system("pause");
	return 0;
}