/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/04 16:37:00
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}
 
class Solution {
    public:

        string removeDuplicateLetters(string s) {
            int N = s.size();
            unordered_set<char> next_charset;
            vector<unordered_set<char>> char_set_vec(N, unordered_set<char>());
            unordered_set<char> charset;
            int uniq_char_count = 0;
            for (int i = N - 1; i >= 0; --i) {
                auto charset = next_charset;
                charset.insert(s[i]);
                next_charset = charset;
                char_set_vec[i].swap(charset);
            }

            //cout << "uniq  => ";
            for (int i = 0; i < N; ++i) {
                cout << char_set_vec[i].size() ;
            }
            cout << endl;

            int selected = 0;
            int prev_uniq_counts = char_set_vec[0].size();
            vector<int> v;
            string result;
            unordered_set<char> used;
            for (int begin = 0; begin < N; ) {
                auto end = begin + 1;
                while (end < N && char_set_vec[end].size() == char_set_vec[begin].size()) {
                    ++end;
                }
                //cout << "begin => " << begin << endl;
                //cout << "end => " << end << endl;
                auto selected = N;
                for (int j = begin; j < end; ++j) {
                    auto it = used.find(s[j]);
                    if (used.end() != it) {
                        continue;
                    }
                    if (N == selected) {
                        selected = j;
                        continue;
                    }
                    if (s[j] < s[selected]) {
                        selected = j;
                    }
                }
                //cout  << "selected => " << selected << endl;

                for (int j = selected + 1; j < N; ++j) {
                    char_set_vec[j].erase(s[selected]);
                }
                result.push_back(s[selected]);
                used.insert(s[selected]);
                //cout << "current result => " << result << endl;
                //cout << "----------------------------" << endl;
                begin = selected + 1;

            }
            return result;
        }

};

int main(int argc, char *argv[]) {
    {
        Solution sol;
        string input = "bcabc";
        cout << "input => " << input << endl;
        cout << sol.removeDuplicateLetters(input) << endl;
    }
    {
        Solution sol;
        string input = "cbacdcbc";
        cout << "input => " << input << endl;
        cout << sol.removeDuplicateLetters(input) << endl;


    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
