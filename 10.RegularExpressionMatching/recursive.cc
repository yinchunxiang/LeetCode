//
// Created by yinchunxiang on 2019-02-24.
//

class Solution {
 public:
  bool match(const std::string& s, int ss, const std::string& p, int ps) {
    if (ss >= s.size() && ps >= p.size()) return true;
    if (ss >= s.size()) {
      if (p.size() < ps + 2) return false;
      return '*' == p[ps + 1]  && match(s, ss, p, ps + 2);
    }
    if (ps >= p.size()) return false;
    // 剩余的模式串的长度 < 2
    if (p.size() < ps + 2) {
      return ('.' == p[ps] || s[ss] == p[ps]) && match(s, ss + 1, p, ps + 1);
    }
    if (p[ps + 1] == '*') {
      // 匹配0个
      if (match(s, ss, p, ps + 2)) return true;
      // 匹配 1- N个
      for (int i = 1; i <= s.size() - ss; ++i) {
        if (s[ss + i - 1] == p[ps] || '.' == p[ps]) {
          if (match(s, ss + i, p, ps + 2)) return true;
          continue;
        }
        return false;
      }
      return false;
    }
    if (p[ps] == '.' || p[ps] == s[ss]) {
      return match(s, ss + 1, p, ps + 1);
    }
    return false;
  }
  bool isMatch(string s, string p) {
    return match(s, 0, p, 0);
  }
};
