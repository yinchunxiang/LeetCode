/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/22 08:45:30
 * @brief 
 * 
 **/

//TODO: 如何证明贪心是正确的

#include <algorithm>
#include <vector>

using namespace std;


class Solution {
    public:
        int findMinArrowShots(vector<pair<int, int>>& points) {
            auto cmp = [](const pair<int, int> &l, const pair<int, int> &r) { return l.second < r.second; };
            sort(begin(points), end(points), cmp);
            long end = LONG_MIN;
            int count = 0;
            for (auto& p : points) {
                if (p.first > end) {
                    ++count;
                    end = p.second;
                }
            }
            return count;

        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
