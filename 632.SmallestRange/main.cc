/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/10 11:04:19
 * @brief 
 * 
 **/ 
 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> all;
        // 初始区间
        int start = 0;
        int end = 0;
        int min_range = INT_MAX;
        int num_list = nums.size();
        // 用来记录有哪些list出现在区间中
        vector<int> occurs(num_list, 0);
        // 用来记录数字在哪些列表出现过
        unordered_map<int, vector<int>> 
        for (auto &row : nums) {

        }
        
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
