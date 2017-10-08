/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/23 17:53:27
 * @brief 
 * 
 **/ 
 

class Solution {
public:
    bool judgePoint24(vector<double>& v) {
        int size = nums.size();
        if (0 == size) return false;
        if (1 == size) {
            return abs(24 - nums[0]) < 0.001;
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == j)  continue;
                vector<double> v;
                for (int m = 0; m < size; ++m) {
                    if (m != i && m != j) {
                        v.push_back(nums[m]);
                    }
                }
                for (int k = 0; k < 4; ++k) {
                    if (k < 2 && i < j) continue;
                    if (0 == k) {
                        v.push_back(nums[i] + nums[j]);
                    }
                    if (1 == k) {
                        v.push_back(num[i] * nums[j]);
                    }
                    if (2 == k) {
                        v.push_back(num[i] - nums[j]);
                    }
                    if (3 == k) {
                        if (0 == nums[j])  continue;
                        v.push_back(nums[i] / num[j]);
                    }
                    if (judgePoint24(v)) {
                        return true;
                    }
                    v.pop_back();
                }

            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double> v;
        for (auto num : nums) {
            v.push_back(double(num));
        }
        return judgePoint24(v);
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
