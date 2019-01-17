#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
 public:

  vector<vector<string>> solveNQueens(int n) {
    Init(n);
    vector<vector<string>> result;
    vector<int> c;
    dfs(result, c, n, 0);
    return result;
  }

  void dfs(vector<vector<string>>& global, vector<int>& c, int n, int row) {
    if (row >= n) {
      vector<string> str_row_vec;
      for (auto i : c) {
        str_row_vec.push_back(rows_[i]);
      }
      global.push_back(str_row_vec);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (cols_[i]) continue;
      if (main_diagonal_[row + i]) continue;
      if (anti_diagonal_[row + n - i]) continue;
      c.push_back(i);
      cols_[i] = true;
      main_diagonal_[row + i] = true;
      anti_diagonal_[row + n - i] = true;
      dfs(global, c, n, row + 1);
      c.pop_back();
      cols_[i] = main_diagonal_[row + i] = anti_diagonal_[row + n - i] = false;
    }
  }

  void Init(int n) {
    for (int i = 0; i < n; ++i) {
      string s(n, '.');
      s[i] = 'Q';
      rows_.push_back(s);
    }
    cols_ = std::move(vector<bool>(n, false));
    main_diagonal_ = std::move(vector<bool>(2 * n, false));
    anti_diagonal_ = std::move(vector<bool>(2 * n, false));
  }

 private:
  vector<string> rows_;
  vector<bool> cols_;
  vector<bool> main_diagonal_;
  vector<bool> anti_diagonal_;
};

void printvv(vector<vector<string> >& vv) {
  for (int i = 0; i < vv.size(); i++) {
    for (int j = 0; j < vv[i].size(); j++) {
      cout << vv[i][j] << " " ;
    }
    cout << endl;
  }
  cout << endl << endl;
}

int main(int argc, const char *argv[]) {
  Solution s;
  auto result = s.solveNQueens(4);
  printvv(result);
  return 0;
}
