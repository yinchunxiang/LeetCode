/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 22:55:47
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int N = nums.size();
            int next = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i]) {
                    nums[next++] = nums[i];
                }
            }
            for (int i = next; i < N; ++i) {
                nums[i] = 0;
            }
            return;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
