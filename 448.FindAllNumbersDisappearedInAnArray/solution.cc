/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 20:15:55
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            int N = nums.size();
            for (int i = 0; i < N; ++i) {
                int target = abs(nums[i]) - 1;
                if (nums[target] > 0) {
                    nums[target] = -nums[target];
                }
            }
            vector<int> result;
            for (int i = 0; i < N; ++i) {
                if (nums[i] > 0) {
                    result.push_back(i + 1);
                }

            }
            return result;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
