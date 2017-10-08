/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/18 11:26:59
 * @brief 
 * 
 *
 **/ 


#include <string>
#include <iostream>

using namespace std;

int minWindow(string& s, string& t) {
    vector<int> map(128, 0);
    for (auto c : t) {
        map[c] += 1;
    }
    int d = numeric_limits<int>::max();
    int count = t.size();
    int end = 0;
    int start = 0;
    while (end < s.size()) {
        if (map[s[end++]] -- > 0) {
            count -= 1;
        }
        while (0 == count) {
            d = min(d, end - start);
            if (map[s[start++]]++ == 0) {
                count += 1;
            }
        }
    }
    return d;
}

 
int main(int argc, char *argv[])
{
    
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
