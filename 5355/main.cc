//
// Created by alexkkk on 2020/3/8.
//

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  void dfs(unordered_map<int, unordered_set<int>> &graph,
           int start, int t, int target,
           unordered_set<int>& visited,
           std::vector<std::pair<int, int>> local_path,
           std::vector<std::pair<int, int>> &path) {

    // 把当前节点放进路径
    visited.insert(start);
    auto it = graph.find(start);
    unordered_set<int> next;
    if (it != graph.end()) {
      for (auto node : it->second) {
        if (visited.count(node)) continue;
        next.insert(node);
      }
    }
    local_path.emplace_back(start, next.size());
    if (next.empty() || t == 0) {
      if (local_path.back().first == target) {
        path.swap(local_path);
      }
      return;
    }

    t -= 1;
    if (t < 0) return;

    for (auto node : next) {
      dfs(graph, node, t, target, visited, local_path, path, found);
    }
  }


  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    unordered_map<int, unordered_set<int>> graph;
    for (auto& edge : edges) {
      graph[edge[0]].insert(edge[1]);
      graph[edge[1]].insert(edge[0]);
    }

    unordered_set<int> visited;
    vector<pair<int, int>> local_path;
    vector<pair<int, int>> path;
    bool found = false;
    dfs(graph, 1, t, target, visited, local_path, path);
    dbg(path);
    if (path.empty()) return 0;

    int result = 1;
    for (auto& p : path) {
      auto count = p.second > 0 ? p.second : 1;
      result *= count;
    }
    return 1.0 / result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  {
    int n = 7;
    std::vector<std::vector<int>> edges {
        {1,2},{1,3},{1,7},{2,4},{2,6},{3,5}
    };
    int t = 2;
    int target = 4;
    cout << s.frogPosition(n, edges, t, target) << endl;
  }

  {
    int n = 7;
    vector<vector<int>> edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    int t = 1;
    int target = 7;
    cout << s.frogPosition(n, edges, t, target) << endl;
  }
  {
    int n = 3;
    vector<vector<int>> edges = {{2,1},{3,2}};
    int t = 1;
    int target = 2;
    cout << s.frogPosition(n, edges, t, target) << endl;
  }
  {
    int n = 1;
    vector<vector<int>> edges;
    int t = 1;
    int target = 1;
    cout << s.frogPosition(n, edges, t, target) << endl;
  }
  return 0;
}

