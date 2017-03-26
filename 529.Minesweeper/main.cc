/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/23 19:57:50
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
    public:
        void help(vector<vector<char>>& board, int row, int col) {
            int rows = board.size();
            if (0 == rows) {
                return ;
            }
            int cols = board[0].size();
            if (0 == cols) {
                return ;
            }
            if ('M' == board[row][col]) {
                board[row][col] = 'X';
                return;
            }
            if ('E' != board[row][col]) {
                return;
            }
            board[row][col] = 'B';
            int count = 0;
            for (int i = row - 1; i <= row + 1; ++i) {
                for (int j = col - 1; j <= col + 1; ++j) {
                    if (i == row && j == col) {
                        continue;
                    }
                    if (i < 0 || i >= rows) {
                        continue;
                    }
                    if (j < 0 || j >= cols) {
                        continue;
                    }
                    if ('M' == board[i][j] || 'X' == board[i][j]) {
                        count += 1;
                    }
                }
            }
            if (count > 0) {
                board[row][col] = '0' + count;
            } else {

            cout << "board["<<row << "][" << col <<"] => " << board[row][col] << endl;
            for (int i = row - 1; i <= row + 1; ++i) {
                for (int j = col - 1; j <= col + 1; ++j) {
                    if (i == row && j == col) {
                        continue;
                    }
                    if (i < 0 || i >= rows) {
                        continue;
                    }
                    if (j < 0 || j >= cols) {
                        continue;
                    }
                    help(board, i, j);
                }
            }
            }
        }

        vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
            int row = click[0];
            int col = click[1];
            help(board, row, col);
            return board;
        }

};

void printv(vector<vector<char>> &w) {
    for (auto &v: w) {
        cout << "{ ";
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "}" << endl;
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<vector<char>> board = {
            {'E', 'E', 'E', 'E', 'E'},
            {'E', 'E', 'M', 'E', 'E'},
            {'E', 'E', 'E', 'E', 'E'},
            {'E', 'E', 'E', 'E', 'E'}
        };
        vector<int> click = {3, 0};
        auto v = s.updateBoard(board, click);
        printv(v);


    }
    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
