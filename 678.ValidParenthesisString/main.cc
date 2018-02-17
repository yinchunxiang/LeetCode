/****************************************************************************
 * 
 * Copyright (C) 2018 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2018/02/08 11:52:43
 * @brief 
 * 
 **/ 

using namespace std;

#include <string>
#include <iostream>

class Solution {
public:
    bool leftCheck(const string& s) {
        int asterisk = 0;
        int left = 0;
        int right = 0;

        for (auto c : s) {
            switch (c) {
                case '*':
                    asterisk++;
                    break;
                case '(':
                    left ++;
                    break;
                case ')':
                    right ++;
                    break;
            }
            if (right > left + asterisk) return false;
        }
        if (abs(left - right) <= asterisk) return true;
        return false;
    }

    bool rightCheck(const string& s) {
        int n = (int)s.size();
        int asterisk = 0;
        int left = 0;
        int right = 0;
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            switch (c) {
                case '*':
                    asterisk++;
                    break;
                case '(':
                    left ++;
                    break;
                case ')':
                    right ++;
                    break;
            }
            if (left > right + asterisk) return false;
        }
        if (abs(left - right) <= asterisk) return true;
        return false;
    }


    bool checkValidString(string s) {
        return leftCheck(s) && rightCheck(s);
    }

};


int main(int argc, char *argv[]) {
    Solution s;
    {
        string input = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
        cout << s.checkValidString(input) << endl;
    }
    {
        string input = "(*)";
        cout << s.checkValidString(input) << endl;
    }
    {
        string input = "(*))";
        cout << s.checkValidString(input) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
