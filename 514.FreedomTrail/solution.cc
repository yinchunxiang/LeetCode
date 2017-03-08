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

#include <algorithm>
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

        int findRotateSteps(string ring, string key) {
            cout << "ring => " << ring << endl;
            cout << "key  => " << key << endl;
            int m = key.size();
            int n = ring.size();

            vector<vector<int>> mp(26, vector<int>());
            for (auto i = 0; i < n; ++i) {
                mp[ring[i]-'a'].push_back(i);
            }
            //for (auto i = 0; i < mp.size(); ++i) {
            //    if (mp[i].empty()) continue;
            //    char c = 'a' + i;
            //    cout << c << "=> ";
            //    printv(mp[i]);
            //}

            vector<vector<int>> dp(m + 1, vector<int>(n, INT_MAX));
            fill(dp[0].begin(), dp[0].end(), 0);

            vector<int> temp(1, 0);

            for (int i = 1; i < m + 1; ++i) {
                //cout << "char => " << key[i - 1] << endl;
                for (auto j : mp[key[i - 1] - 'a']) {
                    //cout << "j => " << j << endl;
                    for (auto k : temp) {
                        //cout << "k => " << k << endl;
                        int diff = abs(j - k);
                        int steps = dp[i - 1][k] + min(diff , n - diff);
                        dp[i][j] = min(dp[i][j], steps);
                    }
                }
                temp = mp[key[i - 1] - 'a'];
                //cout << "temp ------------------";
                //cout << key[i - 1] << "=> ";
                //printv(temp);
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
