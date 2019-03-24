//
// Created by yinchunxiang on 2019-03-03.
//

class Solution1 {
 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> result;
    int i = 0;
    for (; i < intervals.size(); ++i) {
      const auto& interval = intervals[i];
      if (newInterval.end < interval.start) {
        result.push_back(newInterval);
        break;
      }
      if (interval.end < newInterval.start) {
        result.push_back(interval);
        continue;
      }
      newInterval.start = min(newInterval.start, interval.start);
      newInterval.end = max(newInterval.end, interval.end);
    }
    if (i >= intervals.size()) {
      result.push_back(newInterval);
    } else {
      result.insert(result.end(), intervals.begin() + i, intervals.end());
    }
    return result;
  }
};


class Solution {
 public:
  // 往 intervals 原地插入
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    for (auto it = intervals.begin(); it != intervals.end();) {
      if (it->start < newInterval.end) {
        intervals.insert(it, newInterval);
        return intervals;
      }
      if (it->end < newInterval.start) {
        ++it;
        continue
      }
      newInterval.start = min(newInterval.start, it->start);
      newInterval.end = max(newInterval.end, it->end);
      it = intervals.erase(it);
    }
    intervals.push_back(newInterval);
    return intervals;
  }
};

