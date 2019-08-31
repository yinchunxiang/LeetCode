//
// Created by alexkkk on 2019-06-30.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
//  string lcs(const string& str1, const string& str2) {
  string lcs(string& str1, string& str2) {
    int m = str1.size();
    int n = str2.size();
    //string dp[m + 1][n + 1] = {""};
    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        cout << str1[i - 1] << " -> " << str2[j - 1] << endl;
        if (str1[i - 1] == str2[j - 1]) {
          cout << "--> dp: " << dp[i - 1][j - 1] + str1[i - 1] << endl;
//          dp[i][j] = (dp[i - 1][j - 1] + std::to_string(str1[i - 1]));
          dp[i][j] = (dp[i - 1][j - 1] + str1[i - 1]);
          cout << "!!!!!!!! dp[" << i << "][" << j << "]: {" << dp[i][j]  << "}" << endl;
        } else if (dp[i][j - 1].size() > dp[i-1][j].size()) {
          dp[i][j] = dp[i][j - 1];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
        cout << "-----> dp[" << i << "][" << j << "]: {" << dp[i][j]  << "}" << endl;
      }
    }
    return dp[m][n];
  }
  string lcs1(string& A, string& B) {
    int n = A.size(), m = B.size();
    vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (A[i] == B[j])
          dp[i + 1][j + 1] = dp[i][j] + A[i];
        else
          dp[i + 1][j + 1] = dp[i + 1][j].size() > dp[i][j + 1].size() ?  dp[i + 1][j] : dp[i][j + 1];
    return dp[n][m];
  }
  string shortestCommonSupersequence(string str1, string str2) {
    // 1. 先求最大公约数
    auto str = lcs(str1, str2);
    cout << "lcs: " << str << endl;
    int idx1 = 0;
    int idx2 = 0;
    string result;
    for (auto c : str) {
      while (c != str1[idx1]) {
        result += str1[idx1++];
      }
      while (c != str2[idx2]) {
        result += str2[idx2++];
      }
      result += c;
      idx1 += 1;
      idx2 += 1;
    }
    return result + str1.substr(idx1) + str2.substr(idx2);

  }
};

int main(int argc, char* argv[]) {
  Solution s;
  string str1 = "abac";
  string str2 = "cab";
  cout << s.lcs(str1, str2) << endl;
  cout << s.lcs1(str1, str2) << endl;
  return 0;
}
