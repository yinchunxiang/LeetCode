/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 3.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/02 14:50:11
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        void dfs(unordered_map<string, vector<string>>& graph, vector<string> path, vector<vector<string>>& result, string beginWord, string &endWord) {
            path.push_back(beginWord);
            if (beginWord == endWord) {
                result.push_back(path);
                return;
            }
            for (auto &word : graph[beginWord]) {
                dfs(graph, path, result, word, endWord);
            }
            return;
        }

        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            vector<vector<string>> result;
            unordered_map<string, vector<string>> graph;
            unordered_set<string> curr_level;
            unordered_set<string> next_level;
            unordered_set<string> used;
            unordered_set<string> dict(wordList.begin(), wordList.end());
            if (dict.end() == dict.find(endWord)) {
                return result;
            }
            curr_level.insert(beginWord);
            bool found = false;
            while (!curr_level.empty() && !found) {
                used.insert(curr_level.begin(), curr_level.end());
                for (auto word : curr_level) {
                    for (int i = 0; i < word.size(); ++i) {
                        for (char c = 'a'; c <= 'z'; ++c) {
                            if (word[i] == c) {
                                continue;
                            }
                            string next = word;
                            next[i] = c;
                            if (next == endWord) {
                                found = true;
                                next_level.insert(next);
                                graph[word].push_back(next);
                                break;
                            }
                            if (dict.find(next) != dict.end() && used.find(next) == used.end()) {
                                next_level.insert(next);
                                graph[word].push_back(next);
                            }
                        }
                    }

                }
                if (found) {
                    break;
                }
                curr_level.clear();
                curr_level.swap(next_level);
            }
            
            if (found) {
                vector<string> path;
                dfs(graph, path, result, beginWord, endWord);
            }
            return result;
        }

};












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
