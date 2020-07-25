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

  int GetNodeLabelCount(int i, char label) {
    int result = 0;
    result += (label == labels_[i]);

    for (auto& idx : tree_[i]) {
      result += GetNodeLabelCount(idx, label);
    }
    return result;
  }


  void CreateNodeLabelCount(int i) {
    auto& m = node_label_count_[i];
    m.emplace(labels_[i], 1);

    for (auto idx : tree_[i]) {
      CreateNodeLabelCount(idx);
    }

    for (auto idx : tree_[i]) {
      for (auto& entry : node_label_count_[idx]) {
        m[entry.first] += entry.second;
      }
    }
    dbg(i);
    dbg(m);
  }


  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> result(n, 0);
    labels_ = std::move(labels);
    tree_.resize(n);
    node_label_count_.resize(n);


    vector<vector<int>> temp;
    temp.resize(n);
    for (auto& edge : edges) {
      temp[edge[0]].push_back(edge[1]);
      temp[edge[1]].push_back(edge[0]);
    }
    dbg(temp);
    vector<bool> created(n, false);
    vector<int> current { 0 };
    vector<int> next;
    while (!current.empty()) {
      dbg(current);
      for (auto idx : current) {
        auto& children = temp[idx];
        for (auto child : children) {
          if (created[child]) continue;
          tree_[idx].push_back(child);
          next.push_back(child);
        }
        created[idx] = true;
      }
      dbg(next);
      current.clear();
      std::swap(current, next);
    }

    dbg(tree_);

    CreateNodeLabelCount(0);


    for (int i = 0; i < n; ++i) {
      auto label = labels_[i];
      auto& m = node_label_count_[i];
      result[i] = m[label];
    }
    return result;
  }

 private:

  std::string labels_;

  vector<vector<int>> tree_;
  vector<unordered_map<char, int>> node_label_count_;


};

void Check(Solution& s, int n, vector<vector<int>>& edges, const std::string& labels) {
  dbg(n);
  dbg(edges);
  dbg(labels);
  auto result = s.countSubTrees(n, edges, labels);
  dbg(result);
}

int main(int argc, char* argv[]) {

  {
    Solution s;
    int n = 4;
    std::vector<vector<int>> edges {{0,2},{0,3},{1,2}};
    std::string labels = "aeed";
    Check(s, n, edges, labels);
  }

//  {
//    Solution s;
//    int n = 7;
//    std::vector<vector<int>> edges  {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
//    std::string labels = "abaedcd";
//    Check(s, n, edges, labels);
//  }
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