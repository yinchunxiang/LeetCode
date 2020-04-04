//
// Created by alexkkk on 2020/2/4.
//

#include "../../util/dbg.h"
/**
test case:
 5 5
 {
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0}
    {0, 0, 1, 0, 0}
    {0, 0, 0, 1, 0}
    {0, 0, 0, 0, 1}
 }
 => 4小时
 */
bool done(int rows, int columns, vector<vector<int>>& grid)  {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if (0 == grid[i][j]) return false;
    }
  }
  return true;
}

int helper(int i, int j, vector<vector<int>> a, vector<vector<int>> grid) {
  if (!a[i][j])
}


int solve(vector<vector<int>>& grid) {

}

int main(int argc, char* argv[]) {

  return 0;
}
