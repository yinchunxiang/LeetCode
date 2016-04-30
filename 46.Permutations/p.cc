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
#include <utility> // swap

using namespace std;
 
class Solution {
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(result, nums, 0);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            swap(nums[index], nums[i]);
            dfs(result, nums, index + 1);
            swap(nums[index], nums[i]);
        }
        return;
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
