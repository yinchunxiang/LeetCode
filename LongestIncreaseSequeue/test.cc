/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file test.cc
 * @author yinchunxiang(@com)
 * @date 2016/04/27 00:19:42
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> v = {1, 2, 4, 5};
    auto it = find_if(v.rbegin(), v.rend(), [] (int i) {return i < 3;});
    cout << *it << endl;
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
