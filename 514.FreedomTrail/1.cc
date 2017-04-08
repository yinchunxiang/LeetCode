/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 23:56:42
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> move(int n, int target, int pos) {
    vector<int> result(2, n);
    if (target > pos) {
        result[1] = target - pos;
        result[0] = n - result[1];
        return result;
    }
    result[0] = pos - target;
    result[1] = n - result[0];
    return result;
}


vector<int> move(int n, int pos, vector<int>& targets) {
    vector<int> result(2, n);
    for (auto target : targets) {
        auto moves = move(n, pos, target);
        result[0] = min(result[0], moves[0]);
        result[1] = min(result[1], moves[1]);
    }
    return result;
}

void dfs(int& min_count, int cur_count, unordered_map<char, vector<int>>& m, const string& key, int index, int n, int curpos) {
    if (index >= key.size()) {
        min_count = min(min_count, cur_count);
        return;
    }
    auto& targets = m[key[index]];
    auto moves = move(n, curpos, targets);
    //left
    dfs(min_count, cur_count + moves[0], m, key, index + 1, n, (n + curpos - moves[0])%n);
    //right
    dfs(min_count, cur_count + moves[1], m, key, index + 1, n, (curpos + moves[1])%n);
}

int findRotateSteps(string ring, string key) {
    unordered_map<char, vector<int>> posmap;
    for (int i = 0; i < ring.size(); ++i) {
        posmap[ring[i]].push_back(i);
    }
    int min_count = INT_MAX;
    dfs(min_count, 0, posmap, key, 0, ring.size(), 0);
    return min_count + key.size();
}


int main(int argc, char *argv[]) {
    cout << findRotateSteps("godding", "gd") << endl;
    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
