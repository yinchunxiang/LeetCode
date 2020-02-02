//
// Created by alexkkk on 2020/2/2.
//

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // 正常情况
    //T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
    //T[i][k][1] = max(T[i-1][k][1], T[i-1][k][0] - prices[i])

    // 带有cool_down
    //T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
    //T[i][k][1] 的表达式变化如下：
    //* 假设在 i-1 天没有卖出, 则应该是:
    //  T[i - 1][k][0] - prices[i] == T[i - 2][k][0] - prices[i]
    //* 假设在 i-1 天有卖出, 也应该是:  T[i - 2][k][0] - prices[i]
    // 所以： T[i][k][1] = max(T[i-1][k][1], T[i-2][k][0] - prices[i])
    int N = prices.size();
    int pre_ik0 = 0;
    int ik0 = 0;
    int ik1 = INT_MIN;
    for (int i = 0; i < N; ++i) {
      int old_pre_ik0 = pre_ik0;
      pre_ik0 = ik0;
      ik0 = max(ik0, ik1 + prices[i]);
      ik1 = max(ik1, old_pre_ik0 - prices[i]);
    }
    return ik0;

  }
};
