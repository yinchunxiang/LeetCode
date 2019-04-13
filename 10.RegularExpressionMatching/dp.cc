//
// Created by yinchunxiang on 2019-02-24.
//

/**
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
*/

/**
 *  1023. Camelcase Matching / 10. Regular Expression Matching / 44. Wildcard Matching
 *  这3道题目可以放到一起做，都可以通过类似的dp方法解决
 */
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    // 这个初始化非常重要
    // 为什么选这个做初始化，因为后面 j + 1 会用到 j - 1的值
    for (int j = 0; j < n; ++j) {
      if ('*' == p[j]) dp[0][j + 1] = dp[0][j - 1];
    }


    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if ('.' == p[j]) {
          dp[i + 1][j + 1] = dp[i][j];
          continue;
        }
        if (p[j] == s[i]) {
          dp[i + 1][j + 1] = dp[i][j];
          continue;
        }
        if ('*' == p[j]) {
          // 不相等， * 匹配0个
          if (s[i] != p[j - 1] && p[j - 1] != '.') {
            dp[i + 1][j + 1] = dp[i + 1][j - 1];
          } else {
            // 相等
            //dp[i][j - 2]: 匹配0个
            //dp[i][j - 1]: 匹配1个
            //dp[i + 1][j]: 匹配1 - N个
            //dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i + 1][j] || dp[i][j + 1];

            //dp[i][j - 1]: 匹配1个或者多个，所以下面这个式子就可以了
            dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i][j + 1];
          }
        }
      }
    }
    return dp[m][n];

  }
};

