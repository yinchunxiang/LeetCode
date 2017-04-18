/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/08 22:47:41
 * @brief 
 * 
 **/ 

#include <unordered_map>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

//注意返回的index是从0开始，还是从1开始
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, list<int>> indexes;
    for (int i = 0; i < nums.size(); ++i) {
        int rest = target - nums[i];
        if (indexes.end() != indexes.find(rest)) {
            return {i, indexes[rest]};
        }
        indexes[nums[i]] = i;
    }
    return {};
}

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    vector<int> nums{3, 2, 4};
    auto v = twoSum(nums, 6);
    printv(v);
    
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
