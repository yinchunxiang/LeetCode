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
 
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef vector<int>::iterator VecIntIter;
        struct comp {
            bool operator()(const pair<VecIntIter, VecIntIter> &a, const pair<VecIntIter, VecIntIter> &b) {
                return (*a).first > (*b.first);
            }
        }

        int left = INT_MAX;
        int right = INT_MIN;

        // 构造函数： 类型， 容器，类型比较函数或者类
        priority_queue<VecIntIter, vector<VecIntIter>, comp> pq;
        for (auto &row : nums) {
            left = min(left, row[0]);
            right = max(right, row[0]);
            pq.push({row.begin(), row.end()});
        }
        vector<int> result = {left, right};
        while (true) {
            auto p = pq.top();
            pq.pop();
            ++p.first;
            if (p.first == p.second) {
                break;
            }
            pq.push(p);
            //插入priority_queue之后，获取最新的最小值
            left = *(pq.top().first);
            //更新最大值
            right = max(right, *(p.first));
        }
        return result;
        
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
