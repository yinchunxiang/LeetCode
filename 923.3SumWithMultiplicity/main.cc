//
// Created by alexkkk on 2019-06-30.
//

#include <vector>

using namespace std;


class Solution {
public:
  int threeSumMulti(vector<int>& A, int target) {
    // yinchunxiang@2019-06-30: 这种学习下
    const long long mod = 1e9 + 7;
    // yinchunxiang@2019-06-30: dp 含义 dp[i][v]: i个元素之和为v的个数
    vector<vector<long long>> dp(3, vector<long long>(target + 1, 0));
    for (auto x : A) {
      if(x>target) continue;
      // yinchunxiang@2019-06-30: 这个顺序正着可以吗？不行，这样依赖的已经变化了
      for (int i = target; i - x>= 0; i--) {
        // 注意更新顺序, 元素个数 2->1->0
        dp[2][i] += dp[1][i - x];  // 之前的方案都不包含x， 所以直接加
        dp[2][i] %= mod;
        dp[1][i] += dp[0][i-x];
        dp[1][i] %= mod;
      }
      dp[0][x]++;
    }
    return dp[2][target];

  }
};

