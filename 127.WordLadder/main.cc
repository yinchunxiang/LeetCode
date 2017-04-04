/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/03 10:42:57
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> dict(wordList.begin(), wordList.end());
            if (dict.end() == dict.find(endWord)) {
                return 0;
            }
            unordered_set<string> curr_level;
            unordered_set<string> next_level;
            unordered_set<string> used;
            curr_level.insert(beginWord);
            int count = 1;
            while (!curr_level.empty()) {
                // 将当前层加入used，防止指向当前层
                used.insert(curr_level.begin(), curr_level.end());
                // get next level words
                for (const auto &word : curr_level) {
                    // get transformed words
                    for (int i = 0; i < word.size(); ++i) {
                        for (char c = 'a'; c <= 'z'; ++c) {
                            if (c == word[i]) {
                                continue;
                            }
                            string next = word;
                            next[i] = c;
                            if (next == endWord) {
                                return count + 1;
                            }
                            // in dict and not used
                            if (dict.end() != dict.find(next) && used.end() == used.find(next)) {
                                next_level.insert(next);
                            }

                        }

                    }
                }
                count += 1;
                curr_level.clear();
                curr_level.swap(next_level);
            }
            return 0;
                
        }

};












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
