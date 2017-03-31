/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/27 21:50:29
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
 
class Solution {
    public:
        
        vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
            if (1 == n) {
                return vector<int>(1, 0);
            }
            vector<unordered_set<int>> graph(n, unordered_set<int>());
            //create adjacency list 
            for (auto &p : edges) {
                graph[p.first].insert(p.second);
                graph[p.second].insert(p.first);
            }
            vector<int> cur_leaves;
            vector<int> next_leaves;
            for (int i = 0; i < n; ++i) {
                if (graph[i].size() == 1) {
                    cur_leaves.push_back(i);
                }
            }
            while (!cur_leaves.empty()) {
                for (auto i : cur_leaves) {
                    auto s = graph[i];
                    for (auto ss : s) {
                        graph[ss].erase(i);
                        if (graph[ss].size() == 1) {
                            next_leaves.push_back(ss);
                        }
                    }
                }
                if (next_leaves.empty()) {
                    return cur_leaves;
                }
                cur_leaves.clear();
                cur_leaves.swap(next);
            }
                    
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
