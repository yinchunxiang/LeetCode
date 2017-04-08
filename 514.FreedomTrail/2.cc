/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 23:56:42
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findRotateSteps(string ring, string key) {
    int m = ring.size();
    int n = key.size();
    dp[n + 1][m] = {0};
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = INT_MAX;
            for (int k = 0; k < m; ++k) {
                if (key[i] == ring[k]) {
                    int diff = abs(k - j);
                    int step = min(diff, m - diff);
                    dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                }
            }
        }
    } 
    return dp[0][0] + n;
}


int main(int argc, char *argv[]) {
    cout << findRotateSteps("godding", "gd") << endl;
    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
