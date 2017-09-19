/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/14 23:10:22
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <numeric>


using namespace std;
 
class Solution {
public:
    void dfs(int &minSum, vector<int> indexList, int m, vector<int> &nums) {
        int size = indexList.size();
        if (size == m) {
            cout << "----------------->indexList begin" << endl;
            for (auto index : indexList) {
                cout << index << " ";
            }
            cout << endl;
            cout << "----------------->indexList end" << endl;
            int end = nums.size();
            int sum = 0;
            for (int i = indexList.size() - 1; i >= 0; --i) {
                cout << "i: " << i << endl;
                int start = indexList[i];
                sum = max(sum, accumulate(nums.begin() + start, nums.begin() + end, 0));
                cout << "sum: " << sum << endl;
                end = start;
            }
            minSum = min(minSum, sum);
            return;
        }
        for (int j = indexList[size - 1] + 1; j < nums.size() - m + 3 - size ; ++j) {
            cout << "j => " << j << endl;
            indexList.push_back(j);
            dfs(minSum, indexList, m, nums);
            indexList.pop_back();
        }
    }

    int splitArray(vector<int>& nums, int m) {
        int minSum = numeric_limits<int>::max();
        vector<int> indexList(1, 0);
        dfs(minSum, indexList, m, nums);
        return minSum;
    }
};


int main(int argc, char *argv[])
{
    vector<int> input = {7,2, 5, 10, 8};
    int m = 2;
    Solution s;
    cout << s.splitArray(input, 2) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
