/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/15 00:20:10
 * @brief 
 * 
 **/

using namespace std;

#include <vector>
#include <numeric>

class Solution {
    public:
        bool isValidSplit(vector<int> &nums, int m, int sum) {
            // count the minimum number of split
            int count = 1;
            // prev sum
            long prev = 0;
            // loop invariant: prev = 0, count = minimum splits so far
            for (auto num : nums) {
                if(num > sum) return false;
                prev += num;
                if (prev > sum) {
                    prev = num;
                    count++;
                    if(count > m) return false;
                }
            }
            return true;
        }

        int splitArray(vector<int>& nums, int m) {
            long right = accumulate((nums.begin(), nums.end(), (long)0);
            long left = *max_element(nums.begin(), nums.end());
            while (left < right) {
                long mid = left + (right - left)/2;
                bool valid = isValidSplit(nums, m, mid);
                if (valid) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
