//
// Created by alexkkk on 2020/7/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "../util/dbg.h"

using namespace std;


class Solution {
 public:

  // 返回以该节点为根的树中，各个label出现的次数
  vector<int> dfs(int i,
                  const std::string& labels,
                  vector<vector<int>>& adj,
                  vector<bool>& visited,
                  vector<int>& result) {
    visited[i] = true;
    vector<int> res(26, 0);
    for (auto& idx : adj[i]) {
      if (visited[idx]) continue;
      auto label_count = dfs(idx, labels, adj, visited, result);
      for (int i = 0; i < 26; ++i) {
        res[i] += label_count[i];
      }
    }
    result[i] = ++res[labels[i] - 'a'];
    return res;
  }


  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    vector<int> result(n, 0);
    vector<bool> visited(n, false);;
    dfs(0, labels, adj, visited, result);
    return result;
  }
};

void Check(Solution& s, int n, vector<vector<int>>& edges, const std::string& labels) {
  dbg(n);
  dbg(edges);
  dbg(labels);
  auto result = s.countSubTrees(n, edges, labels);
  dbg(result);
}

int main(int argc, char* argv[]) {

//  {
//    Solution s;
//    int n = 4;
//    std::vector<vector<int>> edges {{0,2},{0,3},{1,2}};
//    std::string labels = "aeed";
//    Check(s, n, edges, labels);
//  }

  {
    Solution s;
    int n = 7;
    std::vector<vector<int>> edges  {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    std::string labels = "abaedcd";
    Check(s, n, edges, labels);
  }
//
//  {
//    Solution s;
//    int n = 4;
//    std::vector<vector<int>> edges {{0,1},{1,2},{0,3}};
//    std::string labels = "bbbb";
//    Check(s, n, edges, labels);
//  }

  return 0;
}