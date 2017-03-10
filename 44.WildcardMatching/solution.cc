/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/10 00:08:53
 * @brief 
 * 
 **/ 

#include <iostream>
#include <string>
#include <vector>

using namespace  std;
 
class Solution {
    public:
        bool isMatch(string s, string p) {
            int M = s.size();
            int N = p.size();
            if (!M && !N) {
                return true;
            }
            if (!N) {
                return false;
            }
            vector<vector<bool>> w(M + 1, vector<bool>(N + 1, false));
            w[0][0] = true;
            for (int i = 1; i <= N; ++i) {
                w[0][i] = '*' == p[i - 1] && w[0][i - 1];
                //cout << "w[0]["<<i<<"] => " << w[0][i] << endl;
            }

            for (int i = 1; i <= M; ++i) {//s
                for (int j = 1; j <= N; ++j) {//p
                    if ('*' == p[j - 1]) {
                        for (int k = 0; k <= i; ++k) {
                            if (w[k][j - 1]) {
                                w[i][j] = true;
                                break;
                            }
                        }
                    } else if ('?' == p[j - 1]) {
                        w[i][j] = w[i - 1][j - 1];
                    } else {
                        w[i][j] = (s[i - 1] == p[j - 1] && w[i - 1][j - 1]);
                    }
                    //cout << "w["<<i<<"]["<<j<<"] => " << w[i][j] << endl;
                }
            }
            return w[M][N];

        }
};


int main(int argc, char *argv[]) {
    Solution sol;
    {
        string s = "aa";
        string p = "a";
        cout << s << " " << p << " => "<< sol.isMatch(s, p) << endl;
    }
    {
        string s = "aa";
        string p = "aa";
        cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    }
    {
        string s = "aaa";
        string p = "aa";
        cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    }
    {
        string s = "aa";
        string p = "*";
        cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    }
    {
        string s = "aa";
        string p = "a*";
        cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    }
    {
        string s = "ab";
        string p = "?*";
        cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    }
    {
        string s = "aab";
        string p = "c*a*b";
        cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    }
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
