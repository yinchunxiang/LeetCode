/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/19 20:40:57
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            int i = 0;
            int j = 0;
            while (i < g.size() && j < s.size()) {
                if (g[i] <= s[j]) {
                    ++i;
                }
                ++j;
            }
            return i;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
