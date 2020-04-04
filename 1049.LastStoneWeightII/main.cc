//
// Created by alexkkk on 2020/3/24.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/**
 *
1049. Last Stone Weight II
Medium

387

18

Add to List

Share
We have a collection of rocks, each rock has a positive integer weight.

Each turn, we choose any two rocks and smash them together.
 Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed,
 and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.
 Return the smallest possible weight of this stone (the weight is 0 if there are no stones left.)



Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 100

 */

#include "../util/dbg.h"

/*
short dp[30][6000] = {};
int lastStoneWeightII(vector<int>& A, int s = 0, int i = 0) {
  if (i == A.size()) return s < 0 ? 100 : s;
  if (dp[i][s + 3000] == 0) {
    dp[i][s + 3000] = 1 + min( lastStoneWeightII(A, s + A[i], i + 1),
                               lastStoneWeightII(A, s - A[i], i + 1));
  }
  return dp[i][s + 3000] - 1;
}

int lastStoneWeightII(vector<int>& A) {
  unordered_set<int> s1 = { 0 };
  for (auto i : A) {
    unordered_set<int> s2;
    for (auto j : s1) s2.insert({ j - i, j + i });
    swap(s1, s2);
  }
  return abs(*min_element(begin(s1), end(s1), [](int i, int j) { return abs(i) < abs(j); }));
}

int lastStoneWeightII(vector<int> A) {
  bitset<1501> dp = {1};
  int sumA = 0;
  for (int a : A) {
    sumA += a;
    for (int i = min(1500, sumA); i >= a; --i)
      dp[i] = dp[i] + dp[i - a];
  }
  for (int i = sumA / 2; i > 0; --i)
    if (dp[i]) return sumA - i - i;
  return 0;
}

class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    // 01背包问题
    // dp[i][j] 表示从前i件物品中取若干件放到容量为j的背包里能达到的最大价值
    // 第i个物品在里面的情况： dp[i - 1][j - w[i]] + w[i]:
    // 第i个物品不在里面的情况： dp[i - 1][j]
    // 转移表达式：dp[i][j] = max{dp[i - 1][j - w[i]] + w[i], dp[i - 1][j]}
    int dp[31][1501] = {};
    for (int i = 1; i <= stones.size(); ++i) {
      for (int j = 1; j <=1500; ++j) {
        if (j - stones[i - 1] < 0) continue;
        dp[i][j] = max(dp[i][j - stones[i]] + stones[i], dp[i - 1][j]);
      }
    }


  }
};
*/

class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    // 01背包问题
    // dp[i][j] 表示从前i件物品中取若干件设置为负数放到容量为j的背包里能达到的最小绝对值
    // 第i个物品设置为负数的情况： dp[i - 1][j - w[i]] - v[i]:
    // 第i个物品不设置为负数的情况： dp[i - 1][j - w[i]] + v[i];
    // 转移表达式：dp[i][j] = max{abs(dp[i - 1][j - w[i]] + v[i]), abs(dp[i - 1][j - w[i]] + v[i])}
    auto sum = std::accumulate(stones.begin(), stones.end(), 0);
    std::cout << "sum:" << sum << std::endl;
    auto count = stones.size();
    auto capacity = sum >> 1;
    vector<vector<int>> dp(count + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= count; ++i) {
      for (int j = 1; j <= capacity; ++j) {
        if (j - stones[i - 1] < 0) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = max(dp[i - 1][j - stones[i - 1]] + stones[i - 1], dp[i - 1][j]);
        }
      }
      std::cout << "dp["<< i << "][" << capacity << "]:" << dp[i][capacity] << std::endl;
    }
    return sum - dp[count][capacity] - dp[count][capacity];
  }
};



int main(int argc, char* argv[]) {
  Solution s;
//  vector<int> stones = {2,7,4,1,8,1};
  vector<int> stones = {28,33,34,40,31,7,27};
  cout << s.lastStoneWeightII(stones) << endl;
  return 0;
}

