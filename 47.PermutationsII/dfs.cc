//
// Created by yinchunxiang on 2019-02-23.
//


class Solution {
 public:
  void dfs(vector<vector<int>>& result, vector<int>& local, vector<bool>& used, const vector<int>& nums) {
    if (local.size() >= nums.size()) {
      result.push_back(local);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) continue;
      if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;
      local.push_back(nums[i]);
      used[i] = true;
      dfs(result, local, used, nums);
      used[i] = false;
      local.pop_back();
    }
  }
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    vector<vector<int>> result;
    vector<int> local;
    dfs(result, local, used, nums);
    return result;
  }
};


