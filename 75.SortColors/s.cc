/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/05/01 00:57:25
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::placeholders;   

class Solution {
public:
    void sortColors(vector<int>& nums) {
        partition(
                partition(nums.begin(), nums.end(), [](int i){ return i == 0;}), 
                nums.end(), 
                [](int i){ return i == 1; });
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
