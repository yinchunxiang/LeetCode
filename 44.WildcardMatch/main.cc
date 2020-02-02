//
// Created by alexkkk on 2020/1/30.
//
#include <string>
#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  bool match(string& s, int i, string& p, int j) {
    dbg(s.substr(i));
    dbg(p.substr(j));
    if (i == s.size() && j == p.size()) return true;
    if (j == p.size()) return false;
    if (i == s.size() && '*' != p[j]) return false;
    if (p[j] == '?') return match(s, i + 1, p, j + 1);
    if (p[j] == '*') {
      // * 匹配 0 - 结束
      while (i <= s.size()) {
        if (match(s, i++, p, j+1)) return true;
      }
    }
    return s[i] == p[j] && match(s, i + 1, p, j + 1);
  }

  bool isMatch(string s, string p) {
    if (s.empty()) return p.empty() || p == "*";
    if (p.empty()) return false;
    return match(s, 0, p, 0);
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  dbg(s.isMatch("aaaaaaaaaaaaaaac", "*aaaaaaaaaaaaaaa*b"));

  return 0;
}