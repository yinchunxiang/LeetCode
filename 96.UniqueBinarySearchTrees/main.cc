/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 23:29:08
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    int numTrees(int n) {
        vector<int> g(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                g[i] += g[j] * g[i - 1 -j];
            }
        }
        return g[n];
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << "n => " << 3 << endl;
    cout << s.numTrees(3) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
