//
// Created by yinchunxiang on 2019-04-08.
//

/**
 * dp思路：
 * dp[i][j]:
 *      1. query[i] == pattern[j], dp[i][j] = dp[i - 1][j - 1];
 *      2. query[i] != pattern[j]
 *          2.1 query[i] 是大写字母，直接false
 *          2.2 query[i] 是小写字母， dp[i][j] = dp[i - 1][j];
 */

class Solution {
public:
  bool match(const std::string &query, const std::string &pattern) {
    int query_size = query.size();
    int pattern_size = pattern.size();
    // 注意申请数组的大小，这个是实现时候的优化
    vector <vector<bool>> dp(query_size + 1, vector<bool>(pattern_size + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < query_size; ++i) {
      // 注意这个判断， query和pattern会有开始是小写字母的情况
      // 因为pattern的长度为0， 所以其实就是推到的情况2: query[i] != pattern[j]
      // 然后根据dp推导式子去获得结果，不要臆想
      if (islower(query[i])) { // query[i]是小写字母
        dp[i + 1][0] = dp[i][0];
      } else {
        dp[i + 1][0] = false; // query[i]是大写字母
      }
    }

    for (int i = 0; i < query_size; ++i) {
      for (int j = 0; j < pattern_size; ++j) {
        if (query[i] == pattern[j]) {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (islower(query[i])) {
          dp[i + 1][j + 1] = dp[i][j + 1];
        } else {
          dp[i + 1][j + 1] = false;
        }
      }
    }
    return dp[query_size][pattern_size];
  }

  vector<bool> camelMatch(vector <string> &queries, string pattern) {
    vector<bool> result;
    for (const auto &query : queries) {
      result.push_back(match(query, pattern));
    }
    return result;
  }
}