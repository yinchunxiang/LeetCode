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
    dfs(result, current, 0, candidates, 0, target);
    return result;
  }

  void dfs(vector<vector<int>>& result, vector<int> current, int sum, const vector<int>& candidates, int index, int target) {
    if (sum > target) return;
    if (sum == target) {
      result.push_back(current);
      return;
    }

    if (index >= candidates.size()) return;
    if (sum + candidates[index] > target) return;


    // 用当前值
    current.push_back(candidates[index]);
    dfs(result, current, sum + candidates[index], candidates, index, target);
    current.pop_back();
    // 不用当前值
    dfs(result, current, sum , candidates, index + 1, target);
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  {
    vector<int> candidates {2,3,6,7};
    auto result = s.combinationSum(candidates, 7);
    printvv(result);

  }
  return 0;
}


