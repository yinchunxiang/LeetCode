/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/11 17:58:44
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>

using namespace std;
 
void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
    public:
        void partition(vector<int> &nums) {
            int N = nums.size();
            int pivot = nums[N - 1];
            int bigger = 0;
            for (int i = 0; i < N - 1; ++i) {
                if (nums[i] < pivot) {
                    swap(nums[bigger++], nums[i]);
                }
            }
            swap(nums[bigger], nums[N - 1]);
        }
        int majorityElement(vector<int>& nums) {
            int N = nums.size();
            partition(nums);
            return nums[N/2];
        }

};


int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {4,5,4};
        cout << s.majorityElement(input) << endl;
    }
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
