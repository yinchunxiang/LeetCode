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
  void dfs(std::unordered_map<int, std::unordered_set<int>> &tree,
           int root,
           vector<int>& informTime,
           int local,
           int& result) {
    auto it = tree.find(root);
    if (tree.end() == it) {
      result = max(result, local);
      return;
    }
    auto& nodes = it->second;
    for (auto i : nodes) {
      dfs(tree, i, informTime, local + informTime[root], result);
    }
  }


  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    std::unordered_map<int, std::unordered_set<int>> tree;
    for (int i = 0; i < n; ++i) {
      if (-1 == manager[i]) continue;
      tree[manager[i]].insert(i);
    }
    int result = 0;
    dfs(tree, headID, informTime, 0, result);
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  {
    int n = 1;
    int headID = 0;
    vector<int> manager{-1};
    vector<int> informTime {0};
    dbg(manager);
    cout << s.numOfMinutes(n, headID, manager, informTime) << endl;
  }
  {
    int n = 6;
    int headID = 2;
    vector<int> manager = {2,2,-1,2,2,2};
    vector<int> informTime = {0,0,1,0,0,0};
    dbg(manager);
    cout << s.numOfMinutes(n, headID, manager, informTime) << endl;
  }
  {
    int n = 7;
    int headID = 6;
    vector<int> manager = {1,2,3,4,5,6,-1};
    vector<int> informTime = {0,6,5,4,3,2,1};
    dbg(manager);
    cout << s.numOfMinutes(n, headID, manager, informTime) << endl;
  }
  return 0;
}
