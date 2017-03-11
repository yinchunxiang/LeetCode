/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 19:11:38
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int max_count = 0;
            int cur_count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i]&1) {
                    max_count = max(max_count, ++cur_count);
                } else {
                    cur_count = 0;
                }
            }
            return max_count;
        }
};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {1,1,0,1,1,1};
        cout << s.findMaxConsecutiveOnes(input);
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
