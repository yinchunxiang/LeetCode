/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/05 23:52:18
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:

        int findRotateSteps(string ring, string key) {
            cout << "ring => " << ring << endl;
            cout << "key  => " << key << endl;
            int m = key.size();
            int n = ring.size();
            vector<vector<int>> dp(m + 1, vector<int>(n, 0));

            for (int i = 1; i < m + 1; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j] = INT_MAX;
                    for (int k = 0; k < n; ++k) {
                        if (key[i - 1] == ring[k]) {
                            //cout << "i => " << i - 1 << endl;
                            //cout << "j => " << j << endl;
                            //cout << "k => " << k << endl;
                            int diff = abs(j - k);
                            int steps = min(diff, n - diff);
                            dp[i][j] = min(dp[i - 1][k] + steps, dp[i][j]);
                            //cout << "---------------------" << endl;
                        }
                    }
                }
            }
            return *std::min_element(dp[m].begin(), dp[m].end()) + m;
        }

};

int main(int argc, char *argv[]) {
    {
        string ring = "godding";
        string key = "gd";
        Solution sol;
        cout << sol.findRotateSteps(ring, key) << endl;

    }
    {
        string ring = "godding";
        string key = "godding";
        Solution sol;
        cout << sol.findRotateSteps(ring, key) << endl;

    }
    {
        string ring = "caotmcaataijjxi";
        string key = "oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx";
        Solution sol;
        cout << sol.findRotateSteps(ring, key) << endl;

    }
    return 0;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
