//
// Created by yinchunxiang on 2019-04-12.
//

/**
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
 */

/**
 *  1023. Camelcase Matching / 10. Regular Expression Matching / 44. Wildcard Matching
 *  这3道题目可以放到一起做，都可以通过类似的dp方法解决
 */

/**
 * Time Complexity: O(M*N)
 * Space Complexity: O(M*N)
 */

class Solution {
 public:
  bool isMatch(string s, string p) {
    int ss = s.size();
    int ps = p.size();
    vector<vector<bool>> dp(ss + 1, vector<bool>(ps + 1, false));
    dp[0][0] = true;
    for (int j = 0; j < ps; ++j) {
      if ('*' == p[j]) {
        dp[0][j + 1] = dp[0][j];
      }
    }
    for (int i = 0; i < ss; ++i) {
      for (int j = 0; j < ps; ++j) {
        if ('a' <= p[j] && p[j] <= 'z') {
          dp[i + 1][j + 1] = (s[i] == p[j] && dp[i][j]);
          continue;
        }
        if ('?' == p[j]) {
          dp[i+1][j + 1] = dp[i][j];
          continue;
        }
        if ('*' == p[j]) {
          //匹配0次 或 1-N次
          dp[i+1][j+1] = dp[i + 1][j] || dp[i][j + 1];
        }

      }
    }
    return dp[ss][ps];

  }
};