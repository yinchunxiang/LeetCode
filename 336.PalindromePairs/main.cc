//
// Created by yinchunxiang on 2019-03-24.
//

bool isPalindrome(striing& s) {
  int l = 0;
  int r = s.size() - 1;
  while (l < r) {
    if (s[l++] != s[r--]) return false;
  }
  return true;
}


vector<vector<int>> palindromePairs(vector<string>& words) {
  vector<vector<int>> ans;
  int n = words.size();
  if (n < 2) return ans;
  unordered_map<string, int> m;
  for (int i = 0; i < n; ++i) {
    auto s = words[i];
    reverse(s.begin(), s.end());
    m[s] = i;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < words[i].size(); ++j) {
      string st1 = words[i].substr(0, j);
      string st2 = words[i].substr(j);

      // st2 是回文， 则找st1的翻转之后的是否存在, st1 为empty的情况在这处理了
      if (m.count(st1) && isPalindrome(st2) && m[st1] != i) {
        ans.push_back({i, m[st1]});
        // 空字符也在 words里面的时候
        if (st1.empty()) ans.push_back({m[st1], i});
      }

      // st1 是回文， 则找st1的翻转之后的是否存在
//      if (!st1.empty() && isPalindrome(st1) && m.count(st2) && m[st2] != i) {
      if (isPalindrome(st1) && m.count(st2) && m[st2] != i) {
        ans.push_back({m[st2], i});
      }
    }
  }
  return ans;
}