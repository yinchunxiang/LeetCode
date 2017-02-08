/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/08 20:17:31
 * @brief 
 * 
 **/ 

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int partition(vector<int> &v, int begin, int end) {
    int left_end = begin - 1;
    int pivot = v[end];
    for (int i = begin; i < end; ++i) {
        if (v[i] <= pivot) {
            swap(v[left_end + 1], v[i]);
            left_end += 1;
        }
    }
    swap(v[left_end + 1], v[end]);
    return left_end + 1;
}

struct Range {
    int begin;
    int end;
};

void quick_sort(vector<int> &v, int begin, int end) {
    queue<Range> q;
    q.push(Range{begin, end});
    while (!q.empty()) {
        auto &r = q.front();
        cout << "begin => " << r.begin << " end => " << r.end << endl;
        if (r.begin >= r.end) {
            q.pop();
            continue;
        }
        int mid = partition(v, r.begin, r.end);
        cout << "mid => " << mid << endl;
        q.push(Range{r.begin, mid - 1});
        q.push(Range{mid + 1, r.end});
        q.pop();
    }
    return;
}

int main(int argc, char *argv[]) {
    vector<int> v = {2, 6, 3, 12, 56, 8};
    //cout << "mid => " << partition(v, 0, v.size() - 1) << endl;


    cout << "=> before" << endl;
    printv(v);
    cout << endl;


    quick_sort(v, 0, v.size() - 1);

    cout << "=> after" << endl;
    printv(v);

    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
