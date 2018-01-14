/****************************************************************************
 * 
 * Copyright (C) 2018 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2018/01/14 21:18:58
 * @brief 
 * 
 **/

#include <vector>
#include <map>
#include <iostream>

using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> result;
        map<int, int> timeline;
        for (int i = 0; i < schedule.size(); ++i) {
            for (int j = 0; j < schedule[i].size(); ++j) {
                timeline[schedule[i][j].start] ++;
                timeline[schedule[i][j].end] --;
            }
        }

        int workers = 0;
        for (auto p : timeline) {
            workers += p.second;
            if (workers <= 0) result.push_back(Interval(p.first, 0));
            if (workers && !result.empty() && !result.back().end) result.back().end = p.first;
        }
        // 最后一个可能是无限范围的
        if (!result.empty()) result.pop_back();
        return result;
    }

    vector<Interval> employeeFreeTimeV1(vector<vector<Interval>>& schedule) {
        vector<Interval> sortedIntervals;
        for (const auto& intervals : schedule) {
            sortedIntervals.insert(end(sortedIntervals), begin(intervals), end(intervals));
        }
        sort(
                begin(sortedIntervals),
                end(sortedIntervals),
                [](const Interval& a, const Interval& b) {
                    return a.start < b.start;
                }
        );

        int preStart = INT_MIN;
        int preEnd = sortedIntervals[0].start;

        vector<Interval> result;
        for (int i = 0; i < sortedIntervals.size(); ++i) {
            int curStart = sortedIntervals[i].start;
            int curEnd = sortedIntervals[i].end;
            if (curStart > preEnd) {
                result.emplace_back(preEnd, curStart);
                preStart = curStart;
                preEnd = curEnd;
            } else {
                preStart = min(preStart, curStart);
                preEnd = max(preEnd, curEnd);
            }
        }

        return result;
    }
};


int main(int argc, char* argv[]) {
    //TODO
    cout << "---> start ..." << endl;
    vector<vector<Interval>> input = {
            {{1, 2}, {5, 6}},
            {{1, 3}},
            {{4, 10}}
    };
    Solution s;
    auto result = s.employeeFreeTimeV1(input);
    for (auto interval : result) {
        cout << "(" << interval.start << ", " << interval.end << ")" << endl;
    }
    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
