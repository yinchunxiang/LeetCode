/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/01/04 23:42:45
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>

using namespace std;

void ShellSort(vector<int> &v) {
    int n = (int)v.size();
    // 步长/2逐渐递减到1
    for (int step = n/2; step > 0; step /= 2) {
        for (int i = step; i < n; ++i) {
            int temp = v[i];
            int j = i;
            // 插入排序
            while (j - step >= 0 && v[j - step] > temp) {
                v[j] = v[j - step];
                j -= step;
            }
            v[j] = temp;
        }
    }
}

void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

 
int main(int argc, const char *argv[]) {
    vector<int> input = {12, 34, 54, 2, 3};
    cout << "before sort =>";
    printv(input);
    ShellSort(input);
    cout << "after sort =>";
    printv(input);
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
