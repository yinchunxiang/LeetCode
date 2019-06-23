#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) {
            return gcd(str2, str1);
        }
        return gcd(str1, str2);
    }

    bool Dividable(const string& s, int d) {
      if (d > s.size()) return false;
      if (d == s.size()) return true;
      if (0 != s.size() % d) return false;

      for (int i = 1; i * d < s.size(); ++i) {
        for (int j = 0; j < d; ++j) {
          if (s[j] != s[i * d + j]) {
            return false;
          }
        }
      }
      return true;
    }

  string gcd(const string& l, const string& r) {
    cout << "gcd start ..." << endl;
    cout << "l size: " << l.size() << endl;
    cout << "r size: " << r.size() << endl;
    if (r.size() == l.size()) {
      cout << "size equal ..." << endl;
      return l == r ? l : "";
    }
    for (int d = 2; d <= r.size(); ++d) {
      cout << "d: " << d << endl;
      if (!Dividable(r, d)) continue;
      cout << r << " is dividable by " << d << endl;
      if (0 != strncmp(l.c_str(), r.c_str(), d)) continue;
      if (!Dividable(l, d)) continue;
      cout << l << " is dividable by " << d << endl;
      return l.substr(0, d);
    }
    return "";
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  {
    string s = "ABC";
    cout << s << " is dividable: " << solution.Dividable(s, 3) << endl;
  }
  {
    string s = "ABCABC";
    cout << s << " is dividable: " << solution.Dividable(s, 3) << endl;
  }
  {

    string l = "ABC";
    string r = "ABCABC";
    cout << solution.gcdOfStrings(l, r) << endl;
  }

  return 0;
}
