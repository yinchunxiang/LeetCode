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

        // pair第一个元素代表单元格的高度，第二个元素代表是第几个单元格，真正存入的是i * cols + j
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        int rows = heightMap.size();
        int cols = heightMap[0].size();

        //表示单元格是否被访问过
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));

        //设置最外围的格子已经被访问过，因为他们无法存放水
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
            auto val = q.top(); 
            q.pop();
            auto height = val.first;
            auto x = val.second / cols;
            auto y = val.second % cols;
            // 更新当前整个外围最低的格子的高度
            maxh = max(maxh, height);
            for (auto &p : xy) {
                auto xx = x + p[0];
                auto yy = y + p[1];
                // 判断格子是否合法
                if (xx < 0 || xx >= rows || yy < 0 || yy >= cols || visited[xx][yy]) {
                    continue;
                }
                visited[xx][yy] = 1;
                
                // 还有格子被抱在中间，与那个外围最低的格子相邻，则装的水就可以计算出来
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
