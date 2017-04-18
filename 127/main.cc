/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/16 00:58:32
 * @brief 
 * 
 **/ 

 
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.end() == dict.find(endWord)) {
        return 0;
    }
    unordered_set<string> curr_level;
    unordered_set<string> next_level;
    unordered_set<string> used;
    curr_level.push(beginWord);
    int level = 0;
    while (!curr_level.empty()) {
        // 防止指向当前层
        used.insert(curr_level.begin(), curr_level.end());
        for (auto word : curr_level) {
            for (int i = 0; i < word.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    string next = word;
                    next[i] = c;
                    if (next == endWord) {
                        return level + 2;
                    }
                    if (used.end() != used.find(next) || dict.end() == dict.find(next)) {
                        continue;
                    }
                    next_level.insert(next);
                }
            }
        }
        curr_level.clear();
        curr_level.swap(next_level);
        ++level;
    }
    return 0;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
