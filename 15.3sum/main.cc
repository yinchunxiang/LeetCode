/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 20:30:15
 * @brief 
 * 
 **/

#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            int N = nums.size();
            for (int i = 0; i < N; ++i) {
                int target = -nums[i];
                int l = i + 1;
                int r = N - 1;
                while (l < r) {
                    int sum = nums[l] + nums[r];
                    if (sum < target) {
                        ++l;
                    } else if (sum > target) {
                        --r;
                    } else {
                        result.push_back({nums[i], nums[l], nums[r]});
                        ++l;
                        --r;
                        while (l < r && nums[l] == nums[l - 1]) {
                            ++l;
                        }
                        while (l < r && nums[r] == nums[r + 1]) {
                            --r;
                        }
                    }
                }
                while (i + 1 < N && nums[i] == nums[i + 1]) {
                    ++i;
                }
            }
            return result;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
