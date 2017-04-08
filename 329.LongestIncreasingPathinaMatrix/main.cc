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
        void dfs(int& count, vector<int> path, vector<vector<bool>> visited, vector<vector<int>>& matrix, int i , int j) {
            if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j]) {
                return;
            }
            if (!path.empty() && path.back() >= matrix[i][j]) {
                return;
            }
            path.push_back(matrix[i][j]);
            visited[i][j] = true;
            if (path.size() > count) {
                count = path.size();
            }

            dfs(count, path, visited, matrix, i + 1, j);
            dfs(count, path, visited, matrix, i - 1, j);
            dfs(count, path, visited, matrix, i, j + 1);
            dfs(count, path, visited, matrix, i, j - 1);
        }
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            if (matrix.empty()) return 0;
            rows = matrix.size();
            cols = matrix[0].size();
            int count = 0;
            vector<vector<bool>> visited(rows, vector<bool>(cols, false));
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    dfs(count, {}, visited, matrix, i, j);
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
