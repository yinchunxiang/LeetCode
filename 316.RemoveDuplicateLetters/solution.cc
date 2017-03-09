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
            if (N <= 0) return "";
            vector<int> counts(N + 1, 0);
            //unordered_map<char, int> charset;
            vector<int> charset(26, 0);
            int uniq_char_count = 0;
            for (int i = N - 1; i >= 0; --i) {
                int &temp = charset[s[i] - 'a'];
                if (0 == temp) {
                    uniq_char_count += 1;
                } 
                temp += 1;
                counts[i] = uniq_char_count;
            }
            printv(counts);
            int prev_uniq_counts = uniq_char_count;
            vector<int> v(N, 0);
            vector<int> used(26, 0);
            int top = 0;
            for (int i = 1; i < N; ++i) {
                if (counts[i] != counts[v[top]] && 1 == charset[s[i] - 'a']) {
                    top += 1;
                    v[top] = i;
                    charset[s[i]] -= 1;
                    continue;
                }
                while (top >= 0 && counts[i] == counts[v[top]] && s[i] < s[v[top]]) {
                    //charset[s[v[top]]] += 1;
                    top -= 1;
                }
                top += 1;
                v[top] = i;
                charset[s[i]] -= 1;
                continue;

                if (1 == charset[s[i]]) {
                    top += 1;
                    v[top] = i;
                }

            }
            string result = "";
            for (int i = 0; i <= top; ++i) {
                result += s[v[i]];
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
