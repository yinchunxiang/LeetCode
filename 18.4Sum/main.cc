/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 21:34:02
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            int N = nums.size();
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    int rest = target - nums[i] - nums[j];
                    for (int l = j + 1, r = N - 1; l < r;) {
                        int s = nums[l] + nums[r];
                        if (s < rest) {
                            ++l;
                        } else if (s > rest) {
                            --r;
                        } else {
                            result.push_back({nums[i], nums[j], nums[l], nums[r]});
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

                    while (j + 1 < N && nums[j] == nums[j + 1]) {
                        ++j;
                    }

                }
                while(i + 1 < N && nums[i] == nums[i + 1]) {
                    ++i;
                }
            }
            return result;
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
