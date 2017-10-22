/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/10/22 13:31:57
 * @brief 
 * 
 **/ 

class Solution {
    public:
        int trap(vector<int>& height) {
            vector<int> v;
            int sum = 0;
            for (int i = 0; i < height.size(); ++i) {
                if (v.empty() || height[i] <= height[v.back()]) {
                    v.push_back(i);
                    continue;
                }

                while (!v.empty() && height[v.back()] < height[i]) {
                    int bar = height[v.back()];
                    v.pop_back();
                    // 左侧没有更大的，直接兜不住
                    if (v.empty()) continue;
                    int l = i - v.back() - 1;
                    int h = min(height[v.back()], height[i]) - bar;
                    sum += l * h;
                }
                v.push_back(i);
            }
            return sum;
        }
};









/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
