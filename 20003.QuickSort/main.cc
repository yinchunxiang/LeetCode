/****************************************************************************G
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2016/12/27 23:10:02
 * @brief 
 * 
 **/ 


#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int> &v, int low, int high) {
    int x = v[high]; // v[high] as pivot
    int i = low - 1; // largest <= pivot
    for (int j = low; j < high; ++j) {
        if (v[j] <= x) {
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1],v[high]);
    return i + 1;
}

void QuickSort(vector<int> &v, int low, int high) {
    if (low >= high) {
        return;
    }
    int pivot = partition(v, low, high);
    QuickSort(v, low, pivot - 1);
    QuickSort(v, pivot + 1, high);
}

void printv(const vector<int>& v, int size) {
    for (int i = 0; i < size; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

 
int main() {
    int cases = 0;
    cin >> cases;

    vector<int> v(1000, 0);
    for (int i = 0; i < cases; ++i) {
        int size = 0;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            cin >> v[j];
        }
        for (int j = 0; j < size; ++j) {
            cout <<  v[j] << " ";
        }
        cout << endl;
        QuickSort(v, 0, size - 1);
        printv(v, size);
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
