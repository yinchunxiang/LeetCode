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
        if (numCourses < 1) {
            return {};
        }
        vector<unordered_set<int>> matrix(numCourses, unordered_set<int>());
        vector<int> indegree(numCourses, 0);
        for (auto &p : prerequisites) {
            matrix[p.second].insert(p.first);
            ++indegree[p.first];
        }
        vector<int> result;
        queue<int> zeros;
        for (int i = 0; i < numCourses; ++i)  {
            if (indegree[i] == 0) {
                zeros.push(i);
            }
        }
        for (int i = 0; i < numCourses; ++i)  {
            if (zeros.empty()) {
                return {};
            }
            auto zero = zeros.front();
            zeros.pop();
            result.push_back(zero);
            for (auto next : matrix[zero]) {
                if (0 == --indegree[next]) {
                    zeros.push(next);
                }
            }
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
