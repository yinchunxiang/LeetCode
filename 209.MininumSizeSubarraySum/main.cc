#include <vector>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int l = 0;
    int r = 0;
    int n = nums.size();
    int sum = 0;
    int len = INT_MAX;
    while (r < n) {
      sum += nums[r++];
      while (sum >= s) {
        len = min(len, r - l);
        sum -= nums[l++];
      }
    }
    return len == INT_MAX ? 0 : len;
  }

  int min(int s, vector<int>& nums) {
    vector<int> sums;
    int sum = 0;
    for (auto num : nums) {
      sum += num;
      sums.push_back(sum);
    }
    int len = INT_MAX;
    for (int i = 0; i < sums.size(); ++i) {
      if (sums[i] < s) continue;
      int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
      len = min(len, i - j + 1);
    }
    return len == INT_MAX ? 0 : len;
  }
};