/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/10 11:04:19
 * @brief 
 * 
 **/

#include <vector>
#include <queue>

using namespace std;
 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator VecIntIter;
        struct comp {
            bool operator()(const pair<VecIntIter, VecIntIter> &a, const pair<VecIntIter, VecIntIter> &b) {
                return (*a.first) > (*b.first);
            }
        }

        int left = INT_MAX;
        int right = INT_MIN;

        // 构造函数： 类型， 容器，类型比较函数或者类
        priority_queue<pair<VecIntIter, VecIntIter>, vector<pair<VecIntIter, VecIntIter>>, comp> pq;

        // 得到初始的范围[left, right]
        for (auto &row : nums) {
            left = min(left, row[0]);
            right = max(right, row[0]);
            //pq.push({row.begin(), row.end()});
            pq.emplace(row.begin(), row.end());
        }
        vector<int> result = {left, right};
        while (true) {
            auto p = pq.top();
            pq.pop();
            ++p.first;
            // 判断范围
            if (p.first == p.second) {
                break;
            }
            // pop的是哪个列表的，就从哪个列表加一个进去
            pq.push(p);
            //插入priority_queue之后，获取最新的最小值
            left = *(pq.top().first);
            //更新最大值
            right = max(right, *(p.first));
            if (right - left < result[1] - result[0]) {
                result[0] = left;
                result[1] = right;
            }
        }
        return result;
        
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
