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

int char2int(char c) {
    return c - 'a';
}
 
class Solution {
    public:
        string removeDuplicateLetters(string s) {
            vector<int> counts(26, 0);
            for (auto c : s) {
                counts[char2int(c)] += 1;
            }
            vector<bool> used(26, false);
            string result;
            for (auto c : s) {
                counts[char2int(c)] -= 1;
                if (used[char2int(c)]) {
                    continue;
                }
                while (!result.empty() && c < result.back() && counts[char2int(result.back())]) {
                    used[char2int(result.back())] = false;
                    result.pop_back();
                }
                result.push_back(c);
                used[char2int(c)] = true;
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
