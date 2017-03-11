/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 20:27:35
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int partition(vector<int>& nums, int begin, int end) {
            int pivot = nums[end];
            int bigger = begin;
            for (int i = begin; i < end; ++i) {
                if (nums[i] > pivot) {
                    continue;
                }
                swap(nums[bigger++], nums[i]);

            }
            swap(nums[bigger], nums[end]);
            return bigger;
        }

        int find(vector<int>& nums, int begin, int end, int k) {
            while (begin < end) {
                int mid = partition(nums, begin, end);
                if (mid == k - 1) {
                    return nums[mid];
                }
                if (mid < k - 1) {
                    begin = mid + 1;
                    k -= mid;
                } else {
                    end = mid - 1;
                }
            }
        }
        int thirdMax(vector<int>& nums) {
                    
                
        }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
