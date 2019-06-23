//
// Created by alexkkk on 2019-05-12.
//

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "../ThirdParty/PrettyPrinter/pprint.hpp"

using namespace std;

pprint::PrettyPrinter printer;


/**
 *
You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.



Example 1:

Input: N = 3, paths = [[1,2],[2,3],[3,1]]
Output: [1,2,3]
Example 2:

Input: N = 4, paths = [[1,2],[3,4]]
Output: [1,2,1,2]
Example 3:

Input: N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
Output: [1,2,3,4]


Note:

1 <= N <= 10000
0 <= paths.size <= 20000
No garden has 4 or more paths coming into or leaving it.
It is guaranteed an answer exists.
 */

class Solution {
public:
  bool select(vector<int>& result, vector<vector<int>>& matrix, int cur, int N) {
    if (cur == N) return true;
    unordered_set<int> candidates = {1, 2, 3, 4};
    for (int i = 0; i < N; ++i) {
      if (0 == matrix[cur][i]) continue;
      if (result.size() <= i) {
        continue;
      }
      candidates.erase(result[i]);
    }
    if (candidates.empty()) return false;
    for (const auto& c : candidates) {
      result.push_back(c);
      if (select(result, matrix, cur + 1, N)) {
        return true;
      }
      result.pop_back();
    }
    return false;
  }


  // yinchunxiang@2019-05-12: 空间优化，使用邻接表
  bool select(vector<int>& result, unordered_map<int, unordered_set<int>>& matrix, int cur, int N) {
    if (cur == N) return true;
    unordered_set<int> candidates = {1, 2, 3, 4};
    for (auto i : matrix[cur]) {
      if (result.size() <= i) {
        continue;
      }
      candidates.erase(result[i]);
    }
    if (candidates.empty()) return false;
    for (const auto& c : candidates) {
      result.push_back(c);
      if (select(result, matrix, cur + 1, N)) {
        return true;
      }
      result.pop_back();
    }
    return false;
  }


  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    unordered_map<int, unordered_set<int>> matrix;
    for (const auto& path : paths) {
      int x = path[0] - 1;
      int y = path[1] - 1;
      matrix[x].insert(y);
      matrix[y].insert(x);
    }
    printer.print(matrix);
    vector<int> result;
    select(result, matrix, 0, N);
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> paths = {
      {1, 2}, {2, 3}, {3, 1}
  };
  auto result = s.gardenNoAdj(3, paths);
  printer.print(result);
  return 0;
}
