/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/01/05 00:58:19
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;

void print_unsorted_subarray(const std::vector<int> &v) {
    int size = v.size();
    int begin = 0;
    int end = size - 1;
    for (int i = 0; i < size - 1; ++i) {
        if (v[i] > v[i + 1]) {
            begin = i;
            break;
        }
    }
    if (0 == begin) {
        cout << "complete array is sorted" << endl;
        return;
    }
    for (int i = size - 1; i > 0; --i) {
        if (v[i] < v[i - 1]) {
            end = i;
            break;
        }
    }
    
    int min = v[begin];
    int max = v[end];
    for (int i = begin; i <= end; ++i) {
        if (v[i] < min) {
            min = v[i];
        }
        if (v[i] > max) {
            max = v[i];
        }
    }

    for (int i = 0; i < begin; ++i) {
        if (v[i] > min) {
            begin = i;
            break;
        }
    }
    for (int i = size - 1; i > end; --i) {
        if (v[i] < max) {
            end = i;
            break;
        }
    }
    for (int i = begin; i <= end; ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main(int argc, const char *argv[])
{
    std::vector<int> v = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    print_unsorted_subarray(v);

    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
