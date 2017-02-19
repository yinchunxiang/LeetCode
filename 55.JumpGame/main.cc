/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/18 14:53:58
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int reach = 0;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                reach = max(reach, i + nums[i]);
                if (reach >= n - 1) {
                    return true;
                }
                if (reach < i + 1) {
                    return false;
                }
            }
            return false;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
