/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/05 21:53:35
 * @brief 
 * 
 **/ 

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
 
class Solution {
    public:
        void dfs(vector<string>& result, string curr, unordered_set<string>& dict, int maxlen, int level) {
            if (level >= 2 && dict.end() != dict.find(curr)) {
                result.push_back(curr);
            }
            if (level >= dict.size()) {
                return;
            }
            for (auto word : dict) {
                if (word.size() >= maxlen) {
                    continue;
                }
                if (curr.size() + word.size() > maxlen) {
                    continue;
                }
                dfs(result, curr + word, dict, maxlen, level + 1);
            }
            return;

        }
        vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
            int maxlen = 0;
            for (auto& word : words) {
                maxlen = std::max(maxlen, (int)word.size());
            }
            unordered_set<string> dict(words.begin(), words.end());
            vector<string> result;
            dfs(result, "", dict, maxlen, 0);
            return result;
        }

};

void printv(const std::vector<string> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}


int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<string> words{"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
        auto v = s.findAllConcatenatedWordsInADict(words);
        printv(v);
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
