//
// Created by alexkkk on 2020/3/1.
//

#include <unordered_set>
#include <vector>

#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  int rows_;
  int cols_;
  vector<vector<int>> dirs_ = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}
  };

  void dfs(int i, int j,
           unordered_set<int>& next,
           unordered_set<int>& visited,
           vector<vector<int>>& grid,
           vector<vector<int>>& d,
           int distance) {
    for (int k = 0; k < 4; ++k) {
      auto& dir = dirs_[k];
      int x = i - dir[0];
      int y = j - dir[1];
      if (x >= rows_ || x < 0) continue;
      if (y >= cols_ || y < 0) continue;
      cout << "x: " << x << " y:" << y << " grid:" << grid[x][y] << endl;
      if (k + 1 != grid[x][y]) continue;
      auto new_pos = x * cols_ + y;
      if (visited.count(new_pos)) continue;
      visited.insert(new_pos);
      next.insert(new_pos);
      d[x][y] = distance;
      dfs(x, y, next, visited, grid, d, distance);
    }
  }

  unordered_set<int> extend(unordered_set<int>& cur, unordered_set<int>& visited) {
    unordered_set<int> result;
    for (auto& pos : cur) {
      int i = pos / cols_;
      int j = pos % cols_;
      cout << "--> current pos:" << pos << " i:" << i << " j:" << j << endl;
      for (int k = 0; k < 4; ++k) {
        auto& dir = dirs_[k];
        int x = i + dir[0];
        int y = j + dir[1];
        if (x >= rows_ || x < 0) continue;
        if (y >= cols_ || y < 0) continue;
        cout << "--> extend x:" << x << " y:" << y << endl;
        auto new_pos = x * cols_ + y;
        if (visited.count(new_pos)) continue;
        visited.insert(new_pos);
        result.insert(new_pos);
      }
    }
    return result;
  }


  int minCost(vector<vector<int>>& grid) {
    rows_ = grid.size();
    cols_ = grid[0].size();
    unordered_set<int> s;
    int target =  rows_ * cols_ - 1;
    s.insert(target);
    vector<vector<int>> d(rows_, vector<int>(cols_, rows_ * cols_));
    d[rows_ - 1][cols_ - 1] = 0;
    int distance = 0;
    unordered_set<int> visited;
    visited.insert(target);
    while (!s.empty()) {
      if (s.count(0)) {
        return distance;
      }
      cout << "-------------------> s:" << endl;
      dbg(s);

      unordered_set<int> ss = s;

      for (auto& pos : s) {
        auto i = pos / cols_;
        auto j = pos % cols_;
        dfs(i, j, ss, visited, grid, d, distance);
      }
      cout << "-------> ss:" << endl;
      dbg(ss);
      if (ss.count(0)) {
        return distance;
      }
      distance += 1;
      auto next = extend(ss, visited);
      cout << "-------> next:" << endl;
      dbg(next);
      s.swap(next);
    }
    return distance;
  }
};

int main(int argc, char* argv[]) {
  /*
  vector<vector<int>> grid = {
      {1,1,1,1},
      {2,2,2,2},
      {1,1,1,1},
      {2,2,2,2}
  };
  */
//  vector<vector<int>> grid = {{1,1,3},{3,2,2},{1,1,4}};
  vector<vector<int>> grid = {{2,2,2},{2,2,2}};

  Solution s;
  dbg(s.minCost(grid));
  return 0;
}

