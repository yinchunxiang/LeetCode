/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/18 15:12:51
 * @brief 
 * 
 **/ 


 
class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            
            // [left, right] 当前覆盖区域
            int left = 0;
            int right = 0;
            // 到达当前覆盖区域需要的steps
            int steps = 0;
            while (left <= right) {
                step += 1;
                old_right = right;
                for (int i = left; i <=right; ++i) {
                    int new_right = i + nums[i];
                    if (new_right >= n - 1) {
                        return step;
                    }
                    if (new_right > right) {
                        right = new_right;
                    }
                }
                left = old_right + 1;
            }
            return 0;
        }

        int jump1(vector<int>& nums) {
            int curlast = 0; 
            int nextlast = 0; 
            int steps = 0;
            int n = nums.size();
            for (int i = 0; i < n; ++i) {
                if (i > curlast) {
                    steps += 1;
                    curlast = nextlast;
                    if (curlast >= n -1) {
                        return steps;
                    }
                }
                nextlast = max(nextlast, i + nums[i]);
            }
            return steps;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
