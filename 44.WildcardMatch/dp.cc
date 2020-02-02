//
// Created by alexkkk on 2020/1/30.
//

class Solution {
 public:

  /**
   * Time Complexity: O(M * N)
   * Space Complexity: O(M * N)
   */
  bool isMatch(string s, string p) {
    if (s.empty() && p.empty()) return true;
    if (p.empty()) return false;
    if (s.empty()) {
      for (auto c : p) {
        if (c != '*') return false;
      }
      return true;
    }
    int M = s.size();
    int N = p.size();
    // dp[i][j] = dp[i - 1][j - 1] if (s[i] == p[j] || '?' == p[j] || *)
    bool dp[M + 1][N + 1];
    fill_n(&dp[0][0], (M + 1)* (N + 1), false);
    dp[0][0] = true;
    for (int i = 0; i <= M; ++i) {
      for (int j = 1; j <= N; ++j) {
        // * 匹配之前的长度 0 - i
        if ('*' == p[j - 1]) {
//          for (int k = 0; k <= i; ++k) {
//            if (dp[k][j - 1]) {
//              dp[i][j] = true;
//              break;
//            }
//          }
            // 只要dp[0][j] - dp[i - 1][j] 中任意一个为true，就能保证 dp[i - 1][j] 为 true
            // 这个是个重要的 trick
            dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
        } else if ('?' == p[j - 1]) {
          dp[i][j] = i > 0 ? dp[i - 1][j - 1] : false;
        } else {
          dp[i][j] = i > 0 ? s[i - 1] == p[j - 1] && dp[i - 1][j - 1] : false;
        }

      }
    }

    return dp[M][N];
  }

  // 贪心的方法
  bool Greedy(string s, string p) {
    int m = s.length(), n = p.length();
    int i = 0, j = 0, asterisk = -1, match;
    while (i < m) {
      if (j < n && p[j] == '*') {
        match = i;
        asterisk = j++;
      }
      else if (j < n && (s[i] == p[j] || p[j] == '?')) {
        i++;
        j++;
      }
      else if (asterisk >= 0) {
        i = ++match;
        j = asterisk + 1;
      }
      else return false;
    }
    while (j < n && p[j] == '*') j++;
    return j == n;
  })
};
