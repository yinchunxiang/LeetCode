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
            //cout << " input s => " << s << " p => " << p << endl;
            if (s.empty() && p.empty()) {
                return true;
            }

            if (p.empty()) {
                return false;
            }

            if (s.empty()) {
                for (auto c : p) {
                    if ('*' != c) {
                        return false;
                    }
                }
                return true;
            }

            if ('*' != p[0]) {
                if ('?' == p[0]) {
                    return isMatch(s.substr(1), p.substr(1));
                }
                return s[0] == p[0] && isMatch(s.substr(1), p.substr(1));
            }
            int pos = 0;
            while ('*' == p[pos]) {
                ++pos;
            }

            for (int i = 0; i <= s.size(); ++i) {
                if (isMatch(s.substr(i), p.substr(pos))) {
                    return true;
                }
            }
            return false;
                
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
