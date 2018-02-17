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
#include <iostream>

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
        // 首先考虑输入为空的情况
        if (intervals.empty()) return 0;
        auto cmp = [](const Interval& l, const Interval &r) {return l.end < r.end;};
        sort(intervals.begin(), intervals.end(), cmp);
        int n = (int)intervals.size();
        int pre = intervals[0].end;
        int count = 1;
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

int main(int argc, char* argv[]) {
    //TODO
    vector<vector<int>> input = { {1,2}, {2,3}, {3,4}, {1,3} };
    vector<Interval> intervals;
    for (auto& p : input) {
        Interval interval(p[0], p[1]);
        intervals.push_back(interval);
    }
    Solution s;
    cout << s.eraseOverlapIntervals(intervals) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
