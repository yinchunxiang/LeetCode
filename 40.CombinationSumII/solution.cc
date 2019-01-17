//
// Created by alexkkk on 2019-01-17.
//
#include <vector>
#include <algorithm>
#include "../util/base.h"


using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> current;
    dfs(result, current, candidates, 0, target, -1);
    return result;
  }

  void dfs(vector<vector<int>>& result, vector<int> current, const vector<int>& candidates, int index, int gap, int prev) {
    if (0 == gap) {
      result.push_back(current);
      return;
    }

    // pruning
    if (gap < candidates[index]) return;

    // 用当前值
    current.push_back(candidates[index]);
    dfs(result, current, candidates, index + 1, gap - candidates[index], candidates[index]);
    current.pop_back();
    // 不用当前值
    if (candidates[index] == prev) return;
    dfs(result, current, candidates, index + 1, gap, prev);
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  {
    vector<int> candidates {10, 1, 2, 7, 6, 1, 5};
    auto result = s.combinationSum(candidates, 8);
    printvv(result);

  }
  return 0;
}


