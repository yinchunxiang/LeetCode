//
// Created by alexkkk on 2019-02-08.
//

#include <vector>
#include "../util/base.h"

using namespace std;


class Solution {
public:
  int GetArea(vector<int>& v) {
    vector<int> pos;
    v.push_back(-1);
    int result = 0;
    for (int i = 0; i < v.size(); ++i) {
      while (!pos.empty() && v[pos.back()] > v[i]) {
        int h = v[pos.back()];
        pos.pop_back();
        cout << "v[" << pos.back() << "]: " << h << endl;
        if (0 == h) continue;
        int left_boundary = pos.empty() ? 0 : (pos.back() + 1);
        int area = (i - left_boundary) * h;
        cout << "h: " << h << " width:" << i - left_boundary << " area:" << area << endl;
        result = max(result ,area);
      }
      pos.push_back(i);
    }
    cout << "-------------------" << endl;
    return result;
  }

  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (rows <= 0) return 0;
    int cols = matrix[0].size();
    vector<vector<int>> m(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        int val = (matrix[i][j] - '0');
        if (0 == i) {
          m[i][j] = val;
          continue;
        }
        m[i][j] = (val == 0 ? 0 : m[i - 1][j] + 1);
      }
    }
    printvv(m);
    int result = 0;
    for (int i = 0; i < rows; ++i) {
      int area = GetArea(m[i]);
      result = max(result, area);
    }
    return result;
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
