/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2016/12/25 16:46:50
 * @brief 
 * 
 **/ 

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


void MergeSort(vector<int>& v, vector<int>::iterator left, vector<int>::iterator right) {
    if (right == left || v.end() == left) {
        return;
    }
    auto mid = left +  distance(left, right)/2;
    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);
    vector<int> temp;
    auto it1 = left, it2 = mid + 1;
    while(it1 != std::next(mid) && it2 != v.end()) {
        if (*it1 < *it2) {
            temp.push_back(*it1++);
        } else {
            temp.push_back(*it2++);
        }
    }
    while (it1 != std::next(mid)) {
        temp.push_back(*it1++);
    }
    while (it2 != v.end()) {
        temp.push_back(*it2++);
    }

    for (auto it = temp.begin(); it!= temp.end(); ++it) {
        *left = *it;
        ++left;
    }

    return;
}

void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char *argv[])
{
    vector<int> v = {12, 11, 13, 5, 6, 7};
    MergeSort(v, v.begin(), v.end());
    printv(v);
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
