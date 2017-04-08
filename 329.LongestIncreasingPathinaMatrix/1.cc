/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/06 19:24:12
 * @brief 
 * 
 **/ 


#include <vector>
#include <iostream>

using namespace std;
 
class Solution {
    public:
        int rows;
        int cols;
        int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i , int j) {
            if (dp[i][j]) {
                return dp[i][j];
            }
            vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto &dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if (x <0 || x >= rows || y < 0 || y >= cols) continue;
                if (matrix[x][y] <= matrix[i][j]) continue;
                dp[i][j] = max(dp[i][j], dfs(dp, matrix, x, y));
            }
            return ++dp[i][j];
        }
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            if (matrix.empty()) return 0;
            rows = matrix.size();
            cols = matrix[0].size();
            vector<vector<int>> dp(rows, vector<int>(cols, 0));
            int count = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    count = max(count, dfs(dp, matrix, i, j));
                }
            }
            return count;
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    {
    vector<vector<int>> matrix = {
        {7, 8, 9},
        {9, 7, 6},
        {7, 2, 3}
    };
    cout << s.longestIncreasingPath(matrix) << endl;
    }
    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
