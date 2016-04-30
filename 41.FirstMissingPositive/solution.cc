/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/05/01 00:34:57
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /// write your code here
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (A[i] != i + 1) {
                ///去除异常情况和已经相等的情况
                if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1]) {
                    break;
                }
                swap(A[i], A[A[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
         
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
