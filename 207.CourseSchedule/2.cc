/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 2.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 16:00:40
 * @brief 
 * 
 **/ 
 
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int, unordered_set<int>> graph(numCourses, unordered_set<int>());
    vector<int> indegree(numCourses, 0);
    for (auto &p : prerequisites) {
        graph[p.second].insert(p.first);
        indegree[p.first] += 1;
    }
    for (int i = 0; i < numCourses; ++i) {
        int j = 0;
        for (; j < numCourses; ++j) {
            // 判断有没有入度为0的
            if (!indegree[j]) break;
        }
        if (j == numCourses) return false;
        indegree[j] = -1;
        for (int to : graph[j]) {
            indegree[to] --;
        }
    }
    return true;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
