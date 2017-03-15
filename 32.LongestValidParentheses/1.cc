/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/13 21:24:34
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int longestValidParentheses(string ss) {
            int N = ss.size();
            if (N <= 1) return 0;
            vector<int> f(N, 0);
            for (int i = 1; i < N; ++i) {
                if ('(' == ss[i]) {
                    continue;
                }
                if (')' == ss[i]) {
                    int left = i - f[i - 1] - 1;
                    if (ss[left] == '(') {
                        f[i] = 2 + f[i - 1] + f[left - 1];
                    }
                }
            }
            return *max_element(f.begin(), f.end());
        }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
