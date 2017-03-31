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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses <= 1) {
            return true;
        }
        vector<unordered_set<int>> matrix;
        vector<int> indegree(numCourses, 0);
        for (auto &p : prerequisites) {
            matrix[p.second].insert(p.first);
            indegree[p.first] += 1;
        }
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses && indegree[j] > 0; ++j);
            if (j == numCourses) {
                return false;
            }
            for (auto prevs : matrix[j]) {
                --indegree[prevs];
            }
        }
        return true;
    }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
