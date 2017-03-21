/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/19 11:44:35
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
            int row = matrix.size();
            if (0 == row) {
                return matrix;
            }
            int col = matrix[0].size();
            int MAX_LEN = max(col, row);
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (0 == matrix[i][j]) {
                        continue;
                    }
                    // left
                    auto ld = j - 1 < 0 ? MAX_LEN : matrix[i][j - 1];
                    // up
                    auto ud = i - 1 < 0 ? MAX_LEN : matrix[i - 1][j];
                    matrix[i][j] = min(ld, ud) + 1;
                }
            }

            for (int i = row - 1; i >= 0; --i) {
                for (int j = col - 1; j >= 0; --j) {
                    if (0 == matrix[i][j]) {
                        continue;
                    }
                    // right
                    auto rd = j + 1 >= col ? MAX_LEN: matrix[i][j + 1];
                    // down
                    auto dd = i + 1 >= row ? MAX_LEN: matrix[i + 1][j];
                    matrix[i][j] = min(matrix[i][j], min(rd, dd) + 1);
                }
            }
            return matrix;
        }

};

void printvv(vector<vector<int>> &w) {
    cout << "{" << endl;
    for (auto &v : w) {
        cout << "    { "; 
        for (auto &i : v) {
            cout << i << " ";
        }
        cout << "}" << endl;
    }
    cout << "}" << endl;
}

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<vector<int>> input = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0},
        };
        printvv(input);
        auto w = s.updateMatrix(input);
        printvv(w);
    }
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
