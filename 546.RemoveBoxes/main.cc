/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 23:21:33
 * @brief 
 * 
 **/ 

int dfs(vector<int>& boxes, int memo[100][100][100], int l, int r, int k) {
    if (l > r) return 0;
    if (!memo[l][r][k]) {
        return memo[l][r][k];
    }
    for (;r > l && boxes[r] == boxes[r - 1];--r, ++k);
    //base
    memo[l][r][k] = dfs(boxes, memo, l, r - 1, 0) + (k + 1) * (k + 1);
    for (int i = l; i < r; ++i) {
        memo[l][r][k] = max(memo[l][r][k], dfs(boxes, memo, l, i, k + 1) + dfs(boxes, memo, i + 1, r - 1, 0);
    }
    return memo[l][r][k];
}
 
int removeBoxes(vector<int>& boxes) {
    int memo[100][100][100] = {0};
    return dfs(boxes, memo, 0, boxes.size() - 1, 0);
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
