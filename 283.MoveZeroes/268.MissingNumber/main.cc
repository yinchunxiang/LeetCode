/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 22:59:25
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int N = nums.size();
            if (N <= 0) {
                return 0;
            }
            int real_sum = accumulate(nums.begin(), nums.end(), 0);
            int expect_sum = (1 + nums[N - 1]) * N/2;
            return expect_sum - real_sum;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
