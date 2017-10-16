/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/10/16 17:01:43
 * @brief 
 * 
 **/

#include <string>

#include <vector>
#include <unordered_map>

using namespace std;
 

class Solution {
    public:
        int minStickers(vector<string>& stickers, string target) {
            // 计算每个sticker中字母出现的次数
            int m = stickers.size();
            vector<vector<int>> mp(m, vector<int>(26, 0));
            for (int i = 0; i < m; ++i) {
                for (char c: stickers[i]) {
                    mp[i][c - 'a'] ++;
                }
            }
            unordered_map<string, int> dp;
            dp[""] = 0;
            return helper(dp, mp, target);
        }

    private:
        int helper(unordered_map<string, int>& dp, vector<vector<int>> &mp, string target) {
            auto it = dp.find(target);
            if (dp.end() != it) {
                return it->second;
            }

            int ans = INT_MAX;
            int n = mp.size();
            vector<int> tar(26, 0);
            for (char c : target) tar[c - 'a'] ++;
            for (int i = 0; i < mp.size(); ++i) {
                //优化
                if (0 == mp[i][target[0] - 'a']) continue;
                // 用来存放减去sticker之后的字符串
                string s;
                for (int j = 0; j < 26; ++j) {
                    if (tar[j] - mp[i][j] > 0) {
                        s += string(tar[j] - mp[i][j], 'a' + j);
                    }
                }
                int tmp = helper(dp, mp, s);
                if (-1 == tmp) continue;
                ans = min(ans, 1 + tmp);
            }
            dp[target] = ans == INT_MAX ? -1 : ans;
            return dp[target];
        }
};

int main(int argc, char *argv[]) {
    return 0;
}















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
