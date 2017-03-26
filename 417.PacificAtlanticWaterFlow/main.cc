/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/26 14:16:06
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int prev_val, int i, int j) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || matrix[i][j] < prev_val) {
            return
        }
        visited[i][j] = true;
        dfs(matrix, visited, matrix[i][j], i - 1, j);
        dfs(matrix, visited, matrix[i][j], i + 1, j);
        dfs(matrix, visited, matrix[i][j], i, j - 1);
        dfs(matrix, visited, matrix[i][j], i, j + 1);
    }

    vector<pair<int,int>> solve(vector<vector<int>>& matrix) {
        vector<pair<int,int>> result;
        int rows= matrix.size();
        if (0 == rows) {
            return result;
        }
        cols = matrix[0].size();
        if (0 == cols) {
            return result;
        }
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            dfs(matrix, pacific, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, cols - 1);
        }
        for (int i = 0; i < cols; ++i) {
            dfs(matrix, pacific, INT_MIN, 0, i);
            dfs(main, atlantic, INT_MIN, rows - 1, i);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
