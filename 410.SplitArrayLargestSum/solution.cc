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

class Solution {
    public:
        bool isValidSplit(vector<int> &nums, int m, int sum) {
            int i = 0, n = nums.length;
            // count the minimum number of split
            int count = 0;
            // prev sum
            long prev = 0;
            // loop invariant: prev = 0, count = minimum splits so far
            while(i < n) {
                if(nums[i] > sum) return false;
                while(i < n && prev + nums[i] <= sum) {
                    prev += nums[i++];
                }
                count++;
                if(count > m) return false;
                prev = 0;
            }

            return count <= m;



        }
        int splitArray(vector<int>& nums, int m) {
            int right = accumulate(nums.begin(), nums.end(), 0);
            int left = *max_element(nums.begin(), nums.end());
            while (left < right) {
                int mid = left + (right - left)/2;
                bool valid = isValidSplit(nums, m, mid);
                if (valid) {
                    right = mid;
                } else {
                    left = mid + 1
                }
            }
        }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
