/****************************************************************************
 * 
 * Copyright (C) 2016 Baidu.com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file ss.cc
 * @author yinchunxiang(com@baidu.com)
 * @date 2016/04/16 21:51:02
 * @brief 
 * 
 **/ 
 
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            //vector<vector<int>> result(2 << nums.size());
            vector<vector<int>> result(1);
            result.reserve(2 << nums.size());
            for (auto& num : nums) {
                auto half = result.begin() + result.size();
                copy(result.begin(), result.end(), back_inserter(result));
                for (auto it = half; it != result.end(); ++it) {
                    it->push_back(num);
                }
            }

            return result;
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
    Solution s;
    vector<int> v = {1, 2, 3};
    auto result = s.subsets(v);
    for (auto& v : result) {
        printv(v);
    }
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
