/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/05 11:46:06
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
 
class Solution {
    public:
        int findPairs(vector<int>& nums, int k) {
            if (k < 0) {
                return 0;
            }
            unordered_map<int, int> counts;
            for (int i = 0; i < nums.size(); ++i) {
                counts[nums[i]] += 1;
            }

            sort(nums.begin(), nums.end());


            int result = 0;

            for (int i = 0; i < nums.size(); ++i) {
                if (i >= 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int another = nums[i] + k;
                auto it = counts.find(another);
                if (another == nums[i]) {
                    if (it->second >=2) {
                        counts[nums[i]] -= 2;
                        ++result;
                    }
                } else if(it != counts.end() && it->second > 0) {
                    ++result;
                    counts[nums[i]] -= 1;
                    it->second -= 1;
                }
            }
            return result;
        }

};

int main(int argc, char *argv[]) {
    {
        Solution sol;
        vector<int> v = {               3, 1, 4, 1, 5 };
        cout << sol.findPairs(v, 2) << endl;
    }
    {
        Solution sol;
        vector<int> v = {1, 3, 1, 5, 4};
        cout << sol.findPairs(v, 0) << endl;
    }
    {
        Solution sol;
        vector<int> v = {1, 2, 3, 4, 5};
        cout << sol.findPairs(v, 1) << endl;
    }
    {
        Solution sol;
        vector<int> v = {1, 1, 1, 1, 1};
        cout << sol.findPairs(v, 0) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
