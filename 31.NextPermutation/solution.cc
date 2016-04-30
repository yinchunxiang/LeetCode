/****************************************************************************
 * 
 * Copyright (C) 2016 Baidu.com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(com@baidu.com)
 * @date 2016/04/23 11:00:15
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            /// write your code here
            int size = nums.size();
            int i = size - 2; //第一个乱序的元素的位置
            for (; i >=0; --i) {
                if (nums[i] < nums[i + 1]) {
                    break;
                }
            }
            if (i < 0) {
                reverse(nums.begin(), nums.end());
                return;
            }
            int j = size -1;
            for (; j > i; --j) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
};

void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char* argv[]) {
    {
        vector<int> v = {1,2,3};
        printv(v);
        Solution s;
        s.nextPermutation(v);
        printv(v);
    }
    {
        vector<int> v = {1,4,2,3};
        printv(v);
        Solution s;
        s.nextPermutation(v);
        printv(v);
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
