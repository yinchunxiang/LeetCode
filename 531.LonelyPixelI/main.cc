/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/05 12:04:37
 * @brief 
 * 
 **/ 
#include <iostream> 
#include <vector>

using namespace std;

class Solution {
    public:
        int findLonelyPixel(vector<vector<char>>& picture) {
            int rows = picture.size();
            int cols = rows == 0 ? 0 : picture[0].size();
            vector<int> rb(rows, 0);
            vector<int> cb(cols, 0);
            int result = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if ('B' == picture[i][j]) {
                        rb[i] += 1;
                        cb[j] += 1;
                    }

                }
            }
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if ('B' == picture[i][j]) {
                        if (rb[i] + cb[j] == 2) {
                            result += 1;
                        }
                    }
                }
            }
            return result;
        }

};

int main(int argc, char *argv[]) {
    {
        vector<vector<char>> v = {
            {'W', 'W', 'B'},
             {'W', 'B', 'W'},
              {'B', 'W', 'W'}
        };
        Solution sol;
        cout << sol.findLonelyPixel(v) << endl;;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
