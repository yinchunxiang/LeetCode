/****************************************************************************
 * 
 * Copyright (C) 2018 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2018/01/14 22:36:44
 * @brief 
 * 
 **/

#include <vector>
#include <iostream>
#include <unordered_set>
#include <set>
#include <list>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](const vector<int>& a, const vector<int>& b) {
            return a.back() == b.back() ? a.front() > b.front() : a.back() < b.back();
        });
        list<int> result;
        for (const auto& interval : intervals) {
            int count = 0;
            for (auto num : result) {
                if (num >= interval.front() && num <= interval.back()) {
                    ++count;
                    if (count >= 2) {
                        break;
                    }
                }
            }
            switch (count) {
                case 1:
                    result.push_front(interval.back());
                    break;
                case 0:
                    result.push_front(interval.back() - 1);
                    result.push_front(interval.back());
                    break;
                default:
                    break;
            }
        }
        return  result.size();
    }

    //在前一版本的基础上做优化
    int intersectionSizeTwoV1(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](const vector<int>& a, const vector<int>& b) {
            return a.back() == b.back() ? a.front() > b.front() : a.back() < b.back();
        });
        //list<int> result;
        int count = 0;
        int p1 = -1;
        int p2 = -1;
        for (const auto& interval : intervals) {
            if (interval.back() == p1) continue;
            if (interval.front() <= p2) continue;
            if (interval.front() > p1) {
                count += 2;
                p2 = interval.back() - 1;
                p1 = interval.back();
            } else {
                count += 1;
                p2 = p1;
                p1 = interval.back();
            }
        }
        return  count;
    }
};

int main(int argc, char* argv[]) {
    //TODO
    {
        vector<vector<int>> input = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
        Solution s;
        cout << s.intersectionSizeTwo(input) << endl;
    }

    {
        vector<vector<int>> input = {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
        Solution s;
        cout << s.intersectionSizeTwo(input) << endl;
    }
    {
        vector<vector<int>> input = {{2,10},{3,7},{3,15},{4,11},{6,12},{6,16},{7,8},{7,11},{7,15},{11,12}};
        Solution s;
        cout << s.intersectionSizeTwo(input) << endl;
    }

    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
