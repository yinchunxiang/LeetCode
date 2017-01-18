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
    if (right == std::next(left)) {
        return;
    }
    auto mid = left +  distance(left, right)/2;
    for (auto it = left; it != mid; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = mid; it != right; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    MergeSort(v, left, mid);
    MergeSort(v, mid, right);
    vector<int> temp;
    auto it1 = left;
    auto it2 = mid;
    while(it1 != mid && it2 != right) {
        cout << "*it1 => " << *it1 << endl;
        cout << "*it2 => " << *it1 << endl;
        if (*it1 < *it2) {
            temp.push_back(*it1++);
        } else {
            temp.push_back(*it2++);
        }
    }
    while (it1 != mid) {
        temp.push_back(*it1++);
    }
    while (it2 != right) {
        temp.push_back(*it2++);
    }

    for (auto it = temp.begin(); it!= temp.end(); ++it) {
        *left++ = *it;
    }

    return;
}

void merge_sort(vector<int>& v, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left)/2;
    merge_sort(v, left, mid);
    merge_sort(v, mid + 1, right);
    int n = right - left + 1;
    vector<int> temp(n, 0);
    int index = 0;
    int l = left;
    int r = mid + 1;
    for (; l <= mid && r <= right; ) {
        if (v[l] <= v[r]) {
            temp[index ++] = v[l++];
        } else {
            temp[index ++] = v[r++];
        }
    }
    while (l <= mid) {
        temp[index ++] = v[l++];
    }
    while (r <= right)  {
        temp[index ++] = v[r++];
    }
    for (int i = 0; i < n; ++i) {
        v[left ++ ] = temp[i];
    }
}

void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char *argv[])
{
    vector<int> v = {12, 11, 13, 5, 6, 7, 4, 3, 2, 1};
    cout << "before sort =>";
    printv(v);
    MergeSort(v, v.begin(), v.end());
    //merge_sort(v, 0, 9);
    cout << "after sort =>";
    printv(v);
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
