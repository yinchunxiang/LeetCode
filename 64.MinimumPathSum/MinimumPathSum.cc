#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    if (0 == row) return 0;
    int col = grid[0].size();
    if (0 == col) return 0;

    vector<int> dp = grid[0];
    for (size_t j = 1; j < col; ++j) {
        dp[j] += dp[j - 1];
    }

    for (size_t i = 1; i < row; ++i) {
        dp[0] += grid[i][0];
        for (size_t j = 1; j < col; ++j) {
            dp[j] = grid[i][j] + std::min(dp[j], dp[j - 1]);
        }
    }
    return dp[col - 1];
}

int main(int argc, const char *argv[])
{
    vector<vector<int>> input{{1,2,5},{3,2,1}};
    cout << minPathSum(input) << endl;

    return 0;
}

