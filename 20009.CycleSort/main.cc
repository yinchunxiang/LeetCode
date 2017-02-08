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

int find_target_position(const std::vector<int> &v, int cur_pos) {
    int target_pos = cur_pos;
    int size = v.size();
    for (int j = cur_pos + 1; j < v.size(); ++j) {
        if (v[cur_pos] > v[j]) {
            target_pos += 1;
        }
    }
    if (target_pos == cur_pos) {
        return target_pos;
    }
    while (v[cur_pos] == v[target_pos]) {
        target_pos += 1;
    }

    return target_pos;

}


void CycleSort(std::vector<int>& v) {
    int size = v.size();
    for (int i = 0; i < size - 1; ++i) {
        int cur_pos = i;
        int target_pos = find_target_position(v, cur_pos);

        while (cur_pos != target_pos) {
            swap(v[cur_pos], v[target_pos]);
            target_pos = find_target_position(v, cur_pos);
        }
    }
}

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    std::vector<int> v = {1, 8, 3, 9, 10, 10, 2, 4};
    cout <<  "before sort => ";
    printv(v);
    CycleSort(v);
    cout <<  "after sort => ";
    printv(v);

    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
