/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 4.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/16 18:57:51
 * @brief 
 * 
 **/ 

{

    void dfs(unordered_map<string, unordered_set<string>>& paths, vector<string> path, vector<vector<string>>& result, string& curr, string& endWord) {
        path.push_back(curr);
        if (curr == endWord) {
            result.push_back(path);
            return;
        }
        auto& s = paths[curr];
        if (s.empty()) return;
        for (auto& word : s) {
            dfs(paths, path, result, s, endWord);
        }
        return;
    }

 
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(begin(wordList), end(wordList));
    if (dict.end() == dict.find(endWord)) {
        return {}
    }
    unordered_map<string, unordered_set<string>> paths;
    unordered_set<string> curr_level;
    unordered_set<string> next_level;
    unordered_set<string> used;
    curr_level.insert(beginWord);
    bool found = false;
    while (!curr_level.empty()) {
        used.insert(curr_level.begin(), curr_level.end());
        for (auto word : curr_level) {
            for (int i = 0; i < word.size(); ++i) {
                string next = word;
                for (auto c = 'a'; c <= 'z'; ++c) {
                    next[i] = c;
                    if (used.end() != used.find(next) || dict.end() == dict.find(next)) {
                        continue;
                    }
                    paths[word].insert(next);
                    next_level.insert(next);
                    if (endWord == next) {
                        found = true;
                        break;//位置i其他的变种不需要了
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

    vector<vector<string>> result;
    if (found) {
        dfs(paths, {}, result, beginWord, endWord);
    }
    return result;
    
}

}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
