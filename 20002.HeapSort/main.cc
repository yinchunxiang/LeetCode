/****************************************************************************
 *
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2016/12/26 23:42:15
 * @brief 
 * 
 **/ 

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void rerange(vector<int>&v, int index, int maxn) {
    while (index < maxn) {
        auto lc = index * 2 + 1;
        auto rc = index * 2 + 2;
        auto largest = index;
        if (lc < maxn && v[lc] > v[index]) {
            swap(v[lc], v[index]);
            largest = lc;
        }
        if (rc < maxn && v[rc] > v[index]) {
            swap(v[rc], v[index]);
            largest = rc;
        }
        if (index == largest) {
            break;
        } else {
            index = largest;
        }
    }
}

void extract(vector<int> &v) {
    auto n = v.size();
    if (n <=0) return;

    for (auto i = n - 1; i > 0; --i) {
        swap(v[0], v[i]);
        rerange(v, 0, i);
    }
}

void HeapSort(vector<int> &v) {
    auto n = int(v.size());
    if (n <= 0) return;
    int index = (n - 1)/2 -1;
    for (; index >= 0; --index) {

        rerange(v, index, n);
    }
    extract(v);
}

int main() {
    vector<int> v = {12, 11, 13, 5, 6, 7};
    HeapSort(v);
    printv(v);
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
