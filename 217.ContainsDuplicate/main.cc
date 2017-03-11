/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/11 09:40:01
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> s;
            for (auto n : nums) {
                auto it = s.find(n);
                if (s.end() != it) {
                    return true;
                }
                s.insert(n);
            }
            return false;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
