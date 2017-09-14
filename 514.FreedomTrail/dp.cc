/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 3.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/13 21:14:09
 * @brief 
 * 
 **/ 

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
 
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        if (ring.empty() || key.empty()) {
            return 0;
        }
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int k = 0; k < m; ++k) {
            if (ring[k] != key[0]) {
                dp[0][k] = 0;
            }
            dp[0][k] = min(k, m - k) + 1;
        }

        int res = m * n;

        for (int i = 1;i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (key[i] != ring[j]) {
                    continue;
                }
                for (int k = 0; k < m; ++k) {
                    int d1 = abs(k - j);
                    int d2 = m - d1;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(d1, d2) + 1);
                    if (i == n - 1) {
                        res = min(res, dp[i][j]);
                    }
                }
            }
        }
        
    }
};

int main(int argc, char *argv[])
{
    string ring = "godding";
    string key = "gd";
    Solution s; 
    s.findRotateSteps(ring, key);
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
