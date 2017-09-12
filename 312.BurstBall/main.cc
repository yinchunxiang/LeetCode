/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/12 18:38:20
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        vector<int> v(size + 2, 1);
        copy(nums.begin(), nums.end(), v.begin() + 1);
        vector<vector<int> > dp(v.size(), vector<int>(v.size(), 0));
        for (int k = 3; k <= v.size(); ++k) {
            for (int left = 0; left + k <= v.size(); ++left) {
                int right = left + k - 1;
                for (int i = left + 1; i < right; ++i) {
                    cout << "left: " << left << endl;;
                    cout << "right: " << right << endl;;
                    cout << "v["<< left <<"]: " << v[left] << endl;
                    cout << "v["<< right <<"]: " << v[right] << endl;
                    cout << "v["<< i <<"]: " << v[i] << endl;
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + v[left] * v[i] * v[right]);
                }
            }
        }
        return dp[0][v.size() - 1];
    }
};

int main(int argc, char *argv[]) {
    vector<int> input;
    input.push_back(3);
    input.push_back(1);
    input.push_back(5);
    input.push_back(8);
    Solution s;
    cout << s.maxCoins(input) << endl;
    
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
