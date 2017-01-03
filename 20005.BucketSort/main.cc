/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/01/03 23:17:57
 * @brief 
 * 
 **/ 

#include <iostream>

#include <vector>

using namespace std;

void BucketSort(vector<float> &v) {
    int n= (int)v.size();
    vector<vector<float>> b(n, vector<float>());
    for (auto i : v) {
        int index = n * i;
        b[index].push_back(i);
    }
    for (auto & v : b) {
        sort(v.begin(), v.end());
    }

    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < b[i].size(); ++j) {
            v[index++] = b[i][j];
        }
    }
}
void printv(const std::vector<float> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    vector<float> input = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
    BucketSort(input);
    printv(input);
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
