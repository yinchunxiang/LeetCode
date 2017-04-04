/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/03 11:06:00
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int dfs(vector<vector<int>>& M, vector<vector<int>>& visited, int N, int i) {
            cout << "row => " << i << endl;
            int result = 0;
            for (int j = 0; j < N; ++j) {
                if (visited[i][j] || 0 == M[i][j]) continue;
                visited[i][j] = true;
                if (j == i) {
                    result += 1;
                    continue;
                }
                result += dfs(M, visited, N, j);
            }
            return result;

        }
        int findCircleNum(vector<vector<int>>& M) {
            if (M.empty()) return 0;
            int N = M.size();
            vector<vector<int>> visited(N, vector<int>(N, false));
            int result = 0;
            for (int i = 0; i < N; ++i) {
                int count = dfs(M, visited, N, i);
                if (count > 0) {
                    ++result;
                }


            }
            return result;


        }

};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<vector<int>> input = {
            {1,1,0},
            {1,1,0},
            {0,0,1},
        };
        cout << s.findCircleNum(input) << endl;
    }
    {
        vector<vector<int>> input = {
            {1,0,0,1},
            {0,1,1,0},
            {0,1,1,1},
            {1,0,1,1},
        };
        cout << s.findCircleNum(input) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
