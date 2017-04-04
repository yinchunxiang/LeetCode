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
        void dfs(vector<vector<int>>& M, vector<bool>& visited, int N, int i) {
            cout << "row => " << i << endl;
            visited[i] = true;
            for (int j = 0; j < N; ++j) {
                if (i != j && M[i][j] && !visited[j]) {
                    dfs(M, visited, N, j);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& M) {
            if (M.empty()) return 0;
            int N = M.size();
            vector<bool> visited(N, false);
            int result = 0;
            for (int i = 0; i < N; ++i) {
                if (!visited[i]) {
                    dfs(M, visited, N, i);
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
