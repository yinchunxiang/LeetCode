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

using namespace  std;

class Solution {
    public:
        bool isMatch(string s, string p) {
            int M = s.size();
            int N = p.size();
            int sstar = -1;
            // 用来记录上次*出现的位置
            int pstar = -1;
            int pi = 0;
            for (int si = 0; si < M; ++si, ++pi) {
                if ('*' == p[pi]) {
                    sstar = si;
                    si -= 1;
                    pstar = pi;
                    continue;
                }
                if ('?' == p[pi]) {
                    continue;
                }
                if (s[si] == p[pi]) {
                    continue;
                }
                if (sstar >= 0) {
                    si = sstar++;
                    pi = pstar;
                    continue;
                }
                return false;
            }

            while (pi < N) {
                if ('*' != p[pi]) {
                    return false;
                }
                ++pi;
            }
            return true;
        }
};


int main(int argc, char *argv[]) {
    Solution sol;
    /*
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
    */
    {
        string s = "hi";
        string p = "*?";
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
