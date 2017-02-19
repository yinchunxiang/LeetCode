/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/15 20:32:52
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int longestValidParentheses(string ss) {
            int n = ss.size();
            if (n <= 0) return 0;
            stack<int> s;
            int maxlen = 0;
            int start = -1;

            int i = 0;
            for (i = 0; i < n; ++i) {
                if ('(' == ss[i]) {
                    s.push(i);
                    continue;
                } 
                if (s.empty()) {
                    start = i;
                    continue;
                } 
                s.pop();
                if (s.empty()) {
                    maxlen = max(maxlen, i - start);
                } else {
                    maxlen = max(i - s.top(), maxlen);
                }
            }
            return maxlen;
        }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
