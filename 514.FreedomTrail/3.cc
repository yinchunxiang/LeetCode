/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 3.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/13 21:14:09
 * @brief 
 * 
 **/ 

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
 
class Solution {
public:
    void dfs(int& minSteps, int steps, string &ring, int i, string &key, int j, unordered_map<char, vector<int> > &charIndexMap) {
        if (steps >= minSteps) {
            return;
        }
        if (j == key.size()) {
            minSteps = steps;
            return;
        }
        for (auto index : charIndexMap[key[j]]) {
            int distance1 = abs(index - i);
            //cout << "distance1: " << distance1 << endl;
            int distance2 = ring.size() - distance1;
            //cout << "distance2: " << distance2 << endl;
            dfs(minSteps, steps + min(distance1, distance2) + 1, ring, index, key, j + 1, charIndexMap);
        }
        return;
    }
    int findRotateSteps(string ring, string key) {
        int size = ring.size();
        unordered_map<char, vector<int> > charIndexMap;
        for (int i = 0; i < ring.size(); ++i) {
            char c = ring[i];
            charIndexMap[c].push_back(i);
        }

        int minSteps = ring.size() * key.size();
        int steps = 0;
        dfs(minSteps, steps, ring, 0, key, 0, charIndexMap);
        cout << "min steps: " << minSteps << endl;
        
    }
};

int main(int argc, char *argv[])
{
    string ring = "godding";
    string key = "gd";
    Solution s; 
    s.findRotateSteps(ring, key);
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
