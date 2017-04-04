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
#include <queue>

using namespace std;

class Solution {
public:

    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) { return 0; }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    visited[i][j] = 1;
                    q.push(make_pair(heightMap[i][j], i * cols + j));
                }
            }
        }
        int result = 0;
        int maxh = INT_MIN;
        vector<vector<int>> xy{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto val = q.top(); q.pop();
            auto height = val.first;
            auto x = val.second / cols;
            auto y = val.second % cols;
            maxh = max(maxh, height);
            for (auto &p : xy) {
                auto xx = x + p[0];
                auto yy = y + p[1];
                if (xx < 0 || xx >= rows || yy < 0 || yy >= cols || visited[xx][yy]) {
                    continue;
                }
                visited[xx][yy] = 1;
                
                if (maxh > heightMap[xx][yy]) { result += maxh - heightMap[xx][yy]; }
                q.push(make_pair(heightMap[xx][yy], xx * cols + yy));
            }
        }
        return result;
    }
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
