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

int next_gap(int gap) {
    gap = gap * 10 / 13;
    if (gap < 1) {
        return 1;
    }
    return gap;
}

/*
 * 是BubbleSort的改进版
 * BubbleSort是邻近的互相交换
 * CombSort提高了交换的距离，直到距离为1且没有交换为止
 */
void CombSort(std::vector<int>& v) {
    int n = v.size();
    int gap = n;

    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = next_gap(gap);
        swapped = false;
        for (int i = 0; i < n - gap; ++i) {
            if (v[i] > v[i + gap]) {
                std::swap(v[i], v[i + gap]);
                swapped = true;
            }
        }
    }
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
    std::vector<int> v = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    cout <<  "before sort => ";
    printv(v);
    CombSort(v);
    cout <<  "after sort => ";
    printv(v);

    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
