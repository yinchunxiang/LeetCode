/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/01 22:16:30
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string& s) {
        int count = 0;
        for (auto c : s) {
            if (c != '(' && c != ')') continue;
            if ('(' == c) {
                ++count;
            }
            if (')' == c && count-- <= 0) {
                return false;
            }
        }
        return 0 == count;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<sting> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (isValid(temp)) {
                result.push_back(temp);
                found = true;
            }
            if (found) {
                continue;
            }
            for (int i = 0; i < temp.size(); ++i) {
                if (temp[i] != '(' && temp[i] != ')') continue;
                auto str = temp.substr(0, i - 0) + temp.substr(i + 1);
                auto it = visited.find(str);
                if (visited.end() == it) {
                    q.push(str);
                    visited.insert(str);
                }
            }
        }
        return result;
    }

};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
