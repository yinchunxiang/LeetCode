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

#include <vector>

#include <algorithm>

using namespace std;

bool operator < (const pair<int, int> &l, const pair<int, int> &r) {
    return l.first < r.first;
}
 
class Solution {
    public:
        int findMinArrowShots(vector<pair<int, int>>& points) {
            int n = points.size();
            if (n <= 1) {
                return n;
            }
            sort(points.begin(), points.end());
            vector<pair<int, int>> result;

            int count = 1;

            int end = points[0].second;
            for (int i = 1; i < n; ++i) {
                if (points[i].first <= end) {
                    end = min(end, points[i].second);
                }else {
                    ++count;
                    end = points[i].second;
                }
            }
            return count;
                    
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
