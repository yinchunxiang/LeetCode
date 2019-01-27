//
// Created by yinchunxiang on 2019-01-27.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool IsRowOk(const vector<vector<char>>& board, int row, char value) {
    for (int col = 0; col < 9; ++col) {
      if (board[row][col] == value) return false;
    }
    return true;
  }
  bool IsColOk(const vector<vector<char>>& board, int col, char value) {
    for (int row = 0; row < 9; ++row) {
      if (board[row][col] == value) return false;
    }
    return true;
  }
  bool IsSubGridOk(const vector<vector<char>>& board, int row, int col, char value) {
    int i = row / 3;
    int j = col / 3;
    for (int m = 0; m < 3; ++m) {
      for (int n = 0; n < 3; ++n) {
        int r = 3 * i + m;
        int c = 3 * j + n;
        cout << "r>>" << r << ", c>>" << c << endl;
        if (board[r][c] == value) return false;
      }
    }
    return true;
  }

  void printvv(vector<vector<char>>& vv) {
    for (auto& v : vv) {
      for (auto i : v) {
        std::cout << i << ",";
      }
      cout << endl;
    }
    cout << "-------------------------" << endl;
  }


  bool dfs(vector<vector<char>>& board, int row, int col, int steps) {
    cout << "row=>" << row << ", col=>" << col << endl;
    printvv(board);
    if (steps == 81) return true;
    if (board[row][col] != '.') {
      int next_row = (col == 8)? row + 1 : row;
      int next_col = (col == 8) ? 0 : col + 1;
      return dfs(board, next_row, next_col, steps + 1);
    }
    for (int i = 1; i < 10; ++i) {
      char value = (char)('0' + i);
      cout << "value: " << value << endl;
      if (!IsRowOk(board, row, value)) continue;
      if (!IsColOk(board, col, value)) continue;
      if (!IsSubGridOk(board, row, col, value)) continue;
      char bak = board[row][col];
      board[row][col] = value;
      int next_row = (col == 8)? row + 1 : row;
      int next_col = (col == 8) ? 0 : col + 1;
      if (dfs(board, next_row, next_col, steps + 1)) return true;
      board[row][col] = bak;
    }
    return false;
  }
  void solveSudoku(vector<vector<char>>& board) {
    dfs(board, 0, 0, 0);
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  vector<vector<char>> board = {
      {'.','.','9','7','4','8','.','.','.'},
      {'7','.','.','.','.','.','.','.','.'},
      {'.','2','.','1','.','9','.','.','.'},
      {'.','.','7','.','.','.','2','4','.'},
      {'.','6','4','.','1','.','5','9','.'},
      {'.','9','8','.','.','.','3','.','.'},
      {'.','.','.','8','.','3','.','2','.'},
      {'.','.','.','.','.','.','.','.','6'},
      {'.','.','.','2','7','5','9','.','.'}
  };
  s.solveSudoku(board);

  return 0;
}

