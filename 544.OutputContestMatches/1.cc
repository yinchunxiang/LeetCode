/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/19 12:59:30
 * @brief 
 * 
 **/ 

#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

void printv(const std::vector<string> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}
 
class Solution {
    public:

        string findContestMatch(int n) {
            if (n < 1) {
                return "";
            }
            vector<string> v(n, "");
            for (int i = 1; i <= n; ++i) {
                v[i - 1] = std::to_string(i);
            }

            while (n > 1) {
                for (int i = 0; i < n/2; ++i) {
                    v[i] = "(" + v[i] + "," + v[n - 1 -i] + ")";
                }
                n /= 2;
            }
            return v[0];
        }

};


int main(int argc, char *argv[]) {
    Solution s;
    {
        cout << s.findContestMatch(2) << endl;
    }
    {
        cout << s.findContestMatch(4) << endl;
    }
    {
        cout << s.findContestMatch(8) << endl;
    }
    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
