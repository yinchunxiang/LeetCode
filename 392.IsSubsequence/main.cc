/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/22 22:47:45
 * @brief 
 * 
 **/ 


#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
 
class Solution {
    public:
        bool isSubsequence(string s, string t) {
            if (s.empty()) {
                return true;
            }
            unordered_map<char, vector<int>> charIndexMap;
            for (int i = 0; i < t.size(); ++i) {
                charIndexMap[t[i]].push_back(i);
            }

            int n = s.size();
            auto cur_index_vec = charIndexMap[s[n - 1]];
            if (cur_index_vec.empty()) {
                return false;
            }
            int cur_max_index = cur_index_vec[cur_index_vec.size() - 1];

            for (int i = n - 1; i > 0; --i) {
                auto pre_index_vec = charIndexMap[s[i - 1]];
                if (pre_index_vec.empty()) {
                    return false;
                }
                auto it = lower_bound(pre_index_vec.begin(), pre_index_vec.end(), cur_max_index);
                if (it == pre_index_vec.begin()) {
                    return false;
                }
                cur_max_index = *prev(it);
            }
            return true;
        }

};


int main(int argc, char *argv[]) {
    {
        string s = "abc";
        string t = "ahbgdc";
        Solution sol;
        cout << "isSubsequence(" << s << "," << t<<") => ";
        cout << sol.isSubsequence(s, t) << endl;
    }
    {
        string s = "axc";
        string t = "ahbgdc";
        Solution sol;
        cout << "isSubsequence(" << s << "," << t<<") => ";
        cout << sol.isSubsequence(s, t) << endl;

    }
    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
