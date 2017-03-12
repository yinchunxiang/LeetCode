/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/11 22:55:59
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int r = numbers.size() - 1;
            int l = 0;
            vector<int> result;
            while (l < r) {
                int sum = numbers[l] + numbers[r];
                if (sum == target) {
                    result.push_back(l);
                    result.push_back(r);
                }else if (sum < target) {
                    ++l;
                }else {
                    --r;
                }
            }
            return result;
                    
        }
};












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
