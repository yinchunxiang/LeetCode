//
// Created by alexkkk on 2020/4/4.
//


/**
You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
*/

#include <vector>
#include "../util/dbg.h"

using namespace std;


class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    // dp[i]: 表示容量 i 需要的最小金币数
    // dp[i] = min{dp[i - coins[j]] + 1}  0 <= j < M;
    vector<int> dp(amount + 1, amount + 1);

    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < coins.size(); ++j) {
        if (i < coins[j]) continue;
        dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }

  int coinChangeV2(vector<int>& coins, int amount) {
    int M = coins.size();
    vector<vector<int>> dp(M + 1, vector<int>(amount + 1, amount+1));
    // dp[i][j]:表示i种金币达到额度j所需要的金币的最小个数
    // dp[i -1][j]: 不需要第i种金币，只需要前 i-1 中金币的情况
    // dp[i][j - k * coins[i]] + k: 表示需要 1 - N个 第 i 中金币的情况
    // dp[i][j] = min(dp[i -1][j], dp[i][j - k * coins[i]] + k)  0 < k <= j / coins[i]
    // 会发现 dp[i][j - 1 * coins[i]] + 1 >= dp[i
    for (int i = 0; i <= M; ++i) {
      dp[i][0] = 0;
    }
    for (int i = 1; i <= M; ++i) {
      for (int j = 1; j <= amount; ++j) {
        if (j < coins[i - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          // dp[i][j - coins[i]]： 表示了最少包含一个coins[i - 1] 的情况
          dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
        }
        cout << "dp[" << i << "][" << j << "]:" << dp[i][j] << endl;
      }
      cout << "---> dp[" << i << "][" << amount << "]:" << dp[i][amount] << endl;
    }
    return dp[M][amount] > amount ? -1 : dp[M][amount];
  }


  int coinChangeV3(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (auto c : coins) {
      for (int j = c; j <= amount; ++j) {
        dp[j] = min(dp[j], dp[j - c] + 1);
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }

};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> coins {1, 2, 5};

  dbg(coins);
  dbg(s.coinChangeV2(coins, 11));

  return 0;
}