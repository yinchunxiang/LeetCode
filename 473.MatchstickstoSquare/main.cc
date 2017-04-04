/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/03 18:17:43
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        bool dfs(vector<int>& sums, int target, vector<int>& nums, int index) {
            if (index >= nums.size()) {
                return (target == sums[0] && target == sums[1] && target == sums[2])
            }
            for (int i = 0; i < sums.size(); ++i) {
                if (sums[i] + nums[index] > target) {
                    continue;
                }
                bool visited = false;
                for (int j = i - 1; j >= 0; --j) {
                    if (sums[j] == sums[i]) {
                        visited = true;
                        break;
                    }
                }
                if (visited) continue;
                sums[i] += nums[index];
                if (dfs(sums, target, nums, index + 1)) {
                    return true;
                }
                sums[i] -= nums[index];
            }
            return false;
        }
        bool makesquare(vector<int>& nums) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum %4) {
                return false;
            }
            int target = sum/4;
            sort(nums.begin(), nums.end(), greater<int>());
            vector<int> sums(4, 0);
            return dfs(sums, target, nums, 0);
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
