/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/31 22:18:26
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& heightMap, vector<vector<bool>>& has_water, int i, int j) {
        //cout << "i => " << i << " " << "j => " << j << endl;
        //cout << "--------------------------------" << endl;
        
        if (i - 1 > 0 && has_water[i - 1][j] && heightMap[i - 1][j] >= heightMap[i][j]) {
            has_water[i - 1][j] = false;
            dfs(heightMap, has_water, i - 1, j);
        }
        if (i + 1 < rows_ - 1 && has_water[i + 1][j] && heightMap[i + 1][j] >= heightMap[i][j]) {
            has_water[i + 1][j] = false;
            dfs(heightMap, has_water, i + 1, j);
        }

        if (j - 1 > 0 && has_water[i][j - 1] && heightMap[i][j - 1] >= heightMap[i][j]) {
            has_water[i][j - 1] = false;
            dfs(heightMap, has_water, i, j - 1);
        }

        if (j + 1 < cols_ - 1 && has_water[i][j + 1] && heightMap[i][j + 1] >= heightMap[i][j]) {
            has_water[i][j + 1] = false;
            dfs(heightMap, has_water, i, j + 1);
        }

    }

    
    int area(vector<vector<int>>& heightMap, vector<vector<bool>>& has_water, int i, int j) {
        if (!has_water[i][j]) {
            return 0;
        }
        int height = INT_MAX;
        if (!has_water[i - 1][j]) {
            height = min(height, heightMap[i - 1][j]);
        }
        if (!has_water[i + 1][j]) {
            height = min(height, heightMap[i + 1][j]);
        }
        if (!has_water[i][j - 1]) {
            height = min(height, heightMap[i][j - 1]);
        }
        if (!has_water[i][j + 1]) {
            height = min(height, heightMap[i][j + 1]);
        }
        if (height < INT_MAX) {
            h_[i][j] = height;
        } else {
            height = min(height, h_[i - 1][j]);
            height = min(height, h_[i + 1][j]);
            height = min(height, h_[i][j - 1]);
            height = min(height, h_[i][j + 1]);
        }

        return height - heightMap[i][j];
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) {
            return 0;
        }
        rows_ = heightMap.size();
        cols_ = heightMap[0].size();
        vector<vector<bool>> has_water(rows_, vector<bool>(cols_, true));

            
        // init
        for (int i = 0; i < rows_; ++i) {
            has_water[i][0] = false;
            has_water[i][cols_ - 1] = false;
        }
        for (int j = 1; j < cols_ - 1; ++j) {
            has_water[0][j] = false;
            has_water[rows_ - 1][j] = false;
        }

        for (int i = 0; i < rows_; ++i) {
            dfs(heightMap, has_water, i, 0);
            if (cols_ > 1) {
                dfs(heightMap, has_water, i, cols_ - 1);
            }
        }
        for (int j = 1; j < cols_ - 1; ++j) {
            dfs(heightMap, has_water, 0, j);
            if (rows_ > 1) {
                dfs(heightMap, has_water, rows_ - 1, j);
            }
        }
        /*
        cout << "{" << endl;
        for (int i = 0; i < rows_; ++i) {
            cout << "\t{ ";
            for (int j = 0; j < cols_; ++j) {
                cout << has_water[i][j] << " "; 
            }
            cout << "}" << endl;
        }
        cout << "}" << endl;
        */
        h_ = heightMap;
        
        int result = 0;
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (has_water[i][j]) {
                    //cout << "(i, j) => (" << i << ","<< j <<")" << endl;
                    result += area(heightMap, has_water, i, j);
                }
            }
        }
        return result;
    }
    int rows_;
    int cols_;
    vector<vector<int>> h_;
};

int main(int argc, const char* argv[]) {
    vector<vector<int>> v = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    Solution s;
    cout << s.trapRainWater(v) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
