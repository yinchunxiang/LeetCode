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
    bool 


    bool judgePoint24(vector<int>& nums) {
        if (nums.size() == 1) {
            return abs(nums[i] - 24) <= 0.001;
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                vector<int> temp;
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j) {
                        temp.push_back(nums[k]);
                    }
                }
                for (int m = 0; m < 6; ++m) {
                    vector<int> result(temp);
                    //+
                    if (0 == m) {
                        result.push_back(nums[i] + nums[j]);
                        if (judgePoint24(result)) {
                            return true;
                        }
                    }
                    if (1 == m) {
                        result.push_back(nums[i] * nums[j]);
                        if (judgePoint24(result)) {
                            return true;
                        }
                    }
                    if (2 == m) {
                        result.push_back(nums[i] - nums[j]);
                        if (judgePoint24(result)) {
                            return true;
                        }
                    }
                    if (3 == m) {
                        result.push_back(num[j] - nums[i]);
                        if (judgePoint24(result)) {
                            return true;
                        }
                    }
                    if (4 == m) {
                        result.push_back(num[i] / nums[j]);
                        if (judgePoint24(result)) {
                            return true;
                        }
                    }
                    if (5 == m) {
                        result.push_back(num[j] / nums[i]);
                        if (judgePoint24(result)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
        
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
