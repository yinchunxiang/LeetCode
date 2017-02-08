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

const int kRange = 256;

void CountSort(std::vector<int>& v) {
    int size = v.size();
    vector<int> count(kRange, 0);
    for (int i = 0; i < size; ++i) {
        count[v[i]] += 1;
    }
    for (int i = 1; i < kRange; ++i) {
        count[i] += count[i - 1];
    }
    vector<int> output(size, 0);
    for (int i = 0; i < size; ++i) {
        int index = count[v[i]] - 1;
        output[index] = v[i];
        count[v[i]] -= 1;
    }
    v.swap(output);
    return;

}

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}
 
int main(int argc, const char *argv[])
{
    std::vector<int> v = {8, 4, 1, 56, 3, 44, 23, 6, 28, 0};
    cout <<  "before sort => ";
    printv(v);
    CountSort(v);
    cout <<  "after sort => ";
    printv(v);

    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
