//
// Created by alexkkk on 2020/2/2.
//

#include <vector>
#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> sums;
    int rows = mat.size();
    int cols = mat[0].size();
    for (int i = 0; i < rows; ++i) {
      int sum = 0;
      for (int j = 0; j < cols; ++j) {
        if (0 == mat[i][j]) break;
        sum += mat[i][j];
      }
      sums.push_back(sum);
    }
    vector<int> index;
    for (int i = 0; i < sums.size(); ++i) {
      index.push_back(i);
    }
    auto comp = [&sums](int i, int j) {
      if (sums[i] < sums[j]) return true;
      if (sums[i] == sums[j]) return i < j;
      return false;
    };
    dbg(sums);
    dbg(index);
    std::partial_sort(index.begin(), index.begin() + k, index.end(), comp);
    dbg(index);
    return vector<int>(index.begin(), index.begin() + k);

  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<int>> mat  {
      {1,1,0,0,0},
      {1,1,1,1,0},
      {1,0,0,0,0},
      {1,1,0,0,0},
      {1,1,1,1,1}
  };
  dbg(s.kWeakestRows(mat, 3));
  return 0;
}
