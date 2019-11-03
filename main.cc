//
// Created by alexkkk on 2019-09-16.
//


#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

// 假设matrix所有元素都是正数
vector<vector<int>> compress(vector<vector<int>> matrix) {
  vector<pair<int, pair<int, int>>> v;
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      v.push_back({matrix[i][j], {i, j}});
    }
  }
  std::sort(v.begin(), v.end());

  int rows = matrix.size();
  int cols = matrix[0].size();
  // 这一行的上一元素
  vector<int> row_index(rows, -1);
  // 这一列的上一元素
  vector<int> col_index(cols, -1);

  // 元素对应的真正压缩之后的值
  unordered_map<int, int> m;
  for (int i = 0; i < v.size(); ++i) {
    // 当前元素对应的原来的xy下标
    auto x = v[i].second.first;
    auto y = v[i].second.second;
    // 这行的第一个默认1
    int r = 1;
    if (row_index[x] > 0) {
      // 和上一个值相同
      if (row_index[x] == v[i].first) {
        r = m[row_index[x]];
      } else {
        r = m[row_index[x]] + 1;
      }
    }

    // 这列的第一个默认1
    int c = 1;
    if (col_index[y] > 0) {
      if (col_index[y] == v[i].first) {
        // 和上一个元素相同
        c = m[col_index[y]];
      } else {
        // 和上一个元素不同, 更新
        c = m[col_index[y]] + 1;
      }
    }

    int index = max(r, c);
    row_index[x] = v[i].first;
    col_index[y] = v[i].first;
    m[v[i].first] = index;
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      matrix[i][j] = m[matrix[i][j]];
    }
  }
  return matrix;
}

void Print(vector<vector<int>>& vv) {
  for (const auto& v : vv) {
    for (auto& num : v) {
      cout << num << ",";
    }
    cout << endl;
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  vector<vector<int>> matrix = {
      {10, 40, 50, 60, 70},
      {11, 12, 13, 14, 40},
  };
  Print(matrix);
  auto output = compress(matrix);
  Print(output);
  return 0;
}