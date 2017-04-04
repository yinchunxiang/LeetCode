/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/31 21:18:48
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;

// 本题如果不细抠那些重复的遍历可能就过不了
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if ('O' != board[i][j]) {
            return;
        }
        board[i][j] = '#';
        //四个边都不要遍历了，在最开始会被遍历
        if (i - 1 > 0) {
            dfs(board, i - 1, j);
        }
        if (i + 1 < rows_ - 1) {
            dfs(board, i + 1, j);
        }
        if (j - 1 > 0) {
            dfs(board, i, j - 1);
        }
        if (j + 1 < cols_ - 1){
            dfs(board, i, j + 1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        rows_ = board.size();
        cols_ = board[0].size();
        for (int i = 0; i < rows_; ++i) {
            dfs(board, i, 0);
            if (cols_ > 1) {
                dfs(board, i, cols_ - 1);
            }
        }
        // 注意减少遍历次数
        for (int j = 1; j < cols_ - 1; ++j) {
            dfs(board, 0, j);
            if (rows_ > 1) {
                dfs(board, rows_ - 1, j);
            }
        }
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                board[i][j] = ('#' == board[i][j]) ? 'O' : 'X';
            }
        }
    }
    int rows_;
    int cols_;
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
