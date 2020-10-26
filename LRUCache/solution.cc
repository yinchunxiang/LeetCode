#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;


class LRUCache{
public:
    LRUCache(int capacity) : capacity_(capacity){
    }
    
    int get(int key) {
      auto it = map_.find(key);
      // do not find
      if (map_.end() == it) return -1;
      // 返回值
      auto value = it->second->second;
      // 将该kv所在位置调整到list的头部
      list_.splice(list_.begin(), list_, it->second);
      // 删除之后list的迭代器就失效了，索引要更新map里面的迭代器
      map_[key] = list_.begin();
      return value;
    }
    
    void put(int key, int value) {
      auto it = map_.find(key);
      // find it
      if (map_.end() != it) {
        // update value
        it->second->second = value;
        // move to head
        list_.splice(list_.begin(), list_, it->second);
        // update map
        map_[key] = list_.begin();
        return;
      }

      if (list_.size() >= capacity_) {
        // capacity is not enough
        const auto& key = list_.back().first;
        list_.pop_back();
        map_.erase(key);
      }
      list_.emplace_front(key, value);
      map_[key] = list_.begin();
    }

 private:
  int capacity_;
  // key => list::iterator
  std::unordered_map<int, std::list<pair<int,int>>::iterator> map_;
  // KeyValueList
  std::list<pair<int, int>> list_;

};

int main() {
  return 0;
}
