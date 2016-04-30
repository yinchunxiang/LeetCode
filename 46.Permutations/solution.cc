/****************************************************************************
 * 
 * Copyright (C) 2016 Baidu.com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(com@baidu.com)
 * @date 2016/04/17 00:31:18
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
 
class Solution {
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        unordered_set<int> used;
        dfs(result, nums, used, sub);
        return result;
    }

    void dfs(vector<vector<int>>& result, const vector<int>& nums, unordered_set<int>& used, vector<int>& sub) {
        if (sub.size() == nums.size()) {
            result.push_back(sub);
            return;
        }
        for (auto& num : nums) {
            auto it = used.find(num);
            if (used.end() != it) {
                continue;
            }
            sub.push_back(num);
            used.emplace(num);
            dfs(result, nums, used, sub);
            sub.pop_back();
            used.erase(num);
        }
    }
};

void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char *argv[])
{
    vector<int> v = {1, 2, 3};
    Solution s;
    auto result = s.permute(v);
    for (auto& v : result) {
        printv(v);
    }
    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
