/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/
#include <iostream>
#include <vector>
#include <set>

using namespace std;


/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/13 18:15:40
 * @brief 
 * 
 **/ 
 
 // Definition for an interval.
  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval interval(val, val);
        auto it = sortedIntervalSet.lower_bound(interval);
        // 注意可以跟前面合并的情况
        if (it != sortedIntervalSet.begin() && (--it)->end + 1 < val) {
            ++it;
        }
        int start = val;
        int end = val;
        while (it != sortedIntervalSet.end() && val + 1 >= it->start && val - 1 <= it->end) {
            start = min(start, it->start);
            end = max(end, it->end);
            it = sortedIntervalSet.erase(it);
        }
        sortedIntervalSet.insert(it, Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        return vector<Interval>(sortedIntervalSet.begin(), sortedIntervalSet.end());
    }

private:
    struct Comp {
        // 注意：这里的参数必须是const引用，或者直接传值，不能只是引用
        bool operator()(const Interval &a, const Interval &b) {
            return a.start < b.start;
        }
    };

    set<Interval, Comp> sortedIntervalSet;

};



/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

int main(int argc, char *argv[])
{
    cout << "hello world" << endl;
    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
