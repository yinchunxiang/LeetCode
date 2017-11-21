//
// Created by alexkkk on 11/21/17.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& path, vector<vector<int>> &matrix, int i, int j, int &result) {
        int steps = path[i][j];
        if (steps > 0) {
            result = max(result, steps);
            return;
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        auto rows = matrix.size();
        auto cols = matrix[0].size();
        for(auto p : dirs) {
            int x = i + p.first;
            int y = j + p.second;
            if (x < 0 || x >= rows || y < 0 || y >= cols) {
                count += 1;
                continue;
            }
            if (matrix[i][j] >= matrix[x][y]) {
                count += 1;
                continue;
            }
            dfs(path, matrix, x, y, result);
            path[i][j] = max(path[i][j], 1 + path[x][y]);
        }
        if (4 == count) {
            path[i][j] = 1;
        }
        result = max(result, path[i][j]);
        return;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        size_t rows = matrix.size();
        if (rows <= 0) return 0;
        size_t cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        std::function<int(int, int)> dfs = [&] (int x, int y) {
            if (dp[x][y] > 0) return dp[x][y];
            vector<vector<int>> dirs = {
                    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
            };
            for (auto dir : dirs) {
                int xx = x + dir[0];
                int yy = y + dir[1];
                dp[x][y] = max(dp[x][y], dp[xx][yy]);
            }
            return ++dp[x][y];
        };

        int result = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result = max(result, dfs[i, j]);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    //TODO
    {
        vector<vector<int>> nums = {
                {9, 9, 4},
                {6, 6, 8},
                {2, 1, 1}
        };
        Solution s;
        cout << s.longestIncreasingPath(nums) << endl;
    }
    return 0;
}