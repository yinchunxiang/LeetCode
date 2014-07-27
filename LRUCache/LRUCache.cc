#include <isotream>
#include <tr1/unordered_map>
#include <list>

using namespace std;
typedef pair<int, int>  IntPair
typedef list< IntPair > IntPairList;
typedef std::tr1::unordered_map<int, IntPairList::iterator> IntPairMap;


class LRUCache{
public:
    LRUCache(int capacity) : limit_(capacity){
        
    }
    
    int get(int key) {
        IntPairMap::iterator it = map_.find(key);
        if( map_.end() == it) {
            return -1;
        }
        int ret = it->second->second;
        list_.splice(list_.begin(), list_, map_[key]);
        map_[key] = list_.begin();
        return ret;
    }
    
    void set(int key, int value) {
        IntPairMap::iterator it = map_.find(key);
        if( map_.end() == it) {
            if (list_.size() >= limit_) {
                const int& key = list_.back().first;
                map_.erase(list_.back().first);
                list_.pop_back();
            }
            list_.push_front(pair<int, int>(key, value));
            map_[key] = list_.begin();
        }
        else {
            it->second->second = value;
            list_.splice(list_.begin(), list_, map_[key]);
            map_[key] = list_.begin();
        }
    }

private:
    int limit_;
    IntPairMap map_;
    IntPairList list_;

};

int main() {
}
