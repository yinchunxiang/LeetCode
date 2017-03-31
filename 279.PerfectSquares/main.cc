/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/27 22:32:38
 * @brief 
 * 
 **/ 
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
    public:
        int numSquares(int n) {
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; ;) {
                    int square = j * j;
                    if (square > i) {
                        break;
                    }
                    dp[i] = min(dp[i], dp[i - square] + 1);
                    ++j;
                }
            }
            return dp[n];
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.numSquares(12) << endl;
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
