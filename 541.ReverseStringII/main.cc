/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 10:46:07
 * @brief 
 * 
 **/ 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
 
class Solution {
    public:
        string reverseStr(string s, int k) {
            int N = s.size();
            for (int i = 0; i < N; i += 2*k) {
                int end = min(i + 2 * k, N);
                int diff = end - i;
                if (diff < k) {
                    reverse(s.begin() + i, s.begin() + end);
                    continue;
                } else {
                    reverse(s.begin() + i, s.begin() + i + k);
                }
            }
            return s;
        }
};


int main(int argc, char *argv[]) {
    Solution s;
    {
        string input = "abcdefg";
        int k = 2;
        cout << s.reverseStr(input, k) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
