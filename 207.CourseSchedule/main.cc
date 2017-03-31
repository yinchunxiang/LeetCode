/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/30 20:53:32
 * @brief 
 * 
 **/ 
#include <iostream>	
#include <vector>
#include <unordered_set>

using namespace std;
 
class Solution {
public:
    bool has_loop(vector<unordered_set<int>>& v, int index, unordered_set<int>& path) {
        if (index < noloop_count_) {
            return false;
        }
        auto it = path.find(index);
        if (path.end() != it) {
            return true;
        }
        if (v[index].size() <= 0) {
            return false;
        }
        path.insert(index);
        for (auto i : v[index]) {
            if (has_loop(v, i, path)) {
                return true;
            }
        }
        return false;
        
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 1) {
            return true;
        }
        vector<unordered_set<int>> prereq(numCourses, unordered_set<int>());
        for (auto &p : prerequisites) {
            prereq[p.first].insert(p.second);
        }
        for (int i = 0; i < numCourses; ++i) {
            unordered_set<int> path;
            if (has_loop(prereq, i, path)) {
                return false;
            }
            noloop_count_ ++;
        }
        return true;
    }
    int noloop_count_;


};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
