/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/11 17:27:53
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int N = nums.size();
            int k %= N;
            if (0 == k) return;
            int start = N - k;
            vecotr<int> cp = nums;
            for (int i = 0; i < N; ++i) {
                nums[i] = cp[start];
                start = (start + 1) % N;
            }
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
