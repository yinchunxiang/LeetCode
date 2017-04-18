/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/16 15:53:27
 * @brief 
 * 
 **/ 

class Solution {
    public:

        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            int N = s.size();
            vector<bool> dp(N, false);
            for (int i = N - 1; i > 0; --i) {
                string str = s.substr(i);
                if (dict.end() != dict.find(str)) {
                    dp[i][j] = true;
                    continue;
                }
                for (int j = i + 1; j < N; ++j) {
                    if (dp[j]) {
                        string prefix = s.substr(i, j - i);
                        if (dict.end() != dict.find(prefix)) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
            return dp[0];
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
