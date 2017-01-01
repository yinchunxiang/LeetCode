/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/01/01 12:20:48
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// exp: 表示按照哪一位数字进行排序，从最低位开始，下标从0开始
// 第0位：exp = 10^0 
// 第1位：exp = 10^1 
// 第2位：exp = 10^2
// ……
// 第n位：exp = 10^n
void CountSort(vector<int> &v, int exp) {
    std::vector<int> count(10, 0);
    ///计算每个元素出现的次数
    for (auto i : v) {
        count[i/exp%10] += 1;
    }
    for (int i = 0; i < count.size(); ++i) {
        cout << i << " => " << count[i] << endl;
    }
    // 计算每个元素的最大位置    
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
    int size = (int)v.size();
    std::vector<int> output(size, 0);
    for (int i = size - 1; i >= 0; --i) {
        int radix = v[i]/exp%10;
        output[count[radix] - 1] = v[i];
        count[radix] -= 1;
    }
    swap(output, v);
    return;
}

void RadixSort(vector<int> &v) {
    auto it = std::max_element(v.begin(), v.end());
    if (it == v.end()) {
        return;
    }
    int max = *it;
    int exp = 1;
    while (max/exp > 0) {
        CountSort(v, exp);
        for_each(v.begin(), v.end(), [](int x) {cout << x << " ";});
        cout << endl;

        exp *= 10;
    }
    return;
}
void printv(const std::vector<int> &v) {
    for (auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    std::vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};
    RadixSort(v);
    printv(v);
    
    return 0;
}








/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
