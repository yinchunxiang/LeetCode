/****************************************************************************
 * * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/19 21:40:01
 * @brief 
 * 
 **/ 
#include <iostream> 
#include <string>

using namespace std;

class Solution {
    public:
        string removeKdigits(string num, int k) {
            if (0 == k) {
                return num;
            }

            int n = num.size();
            if (k >= n) {
                return "0";
            }
            int digits = n - k;

            string s = num;
            int top = -1;
            for (int i = 0; i < n; ++i) {
                if (top < 0) {
                    s[++top] = num[i];
                    continue;
                }
                while (top >= 0 && s[top] > num[i] && k) {
                    --top;
                    --k;
                }
                s[++top] = num[i];
            }
            int index = 0;
            while (index <= top && '0' == s[index]) {
                ++index;
            }
            return index == digits ? "0" : s.substr(index, digits - index);
        }
};

int main(int argc, char *argv[]) {
    {
        Solution s;
        string input = "1432219";
        cout << "input => "  << input << endl;
        cout << s.removeKdigits(input, 3) << endl;
    }
    {
        Solution s;
        string input = "10200";
        cout << "input => "  << input << endl;
        cout << s.removeKdigits(input, 1) << endl;

    }
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
