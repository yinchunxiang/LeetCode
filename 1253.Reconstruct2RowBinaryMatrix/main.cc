//
// Created by alexkkk on 2019/11/10.
//


class Solution {
 public:
  vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    int col = colsum.size();
    vector<vector<int>> mat(2, vector<int>(col, 0));

    // 先构建和为2的
    for (int j = 0; j < col; ++j) {
      if (colsum[j] == 2) {
        mat[0][j] = 1;
        mat[1][j] = 1;
      }
    }
    auto& row0 = mat[0];
    int row0_sum = accumulate(row0.begin(), row0.end(), 0);
    auto diff = upper - row0_sum;
    if (diff < 0) return vector<vector<int>>();
    for (int j = 0; j < col; ++j) {
      if (colsum[j] == 1) {
        if (diff > 0) {
          mat[0][j] = 1;
          diff -= 1;
        } else {
          mat[1][j] = 1;
        }
      }
    }
    auto& row1 = mat[1];
    auto row1_sum = accumulate(row1.begin(), row1.end(), 0);
    if (row1_sum != lower) return vector<vector<int>>();
    return mat;
  }
};