//
// Created by alexkkk on 2019-02-08.
//

#include <vector>
#include "../util/base.h"

using namespace std;


class Solution {
public:
  // 这个思路比较好理解
  int GetMaxArea(const vector<vector<char>>& matrix, int up, int down, int left, int right) {
    cout << "up:" << up << " down:" << down << " left:" << left << " right:" << right << endl;
    if (up >= down || left >= right) return 0;
    // 没找到0， 肯定就是返回当前矩阵的大小
    int result = (down - up) * (right - left);
    for (int i = up; i < down; ++i) {
      for (int j = left; j < right; ++j) {
        if (matrix[i][j] != '0') continue;
        // 找到任意一个0， 将矩阵分为4个部分， 最大的必然在其中一个部分
        int rmax = max(GetMaxArea(matrix, up, down, left, j), GetMaxArea(matrix, up, down, j + 1, right));
        int cmax = max(GetMaxArea(matrix, up, i, left, right), GetMaxArea(matrix, i + 1, down, left, right));
        return max(rmax, cmax);
      }
    }
    return result;
  }

  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (rows <= 0) return 0;
    int cols = matrix[0].size();
    return GetMaxArea(matrix, 0, rows, 0, cols);
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  {
    vector<vector<char>> vv = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << s.maximalRectangle(vv) << endl;
  }
  return 0;
}
