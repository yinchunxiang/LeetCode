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
 

void MergeSort(vector<int>& v, vector<int>::iterator left, vector<int>::iterator right) {
    if (v.end() == left || v.end() == right) {
        return;
    }
    auto mid = left +  distance(left, right)/2;
    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);
    vector<int> temp;
    for(auto it1 = left, it2 = mid + 1; it1 != mid + 1, it2 != v.end()) {
        if (*it1 < *it2) {
            temp.push_back(*it1);
        } else {
            temp.push_back(*it2);
        }
    }
    while (it1 != mid + 1) {
        temp.push_back(*it1++);
    }
    while (it2 != v.end()) {
        temp.push_back(*it2++);
    }

    return
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
