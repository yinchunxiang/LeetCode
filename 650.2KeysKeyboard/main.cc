//
// Created by alexkkk on 2020/3/24.
//

#include "../util/dbg.h"

class Solution {
 public:
  int minSteps(int n) {
    vector<int> dp(n + 1);
    for (int i = 2; i <= n; ++i) {
      // copy 为1的情况
      dp[i] = i;
      // copy 为[2, i - 1]
      for (int j = i - 1; j > 1; j--) {
        if (i % j == 0) {
          // i / j: 包括1次copy以及 i/j - 1次paste
          dp[i] = dp[j] + (i / j);
          break;
        }
      }
    }
    return dp[n];
  }
};

int main(int argc, char* argv[]) {

  return 0;
}

