//
// Created by alexkkk on 2019-04-22.
//

int twoCitySchedCost(vector<vector<int>>& costs) {
  int N = cost.size() / 2;
  vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
  for (int i = 1; i <= N; ++i) {
    dp[i][0] = dp[i - 1] + costs[i - 1][0];
  }
  for (int j = 1; j <= N; ++j) {
    dp[0][j] = dp[0][j - 1] + costs[j - 1][1];
  }

  for (int i = 1; i <= N ; ++i) {
    for (int j = 1; j <= N; ++j) {
      dp[i][j] = min(dp[i][j - 1] + cost[i + j - 1][1], dp[i - 1][j] + cost[i + j - 1][0]) ;
    }
  }
  return dp[N][N];
}

