//
// Created by alexkkk on 11/16/17.
//

#include <vector>

using namespace std;


class RangeModule {
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        int n = intervals.size();
        vector<pair<int, int>> temp;
        for (int i = 0; i <= n; ++i) {
            //找到了要插入的位置
            if (i == n || intervals[i].first > right) {
                //@yincx: 先将[left, right)加进去
                temp.emplace_back(left, right);
                //@yincx: 再将余下的都加进去
                while (i < n) temp.push_back(intervals[i++]);
                break;
            }
            //@yincx: interval比要加入的小
            if (intervals[i].second < left) {
                temp.push_back(intervals[i]);
            } else {
                // interval和要加入的[left, right)有交集
                // 更新区间
                left = min(left, intervals[i].first);
                right = max(right, intervals[i].second);
            }
        }
        swap(temp, intervals);

    }

    bool queryRange(int left, int right) {
        int n = (int)intervals.size();
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = l + (r -l )/2;
            if (intervals[m].first >= right) {
                r = m - 1;
            } else if (intervals[m].second < left) {
                l = m + 1;
            } else {
                return left >= intervals[m].first && right <= intervals[m].second;
            }
        }
        return false;

    }

    void removeRange(int left, int right) {
        int n = intervals.size();
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; ++i) {
            //@yincx: 处理没有交集的interval
            if (intervals[i].second < left || intervals[i].first >= right) {
                temp.push_back(intervals[i]);
            } else {
                if (intervals[i].first < left) temp.emplace_back(intervals[i].first, left);
                if (intervals[i].second >= right) temp.emplace_back(right, intervals[i].second);
            }
        }
        swap(intervals, temp);
    }

private:
    vector<pair<int, int>> intervals;
};

