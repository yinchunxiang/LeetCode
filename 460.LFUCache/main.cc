//
// Created by yinchunxiang on 2018/8/30.
//

#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LFUCache {
 public:
  struct Item {
    int key;
    int val;
    int freq;
    Item(int k, int v) : key(k), val(v), freq(1) {
    }
  };

  LFUCache(int capacity) : capacity_(capacity){
  }

  int get(int key) {
    auto it = key_map_.find(key);
    if (key_map_.end() == it) return -1;
    // find it
    auto old_freq = it->second->freq;
    auto new_freq = ++(it->second->freq);

    auto& old_list = freq_map_[old_freq];
    auto& new_list = freq_map_[new_freq];
    new_list.splice(new_list.begin(), old_list, it->second);
    if (old_list.empty() && old_freq == min_freq_) {
      min_freq_ = new_freq;
    }
    // update iterator
    key_map_[key] = new_list.begin();
    return it->second->val;
  }

  void put(int key, int value) {
    if (capacity_ <= 0) return;
    auto key_map_it = key_map_.find(key);
    if (key_map_.end() != key_map_it) {
      // find it
      key_map_it->second->val = value;
      auto old_freq = key_map_it->second->freq;
      auto new_freq = ++(key_map_it->second->freq);

      auto& old_list = freq_map_[old_freq];
      auto& new_list = freq_map_[new_freq];
      new_list.splice(new_list.begin(), old_list, key_map_it->second);
      if (old_list.empty() && old_freq == min_freq_) {
        min_freq_ = new_freq;
      }
      key_map_[key] = new_list.begin();
      return;
    }
    if (key_map_.size() >= capacity_) {
      // delete min_freq last value
      auto& min_freq_list = freq_map_[min_freq_];
      auto old_key = min_freq_list.back().key;
      min_freq_list.pop_back();
      key_map_.erase(old_key);
    }
    auto& new_list = freq_map_[1];
    new_list.emplace_front(key, value);
    key_map_[key] = new_list.begin();
    min_freq_ = 1;
  }

 private:
  int capacity_;
  int min_freq_ = std::numeric_limits<int>::max();
  unordered_map<int, list<Item>> freq_map_;
  unordered_map<int, list<Item>::iterator> key_map_;
};

int main(int argc, const char *argv[]) {
  cout << "460.main" << endl;
  LFUCache lfuCache(10);
  cout << "0 => " << lfuCache.get(0) << endl;
  lfuCache.put(0, 0);
  cout << "0 => " << lfuCache.get(0) << endl;

  return 0;
}
