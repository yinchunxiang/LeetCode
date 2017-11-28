/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/19 12:50:09
 * @brief 
 * 
 **/

#include <vector>

using namespace std;
 
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            if (n < 2) {
                return 0;
            }

            vector<int> left(n, 0);
            int left_min = prices[0];
            for (int i = 1; i < n; ++i) {
                left_min = min(left_min, prices[i]);
                left[i] = max(left[i - 1], prices[i] - left_min);
            }

            vector<int> right(n, 0);
            int right_max = prices[n - 1];
            for (int i = n - 2; i >= 0; --i) {
                right_max = max(right_max, prices[i]);
                right[i] = max(right[i + 1], right_max - prices[i]);
            }

            int max_profile = 0;
            for (int i = 0; i < n; ++i) {
                max_profile = max(max_profile, left[i] + right[i]);
            }
            return max_profile;
            
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
