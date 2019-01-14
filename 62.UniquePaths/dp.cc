#include <vector>
#include <iostream>
using namespace std;

class Solution {
 public:

  int uniquePaths(int m, int n) {
    vector<vector<int>> count(m, vector<int>(n, 1));
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        count[i][j] = count[i - 1][j] + count[i][j - 1];
      }
    }
    return count[m - 1][n - 1];
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  cout << s.uniquePaths(3, 2) << endl;
  cout << s.uniquePaths(7, 3) << endl;
  return 0;
}

