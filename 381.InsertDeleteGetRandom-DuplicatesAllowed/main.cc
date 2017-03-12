/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/11 23:07:50
 * @brief 
 * 
 **/ 
 
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        auto p = set_.insert(val);
        if (p.second) {
            its_.push_back(p.first);
        }
        return p.second
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = set_.find(val);
        if (set_.end() == it) {
            return false;
        }
        swap(*it, *its_.back());
        set_.erase(its_.back());
        its_.pop_back();
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return *its_[rand() % its_.size()];
    }
private:
    unordered_set<int> set_;
    vector<unordered_set<int>::iterator> its_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
