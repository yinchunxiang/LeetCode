//
// Created by alexkkk on 2020/3/22.
//

#include <vector>
#include <unordered_set>
#include "../util/dbg.h"
using namespace std;

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(366, 0);
    unordered_set<int> holidays (days.begin(), days.end());
    int result = std::numeric_limits<int>().max();
    // 表示上一个旅行日
    int prev_day = -1;
    for (int i = 1; i < 366; ++i) {
      // 超过最后一个旅行日就不需要再计算了
      if (i > days.back()) break;
      if (holidays.count(i) <= 0) {
        dp[i] = dp[i - 1];
        continue;
      }
      if (i == 29) {
        dbg(i);
      }
      // 1-day
      dp[i] = dp[i - 1] + costs[0];
      // 7-day
      // 最前面那天就应该是最小的, 所以优化后就是
      // dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1];
      for (int k = i - 6; k <= i; ++k) {
        if (k - 1 < 0) continue;
        if (i != k && k > prev_day ) continue;
        dp[i] = min(dp[i], dp[k - 1] + costs[1]);
      }
      // 30-day
      // 最前面那天就应该是最小的, 所以优化后就是
      // dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[1];
      for (int k = i - 29; k <= i; ++k) {
        if (k - 1 < 0) continue;
        dbg(k);
        if (i != k && k > prev_day ) continue;
        if (k == 1) {
          dbg(i);
          dbg(dp[k-1]);
          dbg(dp[i]);
        }
        dp[i] = min(dp[i], dp[k - 1] + costs[2]);
      }
      dbg(dp[i]);
      prev_day = i;
    }
    return dp[days.back()];
  }
};


int mincostTickets(vector<int>& days, vector<int>& costs) {
  unordered_set<int> travel(begin(days), end(days));
  int dp[366] = {};
  for (int i = 1; i < 366; ++i) {
    // 不是 travel day
    if (travel.find(i) == travel.end()) {
      dp[i] = dp[i - 1];
    }
    else {
      dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]}
    });
  }
  return dp[365];
}

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> days = {1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29};
  vector<int> costs = {3,14,50};
  dbg(s.mincostTickets(days, costs));
  return 0;
}
