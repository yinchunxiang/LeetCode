//
// Created by alexkkk on 2019-02-15.
//

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int minl = s.size() + 1;
    int maxl = 0;
    for (const auto& word : wordDict) {
      int n = word.size();
      minl = min(minl, n);
      maxl = max(maxl, n);
    }
    if (minl > s.size()) return false;
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      if (i < minl) {
        dp[i] = false;
        continue;
      }
      for (int j = minl; j <= maxl; ++j) {
        int start = i - j;
        if (start < 0) break;
        std::string word = s.substr(start, j);
        cout << "word: " << word << endl;
        auto it = dict.find(word);
        if (it != dict.end()) {
          dp[i] = dp[i - j];
          if (dp[i]) break;
        }
      }
      cout << "dp[" << i << "]:" << dp[i] << endl << endl;;
    }
    return dp[s.size()];
  }
};
