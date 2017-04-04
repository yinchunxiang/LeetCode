/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/02 11:05:09
 * @brief 
 * 
 **/ 
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
 
class Solution {
    bool transformable(string& l, string& r) {
        int N = l.size();
        int diff = 0;
        for (int i = 0; i < N; ++i) {
            if (l[i] != r[i]) {
                if (++diff > 1) {
                    return false;
                }
            }
        }
        return 1 == diff;
    }

    void dfs(unordered_map<string, unordered_set<string>>&graph, unordered_set<string> used, vector<string> path, vector<vector<string>>& result, string curr, string& endWord) {
        auto it = used.find(curr);
        if (used.end() != it) {
            return;
        }
        path.push_back(curr);
        used.insert(curr);
        if (curr == endWord) {
            if (result.empty()) {
                result.push_back(path);
                return;
            } 
            int prev_size = result.back().size();
            if (path.size() > prev_size) {
                return;
            }
            if (path.size() < prev_size) {
                result.clear();
            }
            result.push_back(path);
            return;
        }
        if (!result.empty() && path.size() >= result.back().size()) {
            return;
        }
        cout << curr << " => { "; 
        for (auto &target : graph[curr]) {
            cout << target << " ";
        }
        cout << "}" << endl;
        cout << "----------------------------" << endl;
            
        for (auto &target : graph[curr]) {
            dfs(graph, used, path, result, target, endWord);
        }

    }
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            vector<vector<string>> result;
            if (wordList.empty()) {
                return result;
            }
            unordered_map<string, unordered_set<string>> graph;
            for (auto &word : wordList) {
                if (transformable(beginWord, word)) {
                    cout << "beginWord => " << beginWord << "  word => " << word << endl;
                    graph[beginWord].insert(word);
                }
            }
            int N = wordList.size();
            for (int i = 0; i < N - 1; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    if (transformable(wordList[i], wordList[j])) {
                        cout << wordList[i] << " " << wordList[j] << endl;
                        graph[wordList[i]].insert(wordList[j]);
                        graph[wordList[j]].insert(wordList[i]);
                    }
                }
            }

            unordered_set<string> used;
            vector<string> path;
            dfs(graph, used, path, result, beginWord, endWord);
            return result;
        }
};


int main(int argc, char *argv[]) {
    Solution s;
    {
        string beginWord = "hit";
        string endWord = "cog";
        vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
        auto result = s.findLadders(beginWord, endWord, wordList);
        cout << "{" << endl;
        for (auto &v : result) {
            cout << "{ ";
            for (auto &str : v) {
                cout << str << " ";
            }
            cout << "}" << endl;
        }
        cout << "}" << endl;
            
    }
    {

        string beginWord = "a";
        string endWord = "c";
        vector<string> wordList = {"a", "b", "c"};
        auto result = s.findLadders(beginWord, endWord, wordList);
        cout << "{" << endl;
        for (auto &v : result) {
            cout << "{ ";
            for (auto &str : v) {
                cout << str << " ";
            }
            cout << "}" << endl;
        }
        cout << "}" << endl;
    }
    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
