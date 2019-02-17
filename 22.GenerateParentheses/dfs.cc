//
// Created by yinchunxiang on 2019-01-27.
//

class Solution {
 public:
  void dfs(unordered_set<string>& global, string local, int rest_left, int rest_right) {
    if (0 == rest_left && 0 == rest_right) {
      global.insert(local);
      return;
    }
    if (rest_left < 0 || rest_right < 0) return;
    if (rest_right < rest_left) return;
    // use left
    dfs(global, local + "(", rest_left - 1, rest_right);
    // use right
    dfs(global, local + ")", rest_left, rest_right - 1);
  }
  vector<string> generateParenthesis(int n) {
    unordered_set<string> global;
    dfs(global, "", n, n);
    return vector<string>(global.begin(), global.end());
  }
};

