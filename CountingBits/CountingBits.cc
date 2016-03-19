/****************************************************************************
 * 
 * Copyright (C) 2016 Baidu.com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file CountingBits.cc
 * @author yinchunxiang(com@baidu.com)
 * @date 2016/03/19 22:22:06
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;


void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


vector<int> countBits(int num) {
    vector<int> result(num + 1, 0);
    size_t pre2pow = 1;
    size_t cur2pow = 2;
    for (int i = 1; i <= num; ++i) {
        if (i >= cur2pow) {
            pre2pow = cur2pow;
            cur2pow <<= 1;
        }
        result[i] = 1 + result[i - pre2pow];
    }
    return result;
}

int main(int argc, const char *argv[])
{
    {
        auto v = countBits(5);
        printv(v);
    }
    {
        auto v = countBits(10);
        printv(v);
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
