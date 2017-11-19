/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 2.cc
 * @author yinchunxiang(@com)
 * @date 2017/10/22 15:16:17
 * @brief 
 * 
 **/ 
 
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 || i == rows - 1 || 0 == j || j == cols - 1) {
                    visited[i][j] = 1;
                    q.push(make_pair(heightMap[i][j], i * cols + j));
                }
            }
        }
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int maxh = INT_MIN;
        int result = 0;
        while (!q.empty()) {
            auto& p = q.top();
            q.pop();
            int height = p.first;
            int x = p.second / cols;
            int y = p.second % cols;

            maxh = max(height, maxh);
            for(auto& d : dir) {
                int xx = x + d[0];
                int yy = y + d[1];
                if (xx < 0 || xx >= rows || yy < 0 || yy >= cols || visited[xx][yy]) {
                    continue;
                }

                if (heightMap[xx][yy] < maxh) {
                    result += maxh - heightMap[xx][yy];
                }
                visited[xx][yy] = 1;
                q.push(make_pair(heightMap[xx][yy], xx * cols + yy));
            }
        }
        return result;
        
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
