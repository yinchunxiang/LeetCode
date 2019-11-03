//
// Created by alexkkk on 2019/11/3.
//


/**
 * 经典滑动窗口题目
 * 992.Subarrays With K Different Integers
 */

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    return AtMost(nums, k) - AtMost(nums, k - 1);
  }

  int AtMost(vector<int>& nums, int k) {
    int result = 0;
    int i = 0;
    int n = nums.size();
    for (int j = 0; j < n; ++j) {
      k -= nums[j] % 2;
      // 去掉 > k 的情况
      while (k < 0) {
        k += nums[i++] % 2;
      }
      result += j - i + 1;
    }
    return result;
  }


};