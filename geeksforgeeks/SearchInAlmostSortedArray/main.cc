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

int search(vector<int> &v, int l, int r, int x) {
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (v[mid] == x) {
        return mid;
    }
    if (mid - 1 >= l && v[mid - 1] == x) {
        return mid - 1;
    }

    if (mid + 1 <= r && v[mid + 1] == x) {
        return mid + 1;
    }
    if (v[mid] < x) {
        return search(v, mid + 2, r, x);
    } else {
        return search(v, l, mid - 2, x);
    }
    return -1;
}

int search_by_step(const vector<int> &v, int l, int r, int step, int x) {
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l)/2/step;
    if (v[mid] == x) {
        return mid;
    }
    if (v[mid] < x) {
        return search_by_step(v, mid + step, r, step, x);
    } else {
        return search_by_step(v, l, mid - step, step, x);
    }
    
}

int ss(const vector<int> &v, int l, int r, int x, int step) {
    for (int i = 0; i < step; ++i) {
        int index = search_by_step(v, l + i, r - r%step + i, step, x);
        if (index >= 0) {
            return index;
        }
    }
    return -1;
}

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    //vector<int> v = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    vector<int> v = {3, 2, 10, 4, 40};
    printv(v);

    //cout << "=> search 35" << endl;
    //cout << search(v, 0, v.size() - 1, 35) << endl;
    cout << "=> search 4" << endl;
    cout << search(v, 0, v.size() - 1, 4) << endl;


    //cout << "=> search 35" << endl;
    //cout << ss(v, 0, v.size() - 1, 35, 2) << endl;
    cout << "=> search 4" << endl;
    cout << ss(v, 0, v.size() - 1, 4, 2) << endl;

    //cout << "=> search 35" << endl;
    //cout << ss(v, 0, v.size() - 1, 35, 3) << endl;
    cout << "=> search 4" << endl;
    cout << ss(v, 0, v.size() - 1, 4, 3) << endl;


    return 0;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
