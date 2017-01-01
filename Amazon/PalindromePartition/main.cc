/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/01/01 16:35:22
 * @brief 
 * 
 **/ 

#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

int min_cut(const string& s, int start, int end) {
    if (is_palindrome(s, start, end)){
        return 0;
    }
    int min = end - start;
    for (int i = start; i < end; ++i) {
        min = std::min(min,  min_cut(s, start, i) + 1 + min_cut(s, i + 1, end));
    }
    return min;
}

int MinCut(const string &s) {
    int size = (int)s.size();
    vector<vector<bool>> p(size, vector<bool>(size, false));
    for (int i = 0; i < size; ++i) {
        p[i][i] = true;
    }
    vector<vector<int>> c(size, vector<int>(size, 0));

    for (int step = 1; step < size; ++step) {
        for (int i = 0; i + step < size; ++i) {
            /// 先判断是不是回文
            int j = i + step;
            if (1 == step) {
                p[i][j] = (s[i] == s[j]);
            } else {
                p[i][j] = (s[i] == s[j] && p[i + 1][j - 1]);
            }

            /// 计算切回文的最小切数
            if (p[i][j]) {
                c[i][j] = 0;
            } else {
                c[i][j] = step;
                for (int k = i; k < j; ++k) {
                    c[i][j] = min(c[i][j], c[i][k] + 1 + c[k + 1][j]);
                }
            }
        }
    }
    return c[0][size - 1];
}
 
int main(int argc, char *argv[]) {
    string  s = "ababbbabbababa";
    cout << "recursive => " << min_cut(s, 0, s.size() - 1) << endl;;
    cout << "dp => " << MinCut(s) << endl;;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
