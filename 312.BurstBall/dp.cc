//
// Created by alexkkk on 2019-04-13.
//


/**
 * 思路：
 * 当选择i作为第一个点爆的气球走不通的时候，
 * 再反过来想想i作为最后一个被点爆的气球的情况
 *
 * i <= k <= j, k作为最后一个被点爆的气球
 * dp[i][j] = max { dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1}
 */

#include <vector>
#include <iostream>

using namespace std;

/**
 * Time Complexity: O(N * N * N)
 * Space Complexity: O(N * N)
 */

class Solution {
public:
  int GetValue(const vector<int>& nums, int index) {
    if (index < 0 || index >= nums.size()) return 1;
    return nums[index];
  }
  int maxCoins(vector<int>& nums) {
    // 把边角条件一定要考虑下
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int j = 0; j < n; ++j) {
      // 注意 i 的顺序，[0, N]是最大范围，一般是最后一个被计算得出的
      for (int i = j; i >= 0; --i) {
        for (int k = i; k <= j; ++k) {
          int coins = nums[k] * GetValue(nums, i - 1) * GetValue(nums, j + 1);
          coins += (k == i ? 0 : dp[i][k - 1]);
          coins += (k == j ? 0 : dp[k + 1][j]);
          dp[i][j] = max(dp[i][j], coins);
        }
        cout << "(" << i << "," << j << ") => " << dp[i][j] << endl;

      }
    }
    return dp[0][n - 1];
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