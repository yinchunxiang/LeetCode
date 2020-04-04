//
// Created by alexkkk on 2020/3/15.
//

#include "../util/dbg.h"

#include <vector>

using namespace std;


class Solution {
 public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> min_r(rows, 100001);
    vector<int> max_c(cols, 0);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        min_r[i] = min(min_r[i], matrix[i][j]);
        max_c[j] = max(max_c[j], matrix[i][j]);
      }
    }
    dbg(min_r);
    dbg(max_c);
    vector<int> result;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (min_r[i] == max_c[j] && min_r[i] == matrix[i][j]) {
          result.push_back(matrix[i][j]);
        }

      }
    }
    return result;

  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> matrix = {
      {56216},{63251},{75772},{1945},{27014}
  };

  dbg(s.luckyNumbers(matrix));

  return 0;
}