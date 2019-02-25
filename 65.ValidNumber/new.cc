//
// Created by yinchunxiang on 2019-02-24.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  // [-+]?(([0-9]+(.[0-9]*)?)|.[0-9]+)(e[-+]?[0-9]+)?
  bool isNumber(string s) {
    auto is_not_space = [](int ch) {return !std::isspace(ch);};
    // remove left space
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));

    // remote right space
    s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());

    cout << "s => " << s << endl;

    bool has_point = false;
    bool has_e = false;
    bool has_number = false;
    bool has_number_after_e = false;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') { // 数字
        has_number = true;
        if (has_e) {
          has_number_after_e = true;
        }
      } else if ('.' == s[i]) { // 点
        if (has_e || has_point) return false;
        has_point = true;
      } else if ('e' == s[i]) { // e
        if (has_e || !has_number) return false;
        has_e = true;
        has_number_after_e = false;
      } else if ('-' == s[i] || '+' == s[i]) {  // +-
        if (i != 0 && 'e' != s[i - 1]) return false;
      } else {
        return false;
      }
    }
    cout << "has_point: " << has_point << endl;
    cout << "has_e: " << has_e << endl;
    cout << "has_number: " << has_number << endl;
    cout << "has_number_after_e: " << has_number_after_e << endl;

    return has_number && ((has_e && has_number_after_e) || (!has_e && !has_number_after_e));
  }
};

void print(Solution& s, const std::string& input) {
  cout << "input:" << input << " => " << s.isNumber(input) << endl;
}

int main(int argc, const char *argv[]) {
  Solution s;
  print(s, "0");
  print(s, ".1e1");
  print(s, "1.e1");

  return 0;
}

