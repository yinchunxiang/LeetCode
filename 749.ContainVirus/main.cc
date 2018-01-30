/****************************************************************************
 * 
 * Copyright (C) 2018 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2018/01/30 16:57:20
 * @brief 
 * 
 **/

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
private:
    size_t rows_;
    size_t cols_;

public:
    void update(vector<vector<int>>& grid, const unordered_set<int>& extend, int value) {
        for (auto coodinate : extend) {
            auto x = coodinate / cols_;
            auto y = coodinate % cols_;
            grid[x][y] = value;
        }
    }

    int containVirus(vector<vector<int>>& grid) {
        auto rows = grid.size();
        if (rows <= 0) return 0;
        auto cols = grid[0].size();
        rows_ = rows;
        cols_ = cols;
        int totalWalls = 0;
        while(true) {
            vector<vector<int>> visited(rows_, vector<int>(cols_, 0));
            vector<unordered_set<int>> extends ;
            vector<unordered_set<int>> blocks ;
            size_t maxExtendCount = 0;
            int currWalls = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (visited[i][j]) continue;
                    int walls = 0;
                    unordered_set<int> extend;
                    unordered_set<int> block;
                    getArea(i, j, grid, walls, block, extend, visited);
                    if (extend.size() > maxExtendCount) {
                        maxExtendCount = extend.size();
                        currWalls = walls;
                    }
                    extends.push_back(extend);
                    blocks.push_back(block);
                }
            }
            if (0 == currWalls) break;
            totalWalls += currWalls;

            for (int i = 0; i < extends.size(); ++i) {
                const auto& extend = extends[i];
                if (maxExtendCount != extend.size()) {
                    update(grid, extend, 1);
                } else {
                    update(grid, blocks[i], 2);
                }
            }
        }
        return totalWalls;
    }

    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


    void getArea(int x, int y, vector<vector<int>>& grid, int& wall, unordered_set<int>& block,
                 unordered_set<int>& extend, vector<vector<int>>& visited) {

        if (visited[x][y]) return;
        visited[x][y] = 1;
        if (1 != grid[x][y]) return;
        block.emplace(x * cols_ + y);
        for (auto& d : dirs) {
            int xx = x + d.first;
            int yy = y + d.second;
            if (xx < 0 || xx >= rows_ || yy < 0 || yy >= cols_) continue;
            if (0 == grid[xx][yy]) {
                cout << x << ", " << y << endl;
                wall += 1;
                extend.emplace(xx * cols_ + yy);
            }
            getArea(xx, yy, grid, wall, block, extend, visited);
        }
    }

};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<vector<int>> grid = {
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1}
        };
        cout << s.containVirus(grid) << endl;
    }
    {
        vector<vector<int>> grid = {
                {0,1,0,0,0,0,0,1},
                {0,1,0,0,0,0,0,1},
                {0,0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0,0}
        };
        cout << s.containVirus(grid) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
