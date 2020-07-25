//
// Created by alexkkk on 2020/7/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include "../util/dbg.h"

using namespace std;


class Solution {
 public:

  int GetNodeLabelCount(int i, char label) {
    if (tree[i].)

  }


  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    result_.resize(n, 0);
    tree_.resize(n);
    node_label_count_.resize(n);


    for (auto& edge : edges) {
      tree[edge[0]].push_back(edge[1]);
    }
    for (int i = 0; i < n; ++i) {

    }

  }

 private:

  vector<vector<int>> tree_;
  vector<unordered_map<char, int>> node_label_count_;


};

int main(int argc, char* argv[]) {

  return 0;
}