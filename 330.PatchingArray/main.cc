/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/01 23:42:10
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>

using namespace std;
 
class Solution {
    public:
        int minPatches(vector<int>& nums, int n) {
            // 求和注意溢出的问题
            long sum = 0;
            long curmax = 0;
            long index = 0;
            long count = 0;
            while (sum < n) {
                if ((index < nums.size()) && (nums[index] <= sum + 1)) {
                    curmax = max(curmax, (long)nums[index]);
                    sum += nums[index];
                    ++index;
                } else {
                    ++count;
                    curmax = sum + 1;
                    sum += curmax;
                }
            }
            return count;
        }

};

int main(int argc, char *argv[]) {
    {
        vector<int> input = {1, 5, 10};
        Solution sol;
        cout << sol.minPatches(input, 20) << endl;
    }
    {

        vector<int> input = {};
        Solution sol;
        cout << sol.minPatches(input, 7) << endl;
    }
    {

        vector<int> input = {1, 2, 31, 33};
        Solution sol;
        cout << sol.minPatches(input, 2147483647) << endl;

    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
