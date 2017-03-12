/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 15:37:51
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>

using namespace std;
 
class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int N = nums.size();
            for (int i = 0; i < N; ) {
                if (nums[i] == i + 1) {
                    ++i;
                    continue;
                }
                if (nums[i] <= 0) {
                    ++i;
                    continue;
                }
                if (nums[i] > 0 && nums[i] <= N) {
                    int target = nums[i] - 1;
                    swap(nums[i], nums[target]);
                    continue;
                }
                nums[i++] = 0;
            }
            for (int i = 0; i < N; ++i) {
                if (0 == nums[i]) {
                    return i + 1;
                }
            }
            return N + 1;
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {1,2,0};
        cout << s.firstMissingPositive(input) << endl;
    }
    {
        vector<int> input = {3,4,-1,1};
        cout << s.firstMissingPositive(input) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
