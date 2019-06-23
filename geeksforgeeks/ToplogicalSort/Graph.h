//
// Created by alexkkk on 2019-05-11.
//

#pragma once

#include <unordered_map>
#include <vector>

template <class NodeType>
class Graph {
public:
  void AddEdge(const NodeType& from, const NodeType& to) {
    data_[from].push_back(to);
  }

  void dfs(const NodeType& node, std::vector<NodeType>& result) {
    result.push_back(node);
    if (data_[node].empty()) return;
    for (const auto& n : data_[node]) {
      dfs(n, result);
    }
  }

  // yinchunxiang@2019-05-11: 从某个节点开始输出
  std::vector<NodeType> Output(const NodeType& start) {
    std::vector<NodeType> result;
    dfs(start, result);
    return ;
  }


private:
  std::unordered_map<NodeType, std::vector<NodeType>> data_;

};


