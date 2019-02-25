    //
// Created by alexkkk on 2019-02-08.
//

#include <vector>
#include "../util/base.h"

using namespace std;


class Solution {
public:

  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    if (rows <= 0) return 0;
    int cols = matrix[0].size();
    vector<int> height(cols, 0);
    vector<int> left(cols, 0);
    vector<int> right(cols, cols - 1);
    int result = 0;
    for (int i = 0; i < rows; ++i) {
      // 当前行最左边的1的位置
      int most_left = 0;
      for (int j = 0; j < cols; ++j) {
        if (matrix[i][j] == '0') {
          height[j] = 0;
          left[j] = 0;
          most_left = j + 1;
        } else {
          height[j] += 1;
          left[j] = max(left[j], most_left);
        }

        cout << "j:" << j << " left:" << left[j] << " height:" << height[j] << endl;
      }
      cout << "----------------" << endl;

      int most_right = cols - 1;
      for (int j = cols - 1; j >= 0; --j) {
        if (matrix[i][j] == '0') {
          most_right = j - 1;
        } else {
          right[j] = min(right[j], most_right);
          int area = height[j] * (right[j] - left[j] + 1);
          result = max(result, area);
          cout << "j:" << j << " right:" << right[j] << " area:" << area << endl;
        }
      }
      cout << "====================" << endl;
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
