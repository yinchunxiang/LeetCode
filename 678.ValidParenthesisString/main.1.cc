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
    bool checkValidString(string s) {
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
            if (abs(left - right) <= asterisk) return true;
            if (right > left + asterisk) return false;
        }
        return false;
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
