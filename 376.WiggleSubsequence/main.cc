/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/22 23:44:44
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
    public:
        int wiggleMaxLength(vector<int>& nums) {
            int n = nums.size();
            if (n <= 1) return n;
            if (2 == n) {
                return nums[0] == nums[1] ? 1 : 2;
            }
            int i = 1;
            for (; i < n; ++i) {
                if (nums[i] != nums[i - 1]) {
                    break;
                }
            }
            if (i == n) {
                return 1;
            }
            int prev_diff = nums[i] - nums[0];
            int prev_index = 1;
            int count = 2;
            for (int i = 2; i < n; ++i) {
                int cur_diff = nums[i] - nums[prev_index];
                if ((prev_diff > 0 && cur_diff < 0) || (prev_diff < 0 && cur_diff > 0)) {
                    count += 1;
                    prev_diff = cur_diff;
                } 
                prev_index = i;
            }
            return count;
        }

};
void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    {
        vector<int> input = {1,7,4,9,2,5};
        printv(input);
        Solution sol;
        cout << sol.wiggleMaxLength(input) << endl;
    }
    {
        vector<int> input = {1,17,5,10,13,15,10,5,16,8};
        printv(input);
        Solution sol;
        cout << sol.wiggleMaxLength(input) << endl;
    }
    {
        vector<int> input = {1,2,3,4,5,6,7,8,9};
        printv(input);
        Solution sol;
        cout << sol.wiggleMaxLength(input) << endl;
    }
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
