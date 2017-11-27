//
// Created by yinchunxiang on 27/11/2017.
//

#include <vector>

using namespace std;

class Solution {
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        size_t n = nums.size();
        if (k * 3 >= n) {
            return {0, k, 2*k};
        }
        // n + 1
        vector<int> sumVec(0);
        for (auto i : nums) {
            sumVec.push_back(sumVec.back() + i);
        }
        vector<int> left(n - k + 1, 0);
        for (int i = 0; i < n - k + 1; ++i) {
            left[i] = sumVec[i + k] - sumVec[i];
        }

    }
};