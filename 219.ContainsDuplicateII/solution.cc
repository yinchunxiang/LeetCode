/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/11 09:40:01
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
 
class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, vector<int>> pos_vec_map;
            int N = nums.size(); 
            for (int i = 0;i < N; ++i) {
                pos_vec_map[nums[i]].push_back(i);
            }
            for (auto p : pos_vec_map) {
                if (p.second.size() <= 1) {
                    continue;
                }
                auto &v = p.second;
                for (int i = 1; i < v.size(); ++i) {
                    if (v[i] - v[i - 1] <= k) {
                        return true;
                    }
                }
            }
            return false;
        }

};

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {0,1,2,3,4,5,0};
        printv(input);
        cout << s.containsNearbyDuplicate(input, 5)  << endl;
        
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
