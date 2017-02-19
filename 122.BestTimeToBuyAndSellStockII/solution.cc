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
            int start = 0;
            int end = start + 1;
            for (; end < n; ++end) {
                if (prices[end] < prices[end - 1]) {
                    if (end - 1 - start > 0) {
                        max_profile += prices[end -1] - prices[start];
                    }
                    start = end;
                }
            }
            if (end - 1 - start > 0) {
                max_profile += prices[end -1] - prices[start];
            }
            return max_profile;

        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
