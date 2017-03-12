/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 21:44:04
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& nums) {
        /// write your code here
        int N = nums.size();
        int l = 0;
        int r = N - 1;
        int max_area = 0;
        while (l < r) {
            
            int w = r - l;
            int h = (nums[l] < nums[r] ? nums[l++] : nums[r--]);
            max_area = max(max_area, w * h);
            while (l < r && nums[l] <= h) {
                ++l;
            }
            while (l < r && nums[r] <= h) {
                --r;
            }
        }
        return max_area;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.maxArea(v) << endl;
    return 0;
}
 














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
