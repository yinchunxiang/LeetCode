/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/22 09:36:18
 * @brief 
 * 
 **/

#include <vector>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto cmp = [](const Interval& l, const Interval &r) {return l.end < r.end;};
        sort(intervals.begin(), intervals.end(), cmp);
        int n = (int)intervals.size();
        int pre = intervals[0].end;
        int count = 0;
        for (int i = 1; i < n; ++i) {
            // 计算不重复的
            if (intervals[i].start >= pre) {
                ++count;
                pre = intervals[i].end;
            }
        }
        return n - count;

    }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
