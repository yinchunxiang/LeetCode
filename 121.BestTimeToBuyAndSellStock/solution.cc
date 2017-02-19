/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/18 17:09:42
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profile = 0;
            int n = prices.size();
            if (n <= 1) {
                return max_profile;
            }
            int next_max = prices[n - 1];
            for (int i = n - 2; i >= 0; --i) {
                max_profile = max(max_profile, next_max - prices[i]);
                next_max = max(next_max, prices[i]);
            }
            return max_profile;
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
