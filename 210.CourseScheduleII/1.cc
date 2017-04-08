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
#include <queue>

using namespace std;
 
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> result;
        vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
        vector<int> indegree(numCourses, 0);
        for (auto &p : prerequisites) {
            graph[p.second].insert(p.first);
            indegree[p.first] += 1;
        }
        bool found = true;
        for (int i = 0; i < numCourses; ++i) {
            int j = 0;
            for (; j < numCourses; ++j) {
                if (!indegree[j]) break;
            }
            if (j == numCourses) {
                found = false;
                break;
            }
            indegree[j] = -1;
            result.push_back(j);
            for (auto to : graph[j]) {
                indegree[to] --;
            }
        }
        if (!found) {
            return vector<int>();
        }
        return result;
    }

};

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    Solution s;
    {
        //[[1,0],[2,0],[3,1],[3,2]]
        vector<pair<int, int>> input;
        input.push_back(pair<int, int>(1, 0));
        input.push_back(pair<int, int>(2, 0));
        input.push_back(pair<int, int>(3, 1));
        input.push_back(pair<int, int>(3, 2));
        auto v = s.findOrder(4, input);
        printv(v);

    }
    
    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
