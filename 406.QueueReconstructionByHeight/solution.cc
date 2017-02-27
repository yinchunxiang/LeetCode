/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/27 23:33:14
 * @brief 
 * 
 **/ 

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
    { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);  };
    sort(people.begin(), people.end(), comp);
    vector<pair<int, int>> res;
    for (auto& p : people) 
        res.insert(res.begin() + p.second, p);
    return res;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
