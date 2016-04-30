/****************************************************************************
 * 
 * Copyright (C) 2016 Baidu.com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(com@baidu.com)
 * @date 2016/04/24 12:44:19
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        /// write your code here
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        dfs(result, nums, 0);
        return result;
    }
    void dfs(vector<vector<int>>& result, vector<int>& nums, int index) {
        if (index >= nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            auto it = find(nums.begin() + index, nums.begin() + i, nums[i]);
            if (it != nums.begin() + i) {
                cout << "find " << nums[i] << endl;
                continue;
            } else {
                cout << "do not find " << nums[i] << endl;
            }
            
            swap(nums[index], nums[i]);
            dfs(result, nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    /*
    void dfs(vector<vector<int>>& result, vector<int>& nums, int index) {
        if (index >= nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            if (i != index && nums[i] == nums[index]) {
                continue;
            }
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = 0; j < index; ++j) {
                cout <<  "\t";
            }
            printf("nums[%d] = %d nums[%d] = %d \n", index, nums[index], i, nums[i]);
            swap(nums[index], nums[i]);
            dfs(result, nums, index + 1);
            //cout << "nums[index] = " << nums[index] << " nums[i] = " << nums[i] << endl;
            for (int j = 0; j < index; ++j) {
                cout <<  "\t";
            }
            printf("nums[%d] = %d nums[%d] = %d \n", index, nums[index], i, nums[i]);
            swap(nums[index], nums[i]);
        }
        return;
    }
    */
};
void printvv(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for(int j = 0; j < vv[i].size(); ++j) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char* argv[]) {
    {
        vector<int> v = {1, 2, 3, 3};
        printv(v);
        Solution s;
        auto result = s.permuteUnique(v);
        printvv(result);
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
