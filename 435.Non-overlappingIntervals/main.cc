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
            auto cmp = [](const Interval& l, const Interval &r) {return l.start < r.start;}
            sort(intervals.begin(), intervals.end(), cmp);
            int n = (int)intervals.size();
            int pre = 0;
            int count = 0;
            for (int i = 1; i < n; ++i) {
                if (intervals[i].start < intervals[pre].end) {
                    //有交集，则去掉比较大的那个
                    count += 1;
                    if (intervals[i].end > intervals[pre].end) {
                        continue;         
                    }
                } 
                pre = i;
            }
            return count;
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
