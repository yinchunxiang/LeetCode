/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 12:01:09
 * @brief 
 * 
 **/ 

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
 
class Solution {
    public:
        int findPairs(vector<int>& nums, int k) {
            int result = 0;
            sort(nums.begin(), nums.end());
            for (int i = 0, j = 0; i < nums.size(); ++i) {
                j = max(i + 1, j);
                while ( j < nums.size() && nums[j] - nums[i] < k) {
                    ++j;
                }
                if (nums[j] - nums[i] == k) {
                    result += 1;
                }
                while (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                    ++i;
                }
            }
            return result;
        }
};

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {3, 1, 4, 1, 5};
        printv(input);
        cout << s.findPairs(input, 2) << endl;
        
    }
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
