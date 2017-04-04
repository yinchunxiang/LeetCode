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

        vector<string> expand(const string& word, const string& endWord, const unordered_set<string>& dict,  const unordered_set<string>& used) {
            vector<string> result;
            for (int i = 0; i < word.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (word[i] != c) {
                        string new_word = word.substr(0, i) + c + word.substr(i + 1);
                        auto dit = dict.find(new_word);
                        if (new_word == endWord && dict.end() != dit) {
                            result.push_back(new_word);
                            break;
                        }
                        auto uit = used.find(new_word);
                        if (dict.end() != dit && used.end() == uit) {
                            //used.insert(new_word);
                            result.push_back(new_word);
                        }
                    }
                }
            }
            return result;
        }

        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_map<string, vector<string>> graph;
            unordered_set<string> curr_level;
            unordered_set<string> next_level;
            unordered_set<string> used;
            unordered_set<string> dict(wordList.begin(), wordList.end());
            curr_level.insert(beginWord);
            bool found = false;
            while (!curr_level.empty() && !found) {
                cout << "current level => { ";
                for (auto &word : curr_level) {
                    cout << word << " ";
                }
                cout << "}" << endl;
                // 直接将本层加入used，防止同层的相互指向
                used.insert(curr_level.begin(), curr_level.end());

                //get next level
                for (auto &word : curr_level) {
                    if (word == endWord) {
                        found = true;
                        //graph[word] = vector<string>();
                        break;
                    }
                    auto words = expand(word, endWord, dict, used);
                    graph[word].insert(graph[word].end(), words.begin(), words.end());
                    next_level.insert(words.begin(), words.end());
                }
                if (found) {
                    break;
                }
                curr_level.clear();
                curr_level.swap(next_level);
            }
            for (auto &p : graph) {
                cout << p.first << " => { ";
                for (auto &word : p.second) {
                    cout << word << " ";
                }
                cout << "}" << endl;
            }
            vector<vector<string>> result;
            if (found) {
                vector<string> path;
                dfs(graph, path, result, beginWord, endWord);
            }
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
    {

        string beginWord = "red";
        string endWord = "tax";
        vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
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
