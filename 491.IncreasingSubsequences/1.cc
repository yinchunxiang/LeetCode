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

using namespace std;
 
class Solution {
    public:
        void dfs(vector<vector<int>>& result, vector<int> path, vector<int>& nums, int index) {
            for (int i = index + 1; i < nums.size(); ++i) {
                if (i > index + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                path.push_back(nums[i]);
                if (path.size() >= 2) {
                    result.push_back(path);
                }
                dfs(result, path, nums, i);
                path.pop_back();
            }
        }
        
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            vector<vector<int>> result;
            for (int i = 0; i < nums.size() - 1; ++i) {
                if ( i > 0 && nums[i] == nums[i - 1] ) {
                    continue;
                }
                vector<int> path(1, nums[i]);
                dfs(result, path, nums, i);
            }
            return result;
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
