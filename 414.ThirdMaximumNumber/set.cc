/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file pq.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 20:43:31
 * @brief 
 * 
 **/ 

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
 
class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            int N = nums.size();
            unordered_set<int> set;
            for (int i = 0; i < N; ++i) {
                set.insert(nums[i]);
            }
            auto first = *max_element(set.begin(), set.end());
            set.erase(first);
            if (set.empty()) {
                return first;
            }
            auto second = *max_element(set.begin(), set.end());
            set.erase(second);
            if (set.empty()) {
                return first;
            }
            return *max_element(set.begin(), set.end());
        }

};


int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {2, 2, 3, 1};
        cout << s.thirdMax(input) << endl;
    }
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
