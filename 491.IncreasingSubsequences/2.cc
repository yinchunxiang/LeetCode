/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/03 15:12:59
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>
#include <set>

using namespace std;
 
class Solution {
    public:
        void dfs(set<vector<int>>& result, vector<int> &path, vector<int>& nums, int index) {
            for (int i = index ; i < nums.size(); ++i) {
                if (i > index && nums[i] == nums[i - 1]) {
                    continue;
                }
                if (!path.empty() && path.back() > nums[i]) {
                    continue;
                }
                path.push_back(nums[i]);
                if (path.size() >= 2) {
                    result.insert(path);
                }
                dfs(result, path, nums, i + 1);
                path.pop_back();
            }
        }
        
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            set<vector<int>> result;
            vector<int> path;
            dfs(result, path, nums, 0);
            return vector<vector<int>>(result.begin(), result.end());
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {4, 6, 7, 7};
        vector<vector<int>> result = s.findSubsequences(input);
        cout << "{" << endl;
        for (auto& v : result) {
            cout << "{ ";
            for (auto num : v) {
                cout << num << " ";
            }
            cout <<" }" << endl;
        }
        cout << "}" << endl;

    }
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
