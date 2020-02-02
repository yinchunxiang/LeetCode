//
// Created by alexkkk on 2020/2/2.
//

int dp[1001] = {};

int maxJumps(vector<int>& arr, int d, int res = 1) {
  for (auto i = 0; i < arr.size(); ++i) {
    res = max(res, dfs(arr, i, d));
  }
  return res;
}

// 从 i 开始的能访问的下标的个数
int dfs(vector<int>& arr, int i, int d, int res = 1) {
  if (dp[i]) return dp[i];
  int N = arr.size();
  // 往右在 d 范围内找比当前值小的
  for (auto j = i + 1; j <= min(i + d, N - 1) && arr[j] < arr[i]; ++j) {
    res = max(res, 1 + dfs(arr, j, d));
  }
  // 往左在 d 范围内找比当前值小的
  for (auto j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; --j) {
    res = max(res, 1 + dfs(arr, j, d));
  }
  // 左右没有比当前值小的
  dp[i] = res;
  return res;
}