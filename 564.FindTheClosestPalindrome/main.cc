//
// Created by yinchunxiang on 2019-03-24.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string mirror(const string& s) {
  auto half = (s.size() + 1) / 2;
  auto left = s.substr(0, half);
  auto rleft = string(s.rbegin() + half, s.rend());
  return left + rleft;
}

string nearestPalindromeic(string s) {
  int n = s.size();
  auto num = stol(s);
  vector<string> vc {
    mirror(s),
    mirror( to_string(num - long(pow(10, n/2)))),
    mirror( to_string(num + long(pow(10, n/2)))),
    to_string(long(pow(10, n)) + 1),
    to_string(long(pow(10, n)) - 1)
  };
  // 删除和原始串相同的
  vc.erase(vc.remove(begin(vc), end(vc), s), vc.end());
  auto cmp = [&s](const string& a, const string& b) {
    auto l = abs(stol(a) - num);
    auto r = abs(stol(b) - num);
    if (l == r) {
      return stol(a) < stol(b);
    }
    return l < r;
  };
  auto it = min_element(begin(vc), end(vc), cmp);
  return *it;
}


int main(int argc, const char *argv[]) {
  string s = "abcde";
  cout << string(s.rbegin() + (s.size() + 1)/ 2, s.rend()) << endl;
  return 0;
}
