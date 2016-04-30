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
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /// write your code here
        int n = nums.size();
        if (n <= 0) return;
        int next_red = 0; 
        int next_blue = n - 1;
        ///
        for (int i = 0; i < next_blue + 1; ++i) {
            if (0 == nums[i]) {
                swap(nums[next_red++], nums[i]);
            } else if (2 == nums[i]){
                swap(nums[next_blue--], nums[i]);
            } 
        }
        return;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
