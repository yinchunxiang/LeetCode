/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/05 20:46:41
 * @brief 
 * 
 **/ 

#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    int max_step_ = 6;

    // shrink the string until no 3 or more consecutive balls in same color
    string shrink(string s) {
        while (!s.empty()) {
            int start = 0;
            bool done = true;
            for (int i = 0; i <= s.size(); ++i) {
                if (i == s.size() && i - start >= 3) {
                    s = s.substr(0, start);
                    done = false;
                    break;
                }
                if (s[start] == s[i]) {
                    continue;
                }
                if (i - start >= 3) {
                    s = s.substr(0, start) + s.substr(i);
                    done = false;
                    break;
                }
            }
            if (done) break;
        }
        return s;
    }


public:
    int findMinStep(string board, string hand) {
        sort(begin(hand), end(hand));
        int res = helper(board, hand);
        return res > hand.size() ? -1 : res;
    }

    int helper(string b, string h) {
        if (b.empty()) return 0;
        if (h.empty()) return max_step_;
        int res = max_step_;
        for (int i = 0; i < h.size(); ++i) {
            int j = 0;
            int n = b.size();
            while (j < n) {
                // 从j开始查找h[i]
                int k = b.find(h[i], j);
                // 没有找到
                if (string::npos == k) break;

                // 找到2个连续的颜色相同的球
                if (k < n - 1 && b[k] == b[k + 1]) {
                    string nextb = shrink(b.substr(0, k) + b.substr(k + 1));
                    if (nextb.empty()) return 1;
                    string nexth = h;
                    nexth.erase(i, 1);
                    res = min(res, helper(nextb, nexth) + 1);
                    ++k;
                }
                else if (i > 0 && h[i] == h[i - 1]) { //2 balls with same color in hand
                    string nextb = shrink(b.substr(0, k) + b.substr(k + 1));
                    if (nextb.empty()) return 2;
                    string nexth = h;
                    h.erase(i, 1);
                    h.erase(i - 1, 1);
                    res = min(res, helper(nextb, nexth) + 2);
                }
                j = k + 1;
            }
        }
        return res;
    }



};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
