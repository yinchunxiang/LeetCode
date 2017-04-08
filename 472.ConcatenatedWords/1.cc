/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/06 17:47:11
 * @brief 
 * 
 **/ 

#include <unordered_set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(unordered_set<string>& prewords, string& word) {
    if (prewords.empty()) return false;
    int N = word.size();
    vector<bool> dp(N + 1, false);
    // 表示word的前i个字符能不能被prewords构成
    dp[0] = true;
    for (int i = 1; i <= word.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (!dp[j]) continue;
            if (prewords.find(word.substr(j, i - j)) != prewords.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[N];

}
 
vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    sort(begin(words), end(words), [](const string& lhs, const string& rhs){return lhs.size() < rhs.size();});
    unordered_set<string> prewords;
    vector<string> result;
    for (auto word : words) {
        if (dfs(prewords, word)) {
            result.push_back(word);
        }
        prewords.insert(word);
    }
    return result;
    
}

void printv(const std::vector<string> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    auto v = findAllConcatenatedWordsInADict(words);
    printv(v);
    
    return 0;
}









/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
