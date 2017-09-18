/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/18 09:47:18
 * @brief 
 * 
 **/ 
 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0; 
        int high = num.size() - 1;
        int mid = low + (high - low) / 2;
        int minValue = numeric_limits<int>::max();
        while (low < high) {
            if (nums[mid] < nums[high]) {
                high = mid;
            } else if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                --high;
            }
        }
        return nums[low];
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
