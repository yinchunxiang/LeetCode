/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/05 19:53:04
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int binary_search(const std::vector<int> &v, int l, int r, int x) {
    if (l > r) {
        return l;
    }
    int mid = l + (r - l)/2;
    if (v[mid] < x) {
        return binary_search(v, l, mid - 1, x);
    } else {
        return binary_search(v, mid + 1, r, x);
    }
}

int main() {
    //vector<int> v = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    {
        vector<int> v = {1, 1, 0, 0, 0, 0, 0};
        printv(v);

        cout << "=> 1's count:" << endl;
        cout << binary_search(v, 0, v.size() - 1, 1) << endl;
    }

    {
        vector<int> v = {1, 1, 1, 1, 1, 1, 1};
        printv(v);

        cout << "=> 1's count:" << endl;
        cout << binary_search(v, 0, v.size() - 1, 1) << endl;
    }


    return 0;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
