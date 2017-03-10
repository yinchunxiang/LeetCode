/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 19:45:18
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            int N = nums.size();
            for (int i = 0; i < N; ) {
                int target = nums[i] - 1;
                if (i == target) {
                    ++i;
                    continue;
                }
                if (nums[target] == nums[i]) {
                    ++i
                    continue;
                } 
                swap(nums[target], nums[i]);
            }
            vector<int> result;
            for (int i = 0; i < N; ++i) {
                if (i + 1 != nums[i]) {
                    result.push_back(i + 1);
                }
            }
            return result;
        }
};

int main(int argc, char *argv[]) {

    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
