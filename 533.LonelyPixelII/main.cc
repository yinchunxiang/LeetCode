/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/05 13:12:06
 * @brief 
 * 
 **/ 
#include <iostream> 
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        int findRotateSteps(string ring, string key) {
            int N = ring.size();
            vector<vector<int>>  steps(26, vector<int>());
            for (int i = 0; i < N; ++i) {
                auto index = ring[i] - 'a';
                steps[index].push_back(i);
            }
            int result = 0;

            int ldp = 0;
            int rdp = 0;
            int lstart = 0;
            int rstart = 0;
            for (int i = 0; i < key.size(); ++i) {
                auto c = key[i];
                int index = c - 'a';
                auto &v = steps[index];
                int min_clockwise = N;
                int min_clockwise_lp = 0;
                int min_clockwise_rp = 0;

                int min_anticlockwise = N;
                int min_anticlockwise_lp = 0;
                int min_anticlockwise_rp = 0;
                for (auto & pos : v) {
                    // 先进行顺时针处理
                    int ldiff = abs(pos - lstart);
                    if (pos >= lstart) {
                        if (ldiff < min_clockwise ) {
                            min_clockwise = ldiff;
                            min_clockwise_lp = pos;
                        }
                        if (N - ldiff < min_anticlockwise) {
                            min_anticlockwise = N - ldiff;
                            minrp = pos;
                        }
                    } else {
                        if (N - ldiff < min_clockwise) {
                            min_clockwise = N - ldiff;
                            minlp = pos;
                        }
                        if (ldiff < min_anticlockwise) {
                            min_anticlockwise = ldiff;
                            minrp = pos;
                        }
                        
                    }
                    int rdiff = abs(pos - rstart);
                    if (pos >= rstart) {
                        if (rdiff  < min_clockwise) {
                            min_clockwise = rdiff;
                            minlp = pos;
                        }
                        if (N - rdiff < min_anticlockwise) {
                            min_anticlockwise = N - rdiff;
                            minrp = pos;
                        }
                    } else {
                        if (N - rdiff  < min_clockwise) {
                            min_clockwise = N - rdiff;
                            minlp = pos;
                        }
                        if (rdiff < min_anticlockwise) {
                            min_anticlockwise = rdiff;
                            minrp = pos;
                        }
                    }
                }
                lstart = minlp;
                rstart = minrp;
                int prev_ldp = ldp;
                int prev_rdp = rdp;
                ldp = min(prev_ldp, prev_rdp) + 1 + min_clockwise;
                rdp = min(prev_ldp, prev_rdp) + 1 + min_anticlockwise;
            }
            return min(ldp, rdp);

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
