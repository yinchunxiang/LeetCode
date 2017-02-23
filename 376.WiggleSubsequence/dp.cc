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
            vector<int> N(n, 1);
            vector<int> P(n, 1);
            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    if (nums[i] - nums[j] > 0) {
                        P[i] = max(P[i], N[j] + 1);
                    }
                    if (nums[i] - nums[j] < 0) {
                        N[i] = max(N[i], P[j] + 1);
                    }
                }
            }
            return max(N.back(), P.back());
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
