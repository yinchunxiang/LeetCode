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

    }

    void removeRange(int left, int right) {

    }

private:
    vector<pair<int, int>> intervals;
};

