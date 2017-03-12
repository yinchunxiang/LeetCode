/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 21:06:22
 * @brief 
 * 
 **/ 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int N = nums.size();
            sort(nums.begin(), nums.end());
            int mindiff = INT_MAX;
            int closest = 0;
            for (int i = 0; i < N; ++i) {
                int rest = target - nums[i];
                for (int l = i + 1, r = N - 1; l < r;) {
                    int s = nums[l] + nums[r];
                    if (s == rest) {
                        return 0;
                    } else if (s > rest) {
                        --r;
                    } else {
                        ++l;
                    }
                    int diff = abs(s - rest);
                    if (diff < mindiff) {
                        mindiff = diff;
                        closest = nums[i] + s;
                    }
                }
            }
            return closest;
                
        }

};
int main(int argc, char *argv[]) {
    
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
