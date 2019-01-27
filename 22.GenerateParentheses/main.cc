//
// Created by yinchunxiang on 2019-01-27.
//

#include <vector>

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<unordered_set<string>> dp(n + 1, unordered_set<string>());
    dp[0].insert("");
    dp[1].insert("()");
    for (int i = 2; i <= n; ++i) {
      for (int left = 1; left < i; ++left) {
        for (const auto& l : dp[left]) {
          for (const auto& r : dp[i - left]) {
            dp[i].insert(l + r);
          }
        }
      }
      for (const auto& item : dp[i - 1]) {
        dp[i].insert("(" + item + ")");
      }

      //cout << "dp[" << i << "]:" << endl;
      //for (const auto& item : dp[i]) {
      //    cout << item << ",";
      //}
      //cout << endl;
    }
    return vector<string>(dp[n].begin(), dp[n].end());
  }
};