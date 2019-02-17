//
// Created by alexkkk on 2019-02-08.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
  int GetMinCut(const string& s, const vector<vector<bool>>& dp, vector<vector<int>>& memo,  int start, int end) {
    if (memo[start][end] >= 0) return memo[start][end];
    if (dp[start][end]) {
      memo[start][end] = 0;
      return 0;
    }
    int result = end - start;
    for (int i = start; i < end; ++i) {
      if (dp[start][i] && dp[i + 1][end]) return 1;
      if (!dp[start][i]) continue;
      int cuts = GetMinCut(s, dp, memo, start, i) + GetMinCut(s, dp, memo, i + 1, end) + 1;
      result = min(result, cuts);
    }
    cout << "start:"  << start << " end:" << end << " result:" << result << endl;
    memo[start][end] = result;
    return result;
  }

  int minCut(string s) {
    int n = s.size();
    if (n < 2) return 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    vector<int> cuts(n + 1, n);
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i <= j; ++i) {
        if (s[i] == s[j] && (j - i < 2 || dp[i+1][j - 1]) {
          dp[i][j] = true;
          int len = j - i + 1;
          cuts[len] = min(cuts[len], cuts[i + 1] + 1)

        }
        cout << "dp[" << i << "]["<< j <<"]:" << dp[i][j] << endl;
      }
    }
    vector<vector<int>> memo(n, vector<int>(n, -1));

    return GetMinCut(s, dp, memo, 0, n - 1);
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  {
    std::string input = "eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj";
//    std::string input = "ab";
    cout << s.minCut(input) << endl;
  }
  return 0;
}


