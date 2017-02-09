/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/05 19:53:04
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> kClosetElements(vector<int> &v, int x, int k) {
    vector<int>::iterator it = std::find(v.begin(), v.end(), x);
    if (v.end() == it) {
        return vector<int>();
    }
    vector<int> ret(k, 0);
    int count = 0;
    auto rit = std::next(it);
    //vector<int>::reverse_iterator lit = it;
    //auto lit = std::make_reverse_iterator(it);
    std::reverse_iterator<vector<int>::iterator> lit(it);
    cout << "lit => " << *lit << endl;
    for (;count < k && lit != v.rend() && rit != v.end(); ++count) {
        if (x - *lit < *rit - x) {
            ret[count] = *lit;
            lit = next(lit);
        } else {
            ret[count] = *rit;
            rit = next(rit);
        }
    }
    while (count < k && lit != v.rend()) {
        ret[count++] = *lit;
        lit = next(lit);
    }
    while (count < k && rit != v.end()) {
        ret[count++] = *rit;
        rit = next(rit);
    }
    return ret;
    
}

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int k = 4;
    vector<int> v = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    cout << "=> before" << endl;
    printv(v);

    cout << "=> after" << endl;
    printv(kClosetElements(v, 35, 4));


    return 0;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
