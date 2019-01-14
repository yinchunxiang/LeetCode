#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:
  vector<std::pair<int, int>> ExtendState(const std::pair<int, int>& start, int m, int n) {
    vector<std::pair<int, int>> result;
    vector<std::pair<int, int>> directions = {
        std::make_pair(0, 1), std::make_pair(1, 0)
    };
    for (const auto& d : directions) {
      auto next = make_pair(start.first + d.first, start.second + d.second);
      if (next.first >= m || next.second >= n) continue;
//      cout << "next: " << next.first << " " << next.second << endl;
      result.push_back(next);
    }
    return result;
  }
  int dfs(std::pair<int, int> start, std::pair<int, int> end, int m , int n) {
    if (start.first == end.first && start.second == end.second) return 1;
    auto next_state_list = ExtendState(start, m, n);
    int result = 0;
    for (const auto& state : next_state_list) {
      result += dfs(state, end, m, n);
    }
    return result;
  }

  int uniquePaths(int m, int n) {
    return dfs(std::make_pair(0, 0), std::make_pair(m-1, n - 1), m , n);
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  cout << s.uniquePaths(3, 2) << endl;
  cout << s.uniquePaths(7, 3) << endl;
  return 0;
}

