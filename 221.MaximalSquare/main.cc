//
// Created by alexkkk on 2020/4/4.
//

/**
Given a 2D binary matrix filled with 0's and 1's,
 find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/



#include "../util/dbg.h"


class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    auto rows = matrix.size();
    if (rows <= 0) return 0;
    auto cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int result = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (i == 0 || j == 0 || '0' == matrix[i][j]) {
          // dp[i][j]: 表示以[i,j]为右下定点的正方形的边长
          dp[i][j] = matrix[i][j] - '0'; // 这个细节简直了，魔鬼
        } else {
          dp[i][j] = min({dp[i-1][j - 1], dp[i][j - 1], dp[i-1][j]}) + 1;
        }
        result = max(result, dp[i][j]);
      }
    }
    return result * result;
  }
};

int main(int argc, char* argv[]) {



  return 0;
}