/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/04/26 23:38:32
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;

void printv(vector<int>& v) {
    cout << "{ " ;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << "} " ;
    cout << endl;
}


class Solution {
public:
    int solve(vector<int>& nums) {
        /// write your code here
        int n = nums.size();
        if (n <= 1) return n;
        vector<int> tail;
        tail.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            cout << "start to process: " << nums[i] << endl;
            auto it = find_if(tail.begin(), tail.end(), [nums, i](int item) { return item >= nums[i];});
            if (it != tail.end()) {
                cout << "find : " << *it << endl;
                *it = nums[i];
            } else {
                tail.push_back(nums[i]);
            }
            printv(tail);
        }
        return tail.size();
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {1, 3, 2, 4};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
